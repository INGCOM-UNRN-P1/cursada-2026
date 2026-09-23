# Diagnóstico con `nostromo`, `hal` y `vasquez`

Ejemplos pensados para ejecutarse **bajo las herramientas**, no a mano. Los
comandos se escriben desde la raíz de `ejemplos/`. `hal` y `vasquez` aceptan
directamente el `.c` y lo compilan con información de depuración; `nostromo`
necesita el binario ya compilado.

- **`nostromo`** ejecuta el binario en un sandbox (Bubblewrap) con límite de
  tiempo y de memoria, y clasifica el resultado: `SEGFAULT`, `FPE`, `TIMEOUT`,
  `NON_ZERO` o correcto. Es el primer paso con cualquier contraejemplo.
- **`hal`** ejecuta el programa bajo GDB y, si se cae (`SIGSEGV`, `SIGABRT`,
  `SIGFPE`), explica la causa, la línea, los argumentos y la pila de llamadas.
- **`vasquez`** intercepta `malloc`/`calloc`/`realloc` con `LD_PRELOAD`, sin
  recompilar, para forzar fallos y recorrer los caminos de error que en una
  ejecución normal nunca se ejecutan.

| Archivo | Herramienta | Qué muestra |
| --- | --- | --- |
| `01_desreferencia_nula.c` | `nostromo` + `hal` | `SIGSEGV` por escribir a través de `NULL`. |
| `02_indice_fuera_de_rango.c` | `nostromo` + `hal` | Caída por recorrer más allá del bloque reservado. |
| `03_malloc_sin_verificar.c` | `nostromo` + `vasquez` | Falta el control de `NULL`: solo falla cuando `malloc` falla. |
| `04_malloc_verificado.c` | `vasquez` | La versión correcta de `03`: termina con `EXIT_FAILURE`. |
| `05_fuga_en_camino_de_error.c` | `vasquez` | Fuga que existe solo en la rama de error. |
| `06_realloc_sin_temporal.c` | `nostromo` + `vasquez` | `p = realloc(p, ...)` pierde el bloque y se cae. |
| `07_lectura_sin_inicializar.c` | `vasquez` | Memoria envenenada con `0xA5` delata la lectura sin inicializar. |
| `08_cascada_de_reservas.c` | `vasquez` | Lista con cleanup correcto: pasa todos los escenarios. |
| `09_reintento_sin_fin.c` | `nostromo` + `vasquez` | Reintentar `malloc` en un lazo: cuelgue en lugar de caída. |
| `10_crecimiento_sin_limite.c` | `nostromo` | Vector que crece sin fin: solo se puede ejecutar con límite de memoria. |

## Primero, `nostromo`

Un contraejemplo puede caerse, colgarse o consumir toda la memoria. Antes de
usar cualquier otra herramienta, ejecutarlo en el sandbox para saber **qué
clase de fallo** tiene:

```sh
gcc -std=c11 -g memoria_dinamica/diagnostico/01_desreferencia_nula.c -o /tmp/nula
nostromo run /tmp/nula                         # SEGFAULT
```

Según lo que informe `nostromo`, se elige la herramienta siguiente:

| Resultado de `nostromo` | Qué significa | Siguiente paso |
| --- | --- | --- |
| `SEGFAULT`, `FPE`, `ABORT` | El programa recibió una señal. | `hal check` para explicar la causa. |
| `TIMEOUT` | El programa no termina. | Leer el código. **No usar `hal`**: se queda esperando a GDB. |
| `NON_ZERO` | Terminó con código de error. | Revisar `stderr` y el camino de error. |
| Correcto | El camino feliz funciona. | `vasquez` para probar los caminos de error. |

`nostromo run` acepta `--timeout` (segundos, por defecto 2) y `--memory`
(MB, por defecto 128). Ni `hal` ni `vasquez` limitan la memoria.

## `hal`: explicar una caída

```sh
hal check memoria_dinamica/diagnostico/01_desreferencia_nula.c
hal check memoria_dinamica/diagnostico/02_indice_fuera_de_rango.c
```

En `01`, `hal` identifica una *NULL pointer dereference* en la línea 16,
dentro de `cargar`, con `destino=0x0`. En `02` muestra que `sumar` recibió
`cantidad=400000000` para un bloque de 4 enteros.

