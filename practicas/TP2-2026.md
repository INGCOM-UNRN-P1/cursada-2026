# Trabajo Práctico 2 (2026): Arreglos de Enteros y Cadenas Seguras

Universidad Nacional de Río Negro — Ingeniería en Computación  
Programación 1 [B6003]

---

### Condición de completado

Completar todas las funciones con prototipo y al menos una de la sección sin
prototipo.

---
## Introducción

En el lenguaje C estándar (ISO/IEC 9899:2011, C11), los arreglos y las cadenas
de caracteres carecen de metadatos en tiempo de ejecución:

- Un arreglo no conoce su propia cantidad de elementos ni su capacidad física en
  memoria. Al pasarse a una función, debe acompañarse obligatoriamente por su
  tamaño (`size_t cantidad`).
- Las funciones históricas de la biblioteca estándar para cadenas (`strcpy`,
  `strcat`, `sprintf`, `gets`) asumen que el búfer destino tiene capacidad
  infinita. Si el texto a escribir excede el espacio disponible, se produce un
  **desbordamiento de búfer** (_buffer overflow_), corrompiendo variables
  contiguas, el _stack_ del programa o provocando fallos de segmentación
  (_Segmentation Fault_).

El propósito de esta práctica es diseñar, implementar y verificar dos
bibliotecas estáticas:

1. **`libarreglos`**: Procesamiento de arreglos unidimensionales de enteros
   (`int`), con paso explícito de cantidad (`size_t cantidad`) y protección de
   escritura mediante _const-correctness_ (`const int arreglo[]`).
2. **`libcadenas`**: Manipulación de **cadenas seguras**, donde toda operación
   sobre un búfer en memoria exige un parámetro obligatorio `size_t capacidad`,
   garantizando el terminador nulo (`\0`) y la contención estricta en memoria.

> [!IMPORTANT] **Tarea de los estudiantes**: Los archivos
> `libs/arreglos/arreglos.c` y `libs/cadenas/cadenas.c` se entregan con
> esqueletos vacíos. La implementación completa de todas las funciones
> de ambas bibliotecas debe ser desarrollada íntegramente por los estudiantes.

---

## Fundamentos de Cadenas Seguras en C

Una **cadena segura** en esta cátedra cumple cuatro principios:

1. **Capacidad explícita (`size_t capacidad`)**:  
   Toda función que reciba un búfer destino o inspeccione una cadena recibe la
   capacidad total en bytes del búfer en memoria física (incluyendo el byte del
   terminador).
2. **Garantía de terminación nula**:  
   Si `capacidad > 0`, el búfer destino queda **siempre finalizado con el
   carácter nulo `'\0'`** dentro de los límites válidos `[0, capacidad - 1]`.
3. **Inmunidad a desbordamientos (_Buffer Overflow_)**:  
   Jamás se escribe en el índice `capacidad` o superior. La longitud máxima de
   texto admisible es `capacidad - 1`.
4. **Reporte de truncamiento**:  
   Si el texto de origen excede el espacio disponible, se escriben los primeros
   `capacidad - 1` caracteres, se agrega `'\0'` y se retorna `false` (o un código de error) para alertar al llamador sobre la pérdida de datos.

### Comparación de Seguridad

| Operación         | Enfoque Clásico Inseguro (`<string.h>`)                            | Enfoque Seguro (`libcadenas`)                                                                                          |
| :---------------- | :----------------------------------------------------------------- | :--------------------------------------------------------------------------------------------------------------------- |
| **Copia**         | `strcpy(dst, src)`: Escribe sin límite hasta hallar `\0` en `src`. | `cadena_copiar(destino, capacidad, origen)`: Escribe como máximo `capacidad - 1`, asegura `\0` y reporta truncamiento. |
| **Concatenación** | `strcat(dst, src)`: Anexa sin verificar el espacio residual.       | `cadena_concatenar(destino, capacidad, origen)`: Verifica espacio disponible, anexa sin desbordar y asegura `\0`.      |
| **Medición**      | `strlen(s)`: Lee memoria indefinidamente si falta `\0`.            | `cadena_longitud(cadena, capacidad)`: No examina más de `capacidad` bytes en memoria.                                  |

---

## Estructura del repositorio

El proyecto incorpora el framework didáctico de pruebas unitarias **`p1_test`**
dentro del árbol de directorios como parte de la entrega:

