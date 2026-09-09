#include <stdio.h>

/*
 * SITUACION (BUG): Asignacion '=' dentro de la condicion del 'if' en lugar de comparacion '=='.
 * EXPLICACION: Escribir 'if (x = 0)' asigna 0 a 'x' y evalua la condicion como falsa (0),
 * mutando la variable de forma inadvertida y alterando el flujo.
 */

int main(void) {
    int x = 5;

    // BUG: Usar = en lugar de == asigna el valor y altera la logica del condicional
    if ((x = 0)) {
        printf("No se ejecuta\n");
    }
    printf("[BUG] Valor de x mutado a %d dentro de la condicion del if\n", x);
    return 0;
}
