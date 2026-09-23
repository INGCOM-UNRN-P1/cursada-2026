# Layout de memoria y stack frames

Ejemplos independientes sobre la organización de la memoria de un proceso en
C: segmentos (datos, bss, heap, pila) y la mecánica de los marcos de pila
(*stack frames*) durante llamadas a funciones y recursión.

Cada archivo tiene su propio `main` y puede compilarse por separado con C99.
Las direcciones impresas son ilustrativas: el orden exacto de los segmentos y
los valores concretos dependen del sistema operativo, el compilador y las
opciones de enlazado; el estándar de C no los garantiza.

## Categorías

| Directorio | Tema |
| --- | --- |
| `segmentos/` | Dónde vive cada tipo de variable: datos, bss, heap y pila. |
| `stack_frames/` | Creación, anidamiento y destrucción de marcos de pila. |
| `contraejemplos/` | Suposiciones inválidas sobre direcciones, recursión sin límite y caso base inalcanzable. |

## Recorrido sugerido

1. `segmentos/01_datos_inicializados.c`
2. `segmentos/02_datos_no_inicializados_bss.c`
3. `segmentos/03_pila_variables_locales.c`
4. `segmentos/04_heap_dinamico.c`
5. `segmentos/05_mapa_de_direcciones.c`
6. `stack_frames/01_marco_simple.c`
7. `stack_frames/02_llamadas_anidadas.c`
8. `stack_frames/03_recursion_y_crecimiento.c`
9. `stack_frames/04_parametros_copiados_por_valor.c`
10. `stack_frames/05_variables_locales_no_sobreviven.c`

Casos relacionados en otros directorios:

- `../punteros/colgantes/01_retorno_de_variable_local.c` muestra el peligro
  de devolver la dirección de una variable de un marco ya destruido.
- `../memoria_dinamica/fundamentos/02_arreglo_malloc.c` contrasta el heap
  con la pila para el mismo tipo de datos.

Los archivos de `contraejemplos/` están destinados a inspección y
diagnóstico. Compilan, pero **no deben ejecutarse directamente**: contienen
comportamiento indefinido o provocan un desbordamiento de pila intencional.
Para verlos fallar, ejecutarlos dentro de `nostromo`, que corta la ejecución
por tiempo y memoria:

```sh
gcc -std=c11 -g contraejemplos/03_caso_base_inalcanzable.c -o /tmp/factorial
nostromo run /tmp/factorial 5        # 120
nostromo run /tmp/factorial 0        # SEGFAULT: la pila se agotó
```

`hal` no sirve para los desbordes de pila: con cientos de miles de marcos,
GDB supera su tiempo límite.

## Compilación

```sh
gcc -std=c99 -Wall -Wextra -pedantic segmentos/01_datos_inicializados.c -o /tmp/layout
```

Para observar el límite real de la pila del sistema:

```sh
ulimit -s
```
