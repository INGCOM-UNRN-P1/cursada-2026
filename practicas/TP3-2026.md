# Trabajo Práctico 3 (2026): Punteros y Aritmética de Punteros

Universidad Nacional de Río Negro — Ingeniería en Computación  
Programación 1 [B6003]



### Condición de completado

1. Implementar las funciones de la biblioteca `libpunteros` (`intercambiar` y `obtener_min_max`), superando su suite de pruebas unitarias provista con `p1_test`.
2. Completar los 6 ejercicios prácticos:
   - Para **Ejercicio 1** y **Ejercicio 2**: diseñar los prototipos formales en sus respectivos archivos `.h` (respetando las reglas de estilo y documentación Doxygen), implementar las funciones en los `.c` y superar los tests provistos con `p1_test`.
   - Para los **Ejercicios 3, 4, 5 y 6**: diseñar la especificación formal y prototipos en el `.h`, implementar las soluciones en el `.c`, desarrollar el programa interactivo demostrativo en `main.c` y diseñar íntegramente la suite de pruebas unitarias exhaustiva con `p1_test` en `prueba.c`.
3. Todos los ejercicios que procesen secuencias deben operar **estrictamente mediante aritmética de punteros** (recorridos con punteros, operadores de desreferencia `*p`, avance `p++`, suma `p + offset` y resta de punteros `p2 - p1`), prohibiéndose el uso del operador de indexación `arreglo[i]`.

> [!WARNING] **Restricción de Memoria y ALV's**:
> Recuerden que no está permitido utilizar ALV's (Arreglos de Longitud Variable / *Variable Length Arrays*), pero también, este trabajo práctico **no está pensado para utilizar memoria dinámica** (`malloc`/`free`). Todas las operaciones deben resolverse sobre la memoria ya provista y acotada por los llamadores.

> [!TIP] **Reutilización de bibliotecas del TP2 en `libs/`**:
> Podés copiar tus directorios `cadenas` y/o `arreglos` desarrollados en el TP2 directamente dentro de la carpeta `libs/` de este repositorio (`libs/cadenas` y `libs/arreglos`).
> El sistema de compilación y los `Makefiles` de los ejercicios detectan y enlazan dinámicamente cualquier biblioteca presente en `libs/`, permitiéndote reutilizar funciones ya resueltas (como impresión de arreglos, validaciones de cadenas seguras o conversiones).



## Introducción

En el estándar C11, los arreglos y los punteros están íntimamente ligados por la regla de decaimiento (_array-to-pointer decay_): el nombre de un arreglo evalúa a la dirección en memoria de su primer elemento. No obstante, un puntero es una variable independiente capaz de direccionamiento directo y cálculos aritméticos en unidades escaladas por el tamaño del tipo apuntado (`sizeof(*p)`).

El propósito de este Trabajo Práctico es dominar el modelo de memoria de C, pasando de la indexación estática al uso riguroso de:
- Paso por referencia para mutación de variables (`int *a`).
- Parámetros de salida para retornos múltiples (`bool fn(..., int *minimo, int *maximo)`).
- Aritmética de punteros pura (`p++`, `*p`, `fin - inicio`).
- _Const-correctness_ en punteros de solo lectura (`const int *`, `const char *`).
- Navegación y manipulación de cadenas seguras en memoria contigua.



## Estructura del Repositorio

