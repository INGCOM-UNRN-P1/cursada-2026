# Solucionario de Ejercicios y Análisis de Bugs en C

Este documento contiene el análisis línea por línea, causa raíz y solución propuesta para cada uno de los ejercicios de la carpeta `ejercicios/`.

---

## 1. Aritmética

### `aritmetica/ejercicio_01.c`
* **Comportamiento observado**: Imprime un número negativo (`El promedio de 2000000000 y 2000000000 es: -147483648`).
* **Causa Raíz**: En la línea `int promedio = (a + b) / 2;`, la expresión entre paréntesis `(a + b)` se evalúa primero. Como ambos son `int` de 32 bits, `2000000000 + 2000000000 = 4000000000`, valor que supera `INT_MAX` (2147483647). Ocurre un **Signed Integer Overflow**, provocando *Undefined Behavior* y envolviendo el valor a negativo antes de dividir por 2.
* **Solución**:
  ```c
  // Opcion 1: Usar tipo de mayor capacidad
  long long promedio = ((long long)a + b) / 2;

  // Opcion 2: Formular sin riesgo de overflow
  int promedio = a + (b - a) / 2;
  ```

---

### `aritmetica/ejercicio_02.c`
* **Comportamiento observado**: Imprime `Porcentaje de descuento: 0.00%`.
* **Causa Raíz**: En la línea `double porcentaje = (descuento / total) * 100;`, la subexpresión `(descuento / total)` realiza una **división entera** porque `descuento` (15) y `total` (100) son variables de tipo `int`. El resultado `15 / 100` trunca a `0`. Luego `0 * 100` resulta en `0`, que se asigna a `double`.
* **Solución**: Castear al menos uno de los operandos a flotante antes de dividir:
  ```c
  double porcentaje = ((double)descuento / total) * 100.0;
  ```

---

### `aritmetica/ejercicio_03.c`
* **Comportamiento observado**: La cuenta regresiva no se detiene en 0, pasa de 0 a 4294967295 e interrumpe por la salvaguarda.
* **Causa Raíz**: La variable de control `i` fue declarada como `unsigned int`. La condición de parada del bucle es `i >= 0`. Dado que los números `unsigned` jamás pueden ser negativos, cuando `i` vale `0` y se ejecuta `i--`, ocurre un **Underflow** que lleva a `i` al valor `UINT_MAX` (4294967295), cumpliendo siempre `i >= 0`.
* **Solución**: Usar `int` con signo o cambiar la estructura del bucle:
  ```c
  for (int i = 5; i >= 0; i--) { ... }
  ```

---

### `aritmetica/ejercicio_04.c`
* **Comportamiento observado**: El bucle no se detiene al llegar a 1.0 y requiere la salvaguarda de seguridad para interrumpirse.
* **Causa Raíz**: En el estándar IEEE 754 de 32 bits (`float`), el literal `0.1f` no posee una representación binaria exacta. Al acumular `x += 0.1f`, `x` jamás adopta exactamente el valor `1.0f` (pasa por ejemplo de `0.99999994` a `1.0999999`). Por lo tanto, la condición `x != 1.0f` nunca se evalúa como falsa.
* **Solución**: Utilizar comparaciones por desigualdad (`<`) o usar iteraciones enteras:
  ```c
  for (int i = 0; i < 10; i++) {
      float x = i * 0.1f;
      // ...
  }
  ```

---

### `aritmetica/ejercicio_05.c`
* **Comportamiento observado**: Imprime `El numero 4 es Impar` (incorrecto).
* **Causa Raíz**: En C, el operador de igualdad `==` posee mayor precedencia que el operador a nivel de bits `&`. La línea `if (numero & 1 == 0)` se evalúa en realidad como `if (numero & (1 == 0))`. Como `(1 == 0)` es falso (`0`), la expresión resulta en `4 & 0`, que da `0` (falso), ejecutando el bloque `else`.
* **Solución**: Envolver la operación de bits entre paréntesis:
  ```c
  if ((numero & 1) == 0) { ... }
  ```

---

## 2. Condicionales

### `control/condicionales/ejercicio_01.c`
* **Comportamiento observado**: Imprime `Edad 70: Persona en edad laboral` (incorrecto).
* **Causa Raíz**: En C, la sintaxis encadenada `18 <= edad <= 65` no funciona como en matemáticas. Se evalúa de izquierda a derecha: `(18 <= 70)` evalúa a `1` (verdadero). Luego se evalúa `1 <= 65`, que también resulta `1` (verdadero). Por ende, la condición se cumple para **cualquier** edad mayor o igual a 18 (incluso 100 o 1000).
* **Solución**: Separar mediante el operador lógico `&&`:
  ```c
  if (18 <= edad && edad <= 65) { ... }
  ```

---

