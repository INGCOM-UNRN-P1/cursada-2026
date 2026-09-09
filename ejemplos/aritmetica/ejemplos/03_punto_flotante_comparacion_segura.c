#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
 * SITUACION: Comparacion segura de numeros en punto flotante.
 * EXPLICACION: Debido a la representacion IEEE 754, los flotantes sufren imprecisiones binarias.
 * En lugar de usar '==', se verifica que el valor absoluto de la diferencia sea menor que un margen de tolerancia (EPSILON).
 */

#define EPSILON 1e-9

bool son_iguales_double(double a, double b) {
    return fabs(a - b) < EPSILON;
}

int main(void) {
    double a = 0.1 + 0.2;
    double b = 0.3;

    if (son_iguales_double(a, b)) {
        printf("0.1 + 0.2 es aproximadamente igual a 0.3 (Diferencia < %e)\n", EPSILON);
    }
    return 0;
}
