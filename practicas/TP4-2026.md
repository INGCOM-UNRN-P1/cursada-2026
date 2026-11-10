# Trabajo Práctico 4 (2026): Memoria Dinámica en C11 (Sin Structs)

Universidad Nacional de Río Negro — Ingeniería en Computación  
Programación 1 [B6003]

---

### Condición de completado

1. **Bibliotecas de Memoria Dinámica**:
   - **`libvector`**: Manejo de bloques de enteros en heap sin structs (`crear_bloque_enteros`, `liberar_bloque_enteros`, `redimensionar_bloque_enteros`).
      - **Ejercicios sin prototipo previo a diseñar e implementar en `libvector`**:
        1. `fusionar_bloques_enteros`: Concatena dos bloques contiguos reservando el espacio exacto en heap (`n1 + n2`), ideal cuando el tamaño final es conocido de antemano.
        2. `agregar_al_bloque_enteros`: Inserción al final con doble puntero (`int **`) y redimensionamiento dinámico (crecimiento geométrico o incremental de capacidad), optimizado para secuencias de inserciones sucesivas.
   - **`libstring`**: Manipulación y gestión de cadenas seguras en heap sin structs (`cadena_duplicar_segura`, `cadena_unir_dinamica`, `cadena_liberar_segura`).
     - **Ejercicios sin prototipo previo a diseñar e implementar en `libstring`**:
       1. `cadena_subcadena_dinamica`: Extracción de subcadena segura con asignación exacta en heap.
       2. `cadena_invertir_dinamica`: Generación de una nueva cadena invertida en heap.
2. Completar los 6 ejercicios prácticos de aplicación gradual (sin utilizar estructuras `struct`):
   - **Ejercicio 1** y **Ejercicio 2**: Diseñar prototipos en sus headers, implementar la lógica en los `.c` y superar las pruebas unitarias completas provistas con `p1_test`.
   - **Ejercicios 3, 4, 5 y 6**: Diseñar la arquitectura, prototipos, código en `main.c` y suites de pruebas exhaustivas con `p1_test` en `prueba.c`.
3. Gestión rigurosa de memoria: toda asignación con `malloc`/`calloc`/`realloc` debe liberarse con `free`. Cero fugas con `make memcheck` (Valgrind).

> [!TIP] **Reutilización de bibliotecas previas**:
> Podés copiar la biblioteca `cadenas` del TP2 directamente en `libs/cadenas` de este repositorio. Las funciones de medición y control de búfer seguro pueden reutilizarse directamente en tus soluciones dinámicas.

---

## Estructura del Repositorio

```text
.
├── libs/
│   ├── vector/               # Biblioteca estática libvector.a (int*, int**)
│   │   ├── vector.h          # 3 prototipos provistos + 2 ejercicios sin prototipo
│   │   ├── vector.c
│   │   ├── Makefile
│   │   └── prueba.c
│   ├── string/               # Biblioteca estática libstring.a (char*, char**)
│   │   ├── string.h          # 3 prototipos provistos + 2 ejercicios sin prototipo
│   │   ├── string.c
│   │   ├── Makefile
│   │   └── prueba.c
│   └── p1_test/              # Framework didáctico de pruebas
├── ejercicios/
│   ├── ejercicio1/           # Clonación y filtrado de arreglos dinámicos (Tests provistos)
│   ├── ejercicio2/           # Normalización y recorte dinámico de cadenas (Tests provistos)
│   ├── ejercicio3/           # Reversión y particionado dinámico de cadenas
│   ├── ejercicio4/           # Bloques contiguos 2D simulados (matriz plana en heap int*)
│   ├── ejercicio5/           # Listas dinámicas de cadenas en heap (char**)
│   └── ejercicio6/           # Filtro y procesamiento de texto dinámico multilinea
├── Makefile
├── tp.sh
└── README.md
```

---

## Consignas de los Ejercicios

### Ejercicio 1: Clonación y Filtrado de Arreglos Dinámicos (Tests provistos)