### `control/condicionales/ejercicio_02.c`
* **Comportamiento observado**: Otorga acceso aunque `es_admin` valía 0, y cambia su valor a 1.
* **Causa Raíz**: En la línea `if (es_admin = 1)`, se utilizó el operador de asignación `=` en lugar del operador de comparación `==`. Se asigna `1` a `es_admin` y la condición toma el valor de esa expresión (`1`), resultando siempre verdadera.
* **Solución**: Utilizar `==`:
  ```c
  if (es_admin == 1) { ... }
  ```

---

### `control/condicionales/ejercicio_03.c`
* **Comportamiento observado**: Para `nivel_acceso = 1` imprime tanto `Lectura` como `Edicion`.
* **Causa Raíz**: En `case 1:`, falta la sentencia `break;` al final. Esto produce un **Fall-through** (caída en cascada), ejecutando también las instrucciones del `case 2:`.
* **Solución**: Incluir `break;` en todos los casos que lo requieran:
  ```c
  case 1:
      printf("  - Lectura de contenido\n");
      break;
  ```

---

### `control/condicionales/ejercicio_04.c`
* **Comportamiento observado**: Imprime `Elemento encontrado en el indice: -1` cuando el elemento buscado **no** está en el arreglo.
* **Causa Raíz**: La función `buscar_posicion` devuelve `-1` cuando no encuentra el elemento. Al evaluar `if (pos)`, en C cualquier entero distinto de cero (`-1`) se evalúa como **VERDADERO** (`true`). El condicional interpreta `-1` como verdadero y ejecuta el bloque de éxito.
* **Solución**: Comparar explícitamente contra el valor de error o con `>= 0`:
  ```c
  if (pos != -1) { // o pos >= 0
      printf("Elemento encontrado en el indice: %d\n", pos);
  } else {
      printf("Elemento no encontrado en el arreglo.\n");
  }
  ```


---

## 3. Lazos

### `control/lazos/ejercicio_01.c`
* **Comportamiento observado**: Ocurre un fallo de segmentación (*Segmentation Fault*) o corrupción de memoria no detectable.
* **Causa Raíz**: La matriz es de `3x3` (índices validos `0, 1, 2`). El lazo interno utiliza `j <= 3`, lo que intenta escribir en `matriz[i][3]`. Al acceder al cuarto elemento de la fila, sobrepasa el límite del arreglo (Off-by-one / Buffer Overflow).
* **Solución**: Cambiar la condición a estricta `<`:
  ```c
  for (int j = 0; j < 3; j++) { ... }
  ```

---

### `control/lazos/ejercicio_02.c`
* **Comportamiento observado**: El programa queda tildado/bloqueado sin imprimir nada.
* **Causa Raíz**: La línea `while (contador < 5);` posee un **punto y coma al final**. Esto convierte a la instrucción en un bucle con cuerpo vacío `while (contador < 5) {}`. Como `contador` no se incrementa dentro de ese cuerpo vacío, el programa se congela en un bucle infinito en esa misma línea.
* **Solución**: Eliminar el punto y coma final:
  ```c
  while (contador < 5) {
      printf("  contador = %d\n", contador);
      contador++;
  }
  ```

---

### `control/lazos/ejercicio_03.c`
* **Comportamiento observado**: El bucle se congela y requiere la interrupción de seguridad.
* **Causa Raíz**: Al evaluar `valores[1]` que vale `-5` (negativo), la condición `if (valores[i] < 0)` ejecuta `i--`. En el siguiente paso del `for`, el incremento de la cabecera ejecuta `i++`. Esto deja a `i` atrapado en el índice `1` infinitamente.
* **Solución**: No modificar manualmente la variable de iteración dentro del cuerpo de un lazo `for`.

---

## 4. Saltos

### `control/saltos/ejercicio_01.c`
* **Comportamiento observado**: Sigue evaluando las filas de la matriz luego de haber encontrado el elemento buscado `99`.
* **Causa Raíz**: La sentencia `break;` solo interrumpe el lazo `for` más interno (el de las columnas `j`). El lazo exterior (`i`) continúa ejecutándose en las filas siguientes (`i = 2`).
* **Solución**: Usar una bandera en la condición del lazo externo o un retorno de función:
  ```c
  for (int i = 0; i < 3 && !encontrado; i++) {
      for (int j = 0; j < 3; j++) {
          if (matriz[i][j] == buscado) {
              encontrado = 1;
              break;
          }
      }
  }
  ```

---

### `control/saltos/ejercicio_02.c`
* **Comportamiento observado**: El bucle se cuelga en `i = 0` y salta por la salvaguarda de seguridad.
* **Causa Raíz**: En la primera iteración, `i` vale `0`. La condición `i % 2 == 0` es verdadera, por lo que se ejecuta `continue;`. La sentencia `continue` salta directamente al inicio del `while`, omitiendo la instrucción `i++` ubicada al final. Como `i` sigue valiendo `0`, el lazo entra en un bucle infinito.
* **Solución**: Asegurar que la variable de control se incremente antes del `continue` o transformar el bucle a un `for`:
  ```c
  for (int i = 0; i < 5; i++) {
      if (i % 2 == 0) continue;
      printf("  Impar: %d\n", i);
  }
  ```