```text
.
├── libs/
│   ├── arreglos/         # Biblioteca libarreglos.a
│   │   ├── arreglos.h    # Cabecera y contratos
│   │   ├── arreglos.c    # Esqueletos a implementar por los estudiantes
│   │   ├── Makefile      # Compilación de la librería y su suite
│   │   └── prueba.c      # Suite de pruebas unitarias con p1_test
│   ├── cadenas/          # Biblioteca libcadenas.a
│   │   ├── cadenas.h     # Cabecera y contratos
│   │   ├── cadenas.c     # Esqueletos a implementar por los estudiantes
│   │   ├── Makefile      # Compilación de la librería y su suite
│   │   └── prueba.c      # Suite de pruebas unitarias con p1_test
│   └── p1_test/          # Framework de pruebas de la cátedra (incluido en la entrega)
│       ├── p1_test.h     # Macros principales de aserciones y suites
│       ├── p1_arrays.h   # Aserciones especializadas para arreglos
│       ├── p1_files.h    # Aserciones para archivos
│       ├── p1_stdio.h    # Mocks y captura de entrada/salida
│       ├── Makefile      # Compilación y autoverificación de p1_test
│       └── prueba.c      # Suite de autoverificación del framework
├── ejercicios/
│   ├── ejercicio1/       # Aplicativo que consume libarreglos
│   │   ├── main.c
│   │   ├── operaciones.h
│   │   ├── operaciones.c
│   │   ├── Makefile
│   │   └── prueba.c      # Pruebas con p1_test
│   └── ejercicio2/       # Aplicativo que consume libcadenas
│       ├── main.c
│       ├── texto.h
│       ├── texto.c
│       ├── Makefile
│       └── prueba.c      # Pruebas con p1_test
├── Makefile              # Makefile principal dinámico
├── tp.sh                 # Gestor modular de TP
└── README.md             # Enunciado y especificación técnica
```

---

## A.Ejercicios en `libarreglos`

### Ejercicio A.1: Sumatoria de Elementos

- **Firma**:
  ```c
  long long arreglo_sumar(const int arreglo[], size_t cantidad);
  ```
- **Descripción**: Calcula y retorna la suma de los elementos del arreglo.
- **Contrato**: Si `arreglo == NULL` o `cantidad == 0`, retorna `0`.

### Ejercicio A.2: Búsqueda Lineal

- **Firma**:
  ```c
  int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado);
  ```
- **Descripción**: Localiza el índice de la primera aparición del número
  `buscado`.
- **Contrato**: Retorna el índice en base cero
  ($0 \le \text{índice} < \text{cantidad}$) o `-1` si no existe o ante entradas
  nulas.

### Ejercicio A.3: Inversión In-Place

- **Firma**:
  ```c
  void arreglo_invertir(int arreglo[], size_t cantidad);
  ```
- **Descripción**: Invierte el orden de los elementos in-place sin memoria
  adicional.
- **Contrato**: Si `arreglo == NULL` o `cantidad <= 1`, no realiza cambios.

### Ejercicio A.4: Verificación de Orden Ascendente

- **Firma**:
  ```c
  bool arreglo_ordenado(const int arreglo[], size_t cantidad);
  ```
- **Descripción**: Verifica si los elementos del arreglo se encuentran ordenados
  ascendentemente ($arreglo[i] \le arreglo[i+1]$ para toda posición válida).
- **Contrato**: Retorna `true` si está ordenado ascendentemente o si
  `cantidad <= 1`; retorna `false` si encuentra elementos fuera de orden o si
  `arreglo == NULL`.

### Ejercicio A.5: Conteo de Ocurrencias

- **Firma**:
  ```c
  size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado);
  ```
- **Descripción**: Cuenta y retorna cuántas veces aparece el número entero
  `buscado` dentro del arreglo.
- **Contrato**: Retorna el total de coincidencias; retorna `0` si
  `arreglo == NULL` o si `cantidad == 0`.

### Ejercicio A.6: Compactación In-Place

- **Consigna**: Eliminar todas las apariciones de un valor entero dentro de un
  arreglo, compactando los elementos restantes hacia la izquierda sin dejar
  huecos y preservando su orden relativo original. Operación in-place sin
  memoria dinámica.
- **Desafío de diseño**:
  - Definir la firma en `libs/arreglos/arreglos.h` respetando la regla de
    nombres (hasta 12 caracteres, sin abreviaciones).
  - Determinar el tipo de retorno para informar la nueva cantidad de elementos
    válidos (`size_t`).

> [!NOTE] La firma es parte del diseño: es necesario decidir nombre, parámetros y tipo de retorno respetando las convenciones de la cátedra.

### Ejercicio A.7: Fusión Ordenada (_Merge_)

- **Consigna**: Dados dos arreglos ordenados ascendentemente, fusionar sus
  elementos en un tercer arreglo destino de capacidad finita, manteniéndolo
  ordenado sin desbordar la memoria.
- **Desafío de diseño**:
  - Distinguir parámetros de entrada (`const int primero[]`, `size_t`) de los
    de salida (`int destino[]`, `size_t capacidad`).
  - Retornar la cantidad de elementos volcados en destino.

> [!NOTE] En esta práctica la fusión opera sobre buffers de capacidad fija. En TP4 se revisitará este algoritmo usando memoria dinámica (`malloc`), lo que permite retornar un arreglo de tamaño exacto sin necesidad de un buffer destino externo.