- `clonar_bloque`: recibe un `const int *` de tamaño `n` y retorna una copia exacta en heap (`malloc`). Retorna `NULL` si el puntero es `NULL` o `n == 0`.
- `filtrar_bloque_positivos`: recibe un `const int *` de tamaño `n` y retorna un nuevo bloque solo con los elementos > 0, almacenando la cantidad resultante en un parámetro de salida `size_t *`. Retorna `NULL` si no hay elementos positivos.

### Ejercicio 2: Normalización y Recorte Dinámico de Cadenas (Tests provistos)

- `recortar_espacios_dinamico`: recibe una cadena y retorna una copia en heap con los espacios iniciales y finales eliminados.
- `normalizar_mayusculas_dinamico`: retorna una copia en heap de la cadena con todos los caracteres en mayúsculas.
- Ambas funciones retornan `NULL` ante parámetros inválidos y el llamador es responsable de liberar la memoria.

### Ejercicio 3: Reversión y Particionado Dinámico de Cadenas (A desarrollar íntegramente)

- `invertir_cadena_dinamico`: retorna en heap una nueva cadena con los caracteres en orden inverso.
- `partir_por_delimitador`: recibe una cadena y un carácter delimitador; retorna un `char **` con los tokens separados por ese delimitador y almacena la cantidad en un parámetro de salida `size_t *`. Cada token es una cadena independiente en heap.
- Diseñar prototipos en el `.h`, implementar en el `.c`, demostrar en `main.c` y agregar suite en `prueba.c`.

### Ejercicio 4: Bloque Contiguo 2D Simulado (Matriz Plana en Heap) (A desarrollar íntegramente)

Simular una matriz de `filas × columnas` enteros usando un único bloque contiguo `int *`, donde el elemento `(i, j)` se accede como `bloque[i * columnas + j]`.

- `crear_matriz_plana(size_t filas, size_t columnas)`: reserva el bloque en heap, inicializado en cero.
- `obtener_celda(const int *m, size_t columnas, size_t fila, size_t col)`: retorna el valor de la celda.
- `asignar_celda(int *m, size_t columnas, size_t fila, size_t col, int valor)`: escribe el valor.
- `liberar_matriz_plana(int *m)`: libera el bloque.

> [!NOTE] Este ejercicio es el precursor conceptual de `libmatrices` del TP7, donde se agrega una capa de punteros de fila (`int **filas`) para permitir notación `m[i][j]`.

### Ejercicio 5: Listas Dinámicas de Cadenas en Heap (`char **`) (A desarrollar íntegramente)

Manejar un arreglo dinámico de cadenas (`char **lista`) donde cada elemento es una cadena independiente en heap.

- `lista_cadenas_crear(void)`: retorna un `char **` apuntando a un arreglo vacío (o `NULL`).
- `lista_cadenas_agregar(char ***lista, size_t *cantidad, const char *cadena)`: duplica la cadena y la agrega al final, redimensionando con `realloc`.
- `lista_cadenas_destruir(char **lista, size_t cantidad)`: libera cada cadena y luego el arreglo.

> [!NOTE] `char **` es el tipo de `argv` en `main(int argc, char **argv)`. Este ejercicio generaliza ese patrón.

### Ejercicio 6: Filtro y Procesamiento de Texto Dinámico Multilinea (A desarrollar íntegramente)

Leer líneas de texto desde `stdin` (sin saber cuántas hay de antemano), almacenarlas dinámicamente y procesarlas:

- Leer líneas con `fgets` en un buffer fijo y duplicarlas en heap con `strdup` o equivalente.
- Acumular las líneas en un `char **` redimensionable.
- Filtrar y mostrar solo las líneas que contengan una subcadena dada.
- Liberar toda la memoria al terminar.

---

## Comandos de Compilación y Prueba

- Compilar todo el proyecto:
  ```bash
  make all
  ```
- Ejecutar suites de prueba:
  ```bash
  make test
  ```
- Auditoría con Valgrind:
  ```bash
  make memcheck
  ```
- Limpieza:
  ```bash
  make clean
  ```