```text
.
├── libs/
│   ├── punteros/         # Biblioteca estática libpunteros.a
│   │   ├── punteros.h    # Cabecera con primitivas: intercambiar y obtener_min_max
│   │   ├── punteros.c    # Implementación a completar por el estudiante
│   │   ├── Makefile      # Compilación de la librería y su suite
│   │   └── prueba.c      # Pruebas unitarias con p1_test
│   ├── p1_test/          # Framework de pruebas unitarias de la cátedra
│   │   ├── p1_test.h
│   │   ├── Makefile
│   │   └── ...
│   ├── [arreglos/]       # (Opcional) Librería traída del TP2
│   └── [cadenas/]        # (Opcional) Librería traída del TP2
├── ejercicios/
│   ├── ejercicio1/       # Ordenamiento de pares, tríos y suma acumulada
│   │   ├── intercambio.h # Prototipos y contratos a diseñar (ordenar_par, ordenar_tria, sumar_acumulado)
│   │   ├── intercambio.c # Implementación (consume libpunteros)
│   │   ├── main.c        # Programa demostrativo
│   │   ├── prueba.c      # Suite de tests provista completa con p1_test
│   │   └── Makefile
│   ├── ejercicio2/       # Estadísticas, promedio y filtrado por rango con punteros
│   │   ├── estadistica.h # Prototipos y contratos a diseñar (calcular_estadisticas, contar_en_rango)
│   │   ├── estadistica.c # Implementación (consume libpunteros)
│   │   ├── main.c        # Programa demostrativo
│   │   ├── prueba.c      # Suite de tests provista completa con p1_test
│   │   └── Makefile
│   ├── ejercicio3/       # Recorrido, copia e inversión in-place con 2 punteros
│   │   ├── recorrido.h   # Prototipos a diseñar desde cero
│   │   ├── recorrido.c   # Implementación desde cero
│   │   ├── main.c        # Programa demostrativo a desarrollar
│   │   ├── prueba.c      # Suite de tests a desarrollar con p1_test
│   │   └── Makefile
│   ├── ejercicio4/       # Búsqueda con retorno de puntero y distancia (p2 - p1)
│   │   ├── busqueda.h    # Prototipos a diseñar desde cero
│   │   ├── busqueda.c    # Implementación desde cero
│   │   ├── main.c        # Programa demostrativo a desarrollar
│   │   ├── prueba.c      # Suite de tests a desarrollar con p1_test
│   │   └── Makefile
│   ├── ejercicio5/       # Cadenas seguras con punteros (complementario a TP2)
│   │   ├── puntero_cadena.h
│   │   ├── puntero_cadena.c
│   │   ├── main.c
│   │   ├── prueba.c
│   │   └── Makefile
│   └── ejercicio6/       # Algoritmo de selección con punteros
│       ├── ordenamiento.h
│       ├── ordenamiento.c
│       ├── main.c
│       ├── prueba.c
│       └── Makefile
├── Makefile              # Makefile raíz dinámico modular
├── tp.sh                 # Script interactivo de gestión
└── README.md
```



## 1. Ejercicios de Biblioteca: `libpunteros`

Contiene primitivas fundamentales de manipulación por referencia y recorrido de arreglos disponibles para todo el proyecto.

### `intercambiar`

- **Firma provista**:
  ```c
  void intercambiar(int *primer, int *segundo);
  ```
- **Consigna**: Intercambia los contenidos de dos variables enteras recibidas por referencia a través de punteros.
- **Casos borde**: Si algún puntero es `NULL`, no produce ningún efecto. Si ambos punteros son iguales, el valor se preserva.

### `obtener_min_max`

- **Firma provista**:
  ```c
  bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo);
  ```
- **Consigna**: Determina el mínimo y máximo de un arreglo de enteros recorriéndolo estrictamente con aritmética de punteros, escribiendo los resultados en `*minimo` y `*maximo`.
- **Casos borde**: Retorna `false` si `arreglo == NULL`, `cantidad == 0` o si alguno de los punteros de salida es `NULL`. Retorna `true` ante éxito.
- **Suite provista**: [`libs/punteros/prueba.c`](libs/punteros/prueba.c).



## 2. Ejercicios Prácticos para Completar

### Ejercicio 1: Ordenamiento de Pares, Tríos y Acumulación (Tests provistos)
- **Archivos**: `ejercicios/ejercicio1/`
- **Consigna**:
  - `ordenar_par`: Recibe `int *menor` e `int *mayor`. Asegura `*menor <= *mayor` delegando el intercambio en `intercambiar` de `libpunteros`.
  - `ordenar_tria`: Recibe tres punteros `int *a, int *b, int *c` y los ordena ascendentemente apoyándose en `ordenar_par` e `intercambiar`.
  - `sumar_acumulado`: Recibe `const int *arreglo, size_t cantidad, long long *resultado`. Recorre el arreglo estrictamente con aritmética de punteros y retorna `true` si guardó la suma en `*resultado`, o `false` ante punteros nulos.
- **Tests provistos**: [`ejercicios/ejercicio1/prueba.c`](ejercicios/ejercicio1/prueba.c).

### Ejercicio 2: Estadísticas, Promedio y Rango (Tests provistos)
- **Archivos**: `ejercicios/ejercicio2/`
- **Consigna**:
  - `calcular_estadisticas`: Recibe `const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio`. Emplea `obtener_min_max` de `libpunteros` para determinar extremos y acumula con aritmética de punteros para calcular el promedio.
  - `contar_en_rango`: Recibe `const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias`. Cuenta elementos en el intervalo cerrado `[limite_inf, limite_sup]` usando aritmética de punteros.
