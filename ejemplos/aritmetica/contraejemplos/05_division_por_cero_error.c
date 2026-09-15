#include <stdio.h>

/*
 * SITUACION (BUG): Division por cero en punto flotante sin chequeo.
 * EXPLICACION: Dividir 1.0 / 0.0 en IEEE 754 genera inf (infinito) sin lanzar
 * excepcion de runtime, lo que propaga valores invalidos en los calculos
 * subsiguientes sin ser detectado a tiempo.
 */

int main(void)
{
    // BUG: División por cero flotante produce inf o NaN sin lanzar excepción
    double div_cero = 1.0 / 0.0;
    printf("[BUG] 1.0 / 0.0 produce: %f\n", div_cero);
    return 0;
}