---

## B. Ejercicios: `libcadenas`

### Ejercicio B.1: Medición de longitud

- **Firma**:
  ```c
  size_t cadena_longitud(const char cadena[], size_t capacidad);
  ```
- **Descripción**: Cuenta caracteres antes de `'\0'`, inspeccionando a lo sumo
  `capacidad` bytes. Retorna `capacidad` si no hay terminador en ese rango.

### Ejercicio B.2: Copia con control de Búfer

- **Firma**:
  ```c
  bool cadena_copiar(char destino[], size_t capacidad, const char origen[]);
  ```
- **Descripción**: Copia `origen` en `destino`. Si trunca, coloca `'\0'` en
  `capacidad - 1` y retorna `false`. Retorna `true` si cupo completa.

### Ejercicio B.3: Concatenación

- **Firma**:
  ```c
  bool cadena_concatenar(char destino[], size_t capacidad, const char origen[]);
  ```
- **Descripción**: Anexa `origen` a continuación del texto existente en
  `destino`, asegurando terminador nulo sin superar `capacidad`. Retorna `false`
  si truncó.

### Ejercicio B.4: Normalización a mayúsculas

- **Firma**:
  ```c
  size_t cadena_a_mayusculas(char cadena[], size_t capacidad);
  ```
- **Descripción**: Convierte in-place caracteres minúsculas a mayúsculas dentro
  del límite de `capacidad`. Retorna el conteo de conversiones efectuadas.

### Ejercicio B.5: Subcadena Segura (_slice_)

- **Consigna**: Extraer una porción de `origen` a partir de `inicio`, copiando a
  lo sumo `cantidad` caracteres en un búfer destino seguro de tamaño acotado
  (`capacidad`).
- **Desafío de diseño**:
  - Garantizar terminador `\0` en destino y retorno de estado o conteo copiado.

### Ejercicio B.6: Entero a Cadena Decimal (_itoa seguro_)

- **Consigna**: Convertir un `int valor` (positivo, negativo o cero,
  contemplando `INT_MIN`) a caracteres ASCII decimales dentro de un búfer seguro
  acotado por `capacidad`.
- **Desafío de diseño**:
  - Manejar signo, dígitos y el caso extremo de `INT_MIN` sin desbordamiento.

---

## Compilación, Pruebas y Evaluación con `p1_test`

El framework de testing didáctico `p1_test` se incluye en `libs/p1_test` y provee:

- Aserciones didácticas tipadas (`ASSERT_INT_EQ`, `ASSERT_STR_EQ`,
  `ASSERT_ARRAY_INT_EQ`).
- Aislamiento de fallos con `setjmp`/`longjmp` y rescate ante violaciones de
  segmento (`SIGSEGV`).
- Subcasos descriptivos (`SUBCASE`) con reporte detallado de línea y valores
  obtenidos vs esperados.

Pueden consultar su manual en su repositorio [INGCOM-UNRN-P1/treadstone](https://github.com/INGCOM-UNRN-P1/treadstone)

### Comandos de Desarrollo

1. **Compilar todo el proyecto**:
   ```bash
   make all
   ```
2. **Ejecutar todas las suites de prueba**:
   ```bash
   make test
   ```
3. **Probar una biblioteca individual**:
   ```bash
   make -C libs/arreglos test
   make -C libs/cadenas test
   make -C libs/p1_test test
   ```
4. **Opciones CLI de `p1_test`**: Los ejecutables de prueba admiten parámetros
   estándar para depuración:
   - `-f, --fail-fast`: Detiene la ejecución en el primer assert fallido.
   - `-k, --filter <texto>`: Filtra y corre solo los tests cuyo nombre coincida
     con el texto.
   - `-q, --quiet`: Reporte compacto con puntos de avance (`.` y `F`).
   ```bash
   ./libs/arreglos/test_bin -k sumar
   ./libs/cadenas/test_bin --fail-fast
   ```
5. **Auditoría de memoria con Valgrind**:
   ```bash
   make memcheck
   ```
6. **Limpieza completa**:
   ```bash
   make clean
   ```

---

## Criterios de Evaluación

1. **Compilación limpia**: Compilar con `-Wall -Wextra -std=c11 -pedantic` sin
   advertencias.
2. **Cumplimiento de las reglas de estilo**
3. **100% de aserciones aprobadas en `p1_test`**: Todas las pruebas provistas
   deben pasar sin fallos.
4. **Pruebas añadidas para los ejercicios abiertos**: El estudiante debe
   incorporar en `prueba.c` los casos de prueba para los ejercicios sin prototipo de cada biblioteca: **A.6** (compactar) y **A.7** (fusión) en `libarreglos`, y **B.5** (subcadena) y **B.6** (itoa) en `libcadenas`.
