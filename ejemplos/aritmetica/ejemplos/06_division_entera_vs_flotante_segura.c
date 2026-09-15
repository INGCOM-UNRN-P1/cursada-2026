#include <stdio.h>

/*
 * SITUACION: Division flotante explicita entre enteros.
 * EXPLICACION: En C, si ambos operandos son enteros, la division trunca los
 * decimales.Se aplica casteo explicito (double) en al menos uno de los
 * operandos para forzar el resultado flotante.
 */

int main(void)
{
    int a = 5;
    int b = 2;

    // Casteo explicito para forzar division flotante
    double resultado = (double)a / b;
    printf("Division flotante con casteo: %d / %d = %.1f\n", a, b, resultado);
    return 0;
}
