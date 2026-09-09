#include <stdio.h>
#include <limits.h>

/*
 * SITUACION (BUG): Signed Integer Overflow.
 * EXPLICACION: Sumar 1 a INT_MAX causa Comportamiento Indefinido (Undefined Behavior) segun el estandar C.
 * El compilador puede optimizar o asumir que este desbordamiento nunca ocurre, generando resultados impredecibles.
 */

int main(void) {
    // BUG: Integer Overflow en signed int es Comportamiento Indefinido (Undefined Behavior)
    int max_int = INT_MAX;
    printf("[BUG] INT_MAX: %d\n", max_int);
    printf("[BUG] INT_MAX + 1: %d\n", max_int + 1);
    return 0;
}
