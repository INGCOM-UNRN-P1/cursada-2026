#include <stdio.h>
#include <stdbool.h>

/*
 * SITUACION: Prevencion de Underflow en enteros sin signo (unsigned int).
 * EXPLICACION: Los tipos unsigned en C implementan aritmetica modular. Si el resultado es negativo,
 * la variable 'envuelve' hacia UINT_MAX. Se valida previa resta que el sustraendo no supere al minuendo.
 */

// Detección previa de underflow en resta de enteros unsigned
bool restar_seguro_unsigned(unsigned int a, unsigned int b, unsigned int *resultado) {
    if (b > a) {
        return false;
    }
    *resultado = a - b;
    return true;
}

int main(void) {
    unsigned int res = 0;
    unsigned int a = 5, b = 10;

    if (restar_seguro_unsigned(a, b, &res)) {
        printf("Resta exitosa: %u\n", res);
    } else {
        printf("Underflow prevenido: %u - %u resultaria negativo en unsigned.\n", a, b);
    }
    return 0;
}