Otras opciones útiles: `--advice` (consejos defensivos), `--md reporte.md`
(reporte en Markdown) y `hal advice`.

## `vasquez`: forzar los caminos de error

```sh
# El camino feliz funciona: el error está latente.
gcc -std=c11 -g memoria_dinamica/diagnostico/03_malloc_sin_verificar.c -o /tmp/sin_verificar
nostromo run /tmp/sin_verificar                # 16

# Un fallo en la N-ésima llamada.
vasquez inject memoria_dinamica/diagnostico/03_malloc_sin_verificar.c --fail-malloc-at 1
vasquez inject memoria_dinamica/diagnostico/04_malloc_verificado.c --fail-malloc-at 1

# Fugas en la rama de error.
vasquez inject memoria_dinamica/diagnostico/05_fuga_en_camino_de_error.c --fail-malloc-at 2 --check-leaks
vasquez inject memoria_dinamica/diagnostico/06_realloc_sin_temporal.c --fail-realloc-at 1 --check-leaks

# Memoria sin inicializar (ver el campo "stdout" del JSON).
vasquez inject memoria_dinamica/diagnostico/07_lectura_sin_inicializar.c --garbage-memory --json

# Todos los caminos: en cascada y de forma probabilística.
vasquez inject memoria_dinamica/diagnostico/08_cascada_de_reservas.c --fail-malloc-at 2 --cascade --check-leaks
vasquez stress memoria_dinamica/diagnostico/08_cascada_de_reservas.c -n 20 -p 0.3

# Un fallo aislado se "arregla" reintentando; una cascada no.
vasquez inject memoria_dinamica/diagnostico/09_reintento_sin_fin.c --fail-malloc-at 1
vasquez inject memoria_dinamica/diagnostico/09_reintento_sin_fin.c --fail-malloc-at 1 --cascade
```

Resultados esperados:

| Archivo | Resultado de `vasquez` |
| --- | --- |
| `03` | `CRASH ✗` — `SIGSEGV` por desreferenciar el `NULL` devuelto. |
| `04` | `MANEJADO ✓` — `Exit: 1`. |
| `05` | `MANEJADO ✓`, con advertencia de 1 reserva sin liberar en la rama de error. |
| `06` | `CRASH ✗`, con advertencia de 1 reserva sin liberar. |
| `07` | `MANEJADO ✓` (no hay caída), pero `stdout` es `-1515870810` = `0xA5A5A5A5 + 1`. |
| `08` | `MANEJADO ✓` en cualquier escenario; `stress` 20/20 sin caídas. |
| `09` | `MANEJADO ✓` con un fallo; `INFINITE_LOOP` (timeout de 3 s) con `--cascade`. |

`07` muestra una limitación: `vasquez` evalúa si el programa **se cae**, no si
el resultado es correcto. El valor basura hay que buscarlo en la salida. `09`
muestra otra: un único fallo no alcanza para descubrir un reintento sin fin.

## `nostromo`: consumo de memoria sin límite

```sh
gcc -std=c11 -g memoria_dinamica/diagnostico/10_crecimiento_sin_limite.c -o /tmp/crecimiento
nostromo run /tmp/crecimiento --memory 32      # NON_ZERO: "sin memoria con 4194304 elementos"
```

`10` no tiene errores de manejo de memoria: verifica cada `realloc`. El error
es la condición del lazo, que nunca se cumple. Dentro del sandbox, `realloc`
devuelve `NULL` al llegar a 32 MB y el programa termina de forma controlada.
Fuera del sandbox, o con `hal` o `vasquez`, consumiría la memoria de la
máquina.

## `hal` y `vasquez` juntos: no por ahora

`hal check` tiene opciones de inyección (`--fail-malloc-at`,
`--inject-vasquez`, ...), pero en `hal` 0.1.0 la librería de `vasquez` se
carga también dentro de GDB y el propio `hal` consume memoria sin límite
(más de 12 GB con `03`). Hasta que se corrija, usarlas por separado:
`vasquez` para provocar el fallo y ver que se cae, y `hal` sin inyección para
explicar las caídas del camino normal.
