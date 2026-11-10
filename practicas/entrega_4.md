# Entrega #4: Programación Modular

Aplican las [reglas de estilo](https://ingcom-unrn-p1.github.io/indice-1/) evaluadas y ahora también aplican las [especificas a modularización](https://ingcom-unrn-p1.github.io/funciones-1/).

No olviden documentar las funciones.

Esta práctica viene con casos de prueba que deben pasar (`make test`).

Para ser considerada completa, se deben entregar **5 ejercicios**; descarguen el zip adjunto para el molde de la entrega.

## Enunciados

En un ejercicio en particular, reutilicen tanto código como sea posible.

### Ejercicio 1: Números Primos y Divisores

- **Módulo:** `ejercicios/ejercicio1/ejercicio1.h` / `ejercicios/ejercicio1/ejercicio1.c`
- **Operaciones a implementar:**
  1.  `int es_primo(int numero);`: Determina si un número entero es primo. Retorna `1` si es primo, `0` en caso contrario (los números menores o iguales a 1 no son primos).
  2.  `int proximo_primo(int numero_base);`: Retorna el menor número primo estrictamente mayor que `numero_base`.
  3.  `int cantidad_divisores(int numero);`: Retorna la cantidad total de divisores positivos de `numero`. Si `numero` es menor o igual a 0, retorna `0`.

### Ejercicio 2: Sucesión de Fibonacci

- **Módulo:** `ejercicios/ejercicio2/ejercicio2.h` / `ejercicios/ejercicio2/ejercicio2.c`
- **Operaciones a implementar:**
  1.  `int fibonacci(int posicion);`: Calcula el término correspondiente a la posición dada en la sucesión de Fibonacci (donde las posiciones 0 y 1 valen 0 y 1 respectivamente, y cada término siguiente es la suma de los dos anteriores). Si `posicion` es negativa, retorna `-1`.
  2.  `int suma_fibonacci(int hasta_posicion);`: Calcula la suma acumulada de los términos de Fibonacci desde la posición 0 hasta `hasta_posicion`. Si `hasta_posicion` es negativa, retorna `-1`.

### Ejercicio 3: Factorial y Combinatoria

- **Módulo:** `ejercicios/ejercicio3/ejercicio3.h` / `ejercicios/ejercicio3/ejercicio3.c`
- **Operaciones a implementar:**
  1.  `long long factorial(int numero);`: Calcula el factorial de un número entero no negativo. Para 0, el factorial es 1. Si `numero` es negativo, retorna `-1`.
  2.  `long long combinatorio(int cantidad_elementos, int elementos_por_grupo);`: Calcula la cantidad de combinaciones posibles de `cantidad_elementos` agrupados de a `elementos_por_grupo`. Si `elementos_por_grupo` es negativo, mayor a `cantidad_elementos`, o si `cantidad_elementos` es negativo, retorna `-1`.

### Ejercicio 4: Máximo Común Divisor (MCD) y Mínimo Común Múltiplo (MCM)

- **Módulo:** `ejercicios/ejercicio4/ejercicio4.h` / `ejercicios/ejercicio4/ejercicio4.c`
- **Operaciones a implementar:**
  1.  `int maximo_comun_divisor(int primer_numero, int segundo_numero);`: Calcula el máximo común divisor entre dos enteros mediante el algoritmo de Euclides. Si ambos valores son 0, retorna `-1`.
  2.  `int minimo_comun_multiplo(int primer_numero, int segundo_numero);`: Calcula el mínimo común múltiplo entre dos enteros positivos a partir de su producto y su máximo común divisor. Si alguno es menor o igual a 0, retorna `-1`.

### Ejercicio 5: Análisis y Transformación de Dígitos

- **Módulo:** `ejercicios/ejercicio5/ejercicio5.h` / `ejercicios/ejercicio5/ejercicio5.c`
- **Operaciones a implementar:**
  1.  `int contar_digitos(int numero);`: Retorna la cantidad de dígitos decimales de `numero` (el número 0 tiene 1 dígito).
  2.  `int sumar_digitos(int numero);`: Retorna la suma de los valores absolutos de los dígitos de `numero`.
  3.  `int invertir_numero(int numero);`: Invierte el orden de los dígitos conservando el signo (ejemplo: 1230 pasa a 321, -45 pasa a -54).
  4.  `int es_capicua(int numero);`: Retorna `1` si el número se lee igual de izquierda a derecha que de derecha a izquierda, `0` en caso contrario.

### Ejercicio 6: Potenciación Entera y Raíz Cuadrada Entera

- **Módulo:** `ejercicios/ejercicio6/ejercicio6.h` / `ejercicios/ejercicio6/ejercicio6.c`
- **Operaciones a implementar:**
  1.  `long long potencia(int base, int exponente);`: Calcula la potencia de la base elevada al exponente de forma iterativa para exponentes no negativos. Si `exponente` es negativo, retorna `-1`.
  2.  `int raiz_cuadrada_entera(int numero);`: Calcula la parte entera de la raíz cuadrada sin usar librerías externas. Si `numero` es negativo, retorna `-1`.

### Ejercicio 7: Conversión Decimal y Binario (Escalar)

- **Módulo:** `ejercicios/ejercicio7/ejercicio7.h` / `ejercicios/ejercicio7/ejercicio7.c`
- **Operaciones a implementar:**
  1.  `long long decimal_a_binario(int numero_decimal);`: Convierte un entero decimal no negativo a su representación binaria expresada como número entero (ejemplo: 13 pasa a 1101). Si `numero_decimal` es negativo, retorna `-1`.
  2.  `int binario_a_decimal(long long numero_binario);`: Convierte un número compuesto solo por dígitos 0 y 1 a su equivalente en base decimal (ejemplo: 1101 pasa a 13). Si contiene dígitos inválidos o es negativo, retorna `-1`.

### Ejercicio 8: Clasificación de Números (Perfectos, Deficientes y Abundantes)

- **Módulo:** `ejercicios/ejercicio8/ejercicio8.h` / `ejercicios/ejercicio8/ejercicio8.c`
- **Operaciones a implementar:**
  1.  `int suma_divisores_propios(int numero);`: Suma todos los divisores positivos de `numero` estrictamente menores al propio número. Si `numero` es menor o igual a 0, retorna `-1`.
  2.  `int clasificar_numero(int numero);`: Retorna `1` si la suma de divisores propios es igual a `numero` (perfecto), `0` si la suma es menor a `numero` (deficiente), o `2` si la suma es mayor a `numero` (abundante). Si `numero` es menor o igual a 0, retorna `-1`.

### Ejercicio 9: Conversión de Unidades de Temperatura

- **Módulo:** `ejercicios/ejercicio9/ejercicio9.h` / `ejercicios/ejercicio9/ejercicio9.c`
- **Operaciones a implementar:**
  1.  `float celsius_a_fahrenheit(float grados_celsius);`: Convierte una temperatura en grados Celsius a su equivalente en grados Fahrenheit.
  2.  `float fahrenheit_a_celsius(float grados_fahrenheit);`: Convierte una temperatura en grados Fahrenheit a su equivalente en grados Celsius.
  3.  `float celsius_a_kelvin(float grados_celsius);`: Convierte una temperatura en grados Celsius a su equivalente en grados Kelvin. Si la temperatura está por debajo del cero absoluto (-273.15 grados Celsius), retorna `-1.0f`.

### Ejercicio 10: Geometría Plana y Trigonometría

- **Módulo:** `ejercicios/ejercicio10/ejercicio10.h` / `ejercicios/ejercicio10/ejercicio10.c`
- **Operaciones a implementar:**
  1.  `float perimetro_circulo(float radio);`: Retorna el perímetro de un círculo a partir de su radio. Si `radio` es negativo, retorna `-1.0f`.
  2.  `float area_circulo(float radio);`: Retorna el área de un círculo a partir de su radio. Si `radio` es negativo, retorna `-1.0f`.
  3.  `float area_triangulo(float base, float altura);`: Retorna el área de un triángulo a partir de su base y su altura. Si alguna de las dimensiones es menor o igual a 0, retorna `-1.0f`.
  4.  `float calcular_hipotenusa(float primer_cateto, float segundo_cateto);`: Retorna la longitud de la hipotenusa de un triángulo rectángulo a partir de sus dos catetos. Si algún cateto es menor o igual a 0, retorna `-1.0f`.

### Compilación

El `Makefile` principal en la raíz detecta automáticamente todos los subdirectorios dentro de `ejercicios/`, por lo que **no es necesario modificar el `Makefile` raíz**. Al ejecutar `make`, `make test`, `make run` o `make clean` desde la raíz, el nuevo ejercicio se incluirá automáticamente en la secuencia.
