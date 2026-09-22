# Ejemplos — Programación 1 (cursada 2026)

Ejemplos independientes en C para trabajar en clase. Cada directorio tiene su
propio `README.md` con el recorrido sugerido.

| Directorio          | Tema                                                                                         |
| ------------------- | -------------------------------------------------------------------------------------------- |
| `aritmetica/`       | Desbordes, punto flotante, división y precedencia (`ejemplos/` seguros y `contraejemplos/`). |
| `control/`          | Condicionales, lazos y saltos.                                                               |
| `arreglos/`         | Arreglos estáticos, cadenas y `ctype.h`.                                                     |
| `punteros/`         | Punteros sin memoria dinámica.                                                               |
| `layout/`           | Segmentos de memoria y marcos de pila.                                                       |
| `memoria_dinamica/` | `malloc`, `realloc`, `free` y estructuras dinámicas.                                         |
| `directos/`         | Programas cortos hechos en clase.                                                            |
| `ejercicios/`       | Ejercicios de aritmética y control, con `SOLUCIONES.md`.                                     |

Los archivos marcados como contraejemplos (por ejemplo `punteros/salvajes/` o
`punteros/colgantes/`) compilan a propósito, pero contienen comportamiento
indefinido: sirven para analizarlos con las herramientas de diagnóstico, no para
ejecutarlos "a ciegas".

---

## Herramientas de desarrollo y diagnóstico

La cátedra mantiene un ecosistema de herramientas de línea de comandos para
compilar, revisar y diagnosticar código C. La documentación completa está en el
manual del ecosistema (`apunte/manual/`, secciones _2. Desarrollo_ y _3.
Diagnóstico_). Este resumen cubre lo necesario para usarlas con estos ejemplos.

### 1. Dependencias del sistema

Instalá primero el toolchain nativo según tu sistema:

```bash
# Fedora / RHEL
sudo dnf install -y gcc gcc-c++ gdb valgrind clang-tools-extra bubblewrap \
    graphviz python3-pip

# Ubuntu / Debian (también WSL2)
sudo apt update && sudo apt install -y build-essential gcc gdb valgrind \
    clang-format libclang-dev bubblewrap graphviz python3-pip python3-venv

# Arch Linux / Manjaro
sudo pacman -S --needed base-devel gcc gdb valgrind clang bubblewrap \
    graphviz python-pip uv

# macOS (Homebrew)
brew install gcc gdb clang-format graphviz uv
```