- **Tests provistos**: [`ejercicios/ejercicio2/prueba.c`](ejercicios/ejercicio2/prueba.c).

### Ejercicio 3: Copia e Inversión In-Place con Punteros (A desarrollar íntegramente)
- **Archivos**: `ejercicios/ejercicio3/`
- **Consigna**:
  - `copiar_arreglo`: Copia todos los elementos de un arreglo fuente a un arreglo destino de igual o mayor tamaño, usando exclusivamente aritmética de punteros (sin `[]`). Establecé las precondiciones de los punteros en el `.h`.
  - `invertir_arreglo`: Invierte in-place un arreglo empleando dos punteros que convergen desde los extremos, reutilizando `intercambiar`.
- **Responsabilidad del alumno**: Prototipos y documentación en `recorrido.h`, lógica en `recorrido.c`, demostración en `main.c` y suite en `prueba.c`.

### Ejercicio 4: Búsqueda con Retorno de Puntero y Distancia (A desarrollar íntegramente)
- **Archivos**: `ejercicios/ejercicio4/`
- **Consigna**:
  - `buscar_primero`: Retorna un puntero a la primera ocurrencia de un valor (`const int *`), o `NULL` si no existe.
  - `distancia_punteros`: Determina el índice relativo calculando la resta de punteros (`elemento - inicio`).
- **Responsabilidad del alumno**: Prototipos y documentación en `busqueda.h`, lógica en `busqueda.c`, demostración en `main.c` y suite en `prueba.c`.

> [!NOTE] Comparar `buscar_primero` con `buscar_puntero_minimo` (Ej6): ambos recorren el arreglo con punteros, pero `buscar_primero` termina al encontrar el valor buscado (cortocircuito), mientras que `buscar_puntero_minimo` siempre recorre el rango completo. ¿Cuál es la diferencia en complejidad promedio vs. peor caso?

### Ejercicio 5: Cadenas Seguras con Aritmética de Punteros (A desarrollar íntegramente)
- **Archivos**: `ejercicios/ejercicio5/`
- **Complementario al TP2**: Reimplementar con aritmética de punteros (sin `[]`) las siguientes funciones equivalentes a las de `libcadenas` del TP2:
  - `copiar_con_punteros(char *dest, size_t cap, const char *src)`: equivalente a `cadena_copiar`.
  - `concatenar_con_punteros(char *dest, size_t cap, const char *src)`: equivalente a `cadena_concatenar`.
  - `longitud_con_punteros(const char *s, size_t cap)`: equivalente a `cadena_longitud`.
  Contratos, firma y documentación en `puntero_cadena.h`. El objetivo es contrastar la implementación con índices del TP2 vs. la implementación con punteros.
- **Responsabilidad del alumno**: Prototipos y documentación en `puntero_cadena.h`, lógica en `puntero_cadena.c`, demostración en `main.c` y suite en `prueba.c`.

### Ejercicio 6: Ordenamiento por Selección con Punteros (A desarrollar íntegramente)
- **Archivos**: `ejercicios/ejercicio6/`
- **Consigna**:
  - `buscar_puntero_minimo`: Recorre un rango acotado por punteros (`[inicio, fin)`) y retorna el puntero al elemento mínimo.
  - `ordenar_seleccion_punteros`: Implementa el algoritmo Selection Sort ordenando in-place mediante aritmética de punteros e `intercambiar`.
- **Responsabilidad del alumno**: Prototipos y documentación en `ordenamiento.h`, lógica en `ordenamiento.c`, demostración en `main.c` y suite en `prueba.c`.

## Tests y asserts

Podés consultar el [manual de la librería de testing](./libs/p1_test/docs/p1_test_manual.md)

## Comandos de Compilación y Prueba

- Compilar todo el proyecto:
  ```bash
  make all
  ```
- Ejecutar todas las pruebas unitarias:
  ```bash
  make test
  ```
- Probar un módulo individual:
  ```bash
  make -C libs/punteros test
  make -C ejercicios/ejercicio1 test
  make -C ejercicios/ejercicio2 test
  ```
- Comprobación con Valgrind:
  ```bash
  make memcheck
  ```
- Limpieza:
  ```bash
  make clean
  ```