Las herramientas se instalan con [`uv`](https://docs.astral.sh/uv/). Si no lo
tenés:

```bash
curl -LsSf https://astral.sh/uv/install.sh | sh
```

En Windows, la opción recomendada es utilizar el
[INGCOM-UNRN-P1/entorno](https://github.com/INGCOM-UNRN-P1/entorno) que contiene
las herramientas base.

### 2. Instalación de las herramientas

**Opción recomendada — todo el ecosistema.** Desde el repositorio central
[`toolbox`](https://github.com/INGCOM-UNRN-P1/toolbox):

```bash
git clone https://github.com/INGCOM-UNRN-P1/toolbox.git p1-tools
cd p1-tools
./scripts/clone_repos.sh        # clona (o actualiza) todos los repos de herramientas
source ./scripts/install_tools.sh   # instala cada CLI con uv y carga el autocompletado
./scripts/health_check.sh       # verifica el entorno completo
```

`install_tools.sh` acepta `--pip` para instalar dentro del venv activo en lugar
de usar `uv tool`, y `--target DIR` si los repositorios están en otro
directorio. Usar `source` en lugar de `./` deja el autocompletado activo en la
terminal actual.

**Opción individual — una sola herramienta.** Dentro del repositorio de la
herramienta (por ejemplo `https://github.com/INGCOM-UNRN-P1/hal`):

```bash
uv tool install git+https://github.com/INGCOM-UNRN-P1/hal
```

Autocompletado para Bash, Zsh o Fish:

```bash
<herramienta> --install-completion
```

### 3. Verificar el entorno con `doctor`

Todas las herramientas tienen el subcomando `doctor`, que revisa compilador,
GDB, límites de core dump, Valgrind, sanitizers, `clang-format`, Bubblewrap, y
Graphviz según lo que necesite cada una:

```bash
ripley doctor
hal doctor
```

| Alerta de `doctor`             | Causa                        | Solución                                          |
| ------------------------------ | ---------------------------- | ------------------------------------------------- |
| `gcc / clang no encontrado`    | Falta el toolchain C         | Instalá `build-essential` / `base-devel` / `gcc`. |
| `bwrap permisos insuficientes` | User namespaces desactivados | `sudo sysctl kernel.unprivileged_userns_clone=1`  |
| `gdb no responde`              | GDB sin soporte MI/Python    | Reinstalá el paquete `gdb` completo.              |

Para que `hal` pueda analizar core dumps, habilitalos en la sesión:

```bash
ulimit -c unlimited
```

---

## Herramientas de desarrollo

Uso cotidiano mientras se escribe el código. Casi todos los comandos aceptan
`--json` (salida estructurada) o `--md` (reporte en Markdown).

### `daedalus` — compilación pedagógica

Compila con los flags de cátedra (`-std=c11 -Wall -Wextra -Werror -pedantic`) y
traduce los errores de GCC/Clang/ld a español.

| Comando                                      | Qué hace                                           |
| -------------------------------------------- | -------------------------------------------------- |
| `daedalus compile src/*.c -o ./bin/programa` | Compila con flags estrictos y explica los errores. |
| `daedalus explain "<mensaje de error>"`      | Explica un error o advertencia del compilador.     |
| `daedalus suggest-flags`                     | Sugiere flags defensivos para el estándar fijado.  |

### `gaff` — estilo y convenciones

Formato Allman, `snake_case`, espaciado de palabras clave, guardas de inclusión,
ausencia de globales.

| Comando                       | Qué hace                                         |
| ----------------------------- | ------------------------------------------------ |
| `gaff check src/ include/ -r` | Audita las reglas de estilo (recursivo).         |
| `gaff fix src/ include/ -r`   | Corrige automáticamente las reglas autofixables. |
| `gaff fix --interactive src/` | Muestra el diff antes de aplicar.                |
| `gaff rules`                  | Lista las reglas con sus alias `0xXXXXh`.        |
| `gaff init-config`            | Genera el `.clang-format` institucional.         |

### `spunkmeyer` — antipatrones didácticos

Detecta casteos de `malloc`, `while (!feof(f))`, `if (cond == true)`, punteros a
locales devueltos, `if (p) free(p)`, etc.

| Comando                           | Qué hace                                            |
| --------------------------------- | --------------------------------------------------- |
| `spunkmeyer detect src/ include/` | Busca antipatrones.                                 |
| `spunkmeyer explain <codigo>`     | Explica por qué es un antipatrón y cómo corregirlo. |
| `spunkmeyer list`                 | Lista el catálogo.                                  |
| `spunkmeyer fix src/`             | Corrige los antipatrones seguros de corregir.       |

### `kaneda` — seguridad

Funciones prohibidas (`gets`, `strcpy`, `sprintf`), desbordes de buffer y format
strings.

| Comando                      | Qué hace                                                         |
| ---------------------------- | ---------------------------------------------------------------- |
| `kaneda audit src/ include/` | Audita todo el proyecto.                                         |
| `kaneda scan archivo.c`      | Analiza un archivo y sugiere alternativas (`fgets`, `snprintf`). |
| `kaneda rules`               | Muestra funciones prohibidas y buenas prácticas.                 |

### `nostromo` — ejecución aislada

Ejecuta binarios en un sandbox (Bubblewrap + `setrlimit`) con límites de CPU y
memoria, y evalúa casos `.in`/`.out`.

| Comando                                                       | Qué hace                      |
| ------------------------------------------------------------- | ----------------------------- |
| `nostromo exec --timeout 2s --mem 32M -- ./bin/programa`      | Ejecuta con cuotas estrictas. |
| `nostromo run --binary ./bin/programa --testcases testcases/` | Corre la suite `.in`/`.out`.  |
| `nostromo gen-testcases --binary ./bin/canon -i inputs/`      | Genera los `.out` esperados.  |

### `bishop` — trazado visual de memoria

Ejecuta el programa bajo GDB y dibuja stack frames, variables, punteros y
bloques del heap.

| Comando                                            | Qué hace                                         |
| -------------------------------------------------- | ------------------------------------------------ |
| `bishop trace -- ./bin/programa`                   | Dibuja la memoria paso a paso en ASCII.          |
| `bishop trace --format mermaid -- ./bin/programa`  | Exporta a diagrama Mermaid.                      |
| `bishop snapshot -o memoria.txt -- ./bin/programa` | Guarda una captura completa del mapa de memoria. |
| `bishop inspect <pid>`                             | Inspecciona un proceso en ejecución.             |

---

## Herramientas de diagnóstico

Para cuando el programa compila pero falla, pierde memoria o hay que medir la
calidad de los tests.

### `hal` — caídas y core dumps

Diagnostica `SIGSEGV`, `SIGABRT`, `SIGFPE`: extrae el stack trace con GDB y lo
explica en cristiano.

| Comando                             | Qué hace                                            |
| ----------------------------------- | --------------------------------------------------- |
| `hal inspect ./bin/programa [args]` | Ejecuta, captura la caída y la diagnostica.         |
| `hal core ./bin/programa core.dump` | Análisis post-mortem de un core dump.               |
| `hal valgrind ./bin/programa`       | Corre Valgrind y traduce fugas y accesos inválidos. |

### `tetsuo` — AddressSanitizer / UBSan

Compila con sanitizers y traduce sus reportes.

| Comando                                         | Qué hace                                    |
| ----------------------------------------------- | ------------------------------------------- |
| `tetsuo compile src/*.c -o ./bin/instrumentado` | Compila con `-fsanitize=address,undefined`. |
| `tetsuo run -- ./bin/instrumentado`             | Ejecuta y traduce la salida en tiempo real. |
| `tetsuo translate < asan.log`                   | Traduce un reporte guardado.                |

### `vasquez` — inyección de fallos

Intercepta llamadas a glibc con `LD_PRELOAD`, sin recompilar, para probar los
caminos de error.

| Comando                                                              | Qué hace                                            |
| -------------------------------------------------------------------- | --------------------------------------------------- |
| `vasquez inject --target ./bin/programa --fail-malloc-at 3`          | La 3.ª llamada a `malloc` devuelve `NULL`.          |
| `vasquez inject --target ./bin/programa --faults "fopen:1,malloc:2"` | Fallos secuenciales combinados.                     |
| `vasquez check-leaks ./bin/programa`                                 | Verifica que no haya fugas en los caminos de error. |


---

## Uso con estos ejemplos

Flujo típico sobre un archivo:

```bash
daedalus compile punteros/basicos/01_direccion_e_indireccion.c -o bin/direccion
gaff check punteros/ -r
spunkmeyer detect memoria_dinamica/
bishop trace -- ./bin/direccion
```

Analizar un contraejemplo sin arriesgar la terminal:

```bash
tetsuo compile punteros/colgantes/01_retorno_de_variable_local.c -o bin/colgante
tetsuo run -- ./bin/colgante          # explica el acceso inválido
hal inspect ./bin/colgante            # alternativa sin sanitizers
nostromo exec --timeout 2s --mem 32M -- ./bin/colgante
```

Probar la robustez de los ejemplos de memoria dinámica:

```bash
daedalus compile memoria_dinamica/robustos/02_cleanup_contra_error.c -o bin/robusto
vasquez inject --target ./bin/robusto --fail-malloc-at 1
hal valgrind ./bin/robusto
```

### Integración en el `Makefile`

```makefile
check:
	gaff check src/ include/ -r
	ripley check src/ include/
	spunkmeyer detect src/ include/
	kaneda audit src/ include/

.PHONY: check
```

Ejecutá `make check` antes de cada commit.
