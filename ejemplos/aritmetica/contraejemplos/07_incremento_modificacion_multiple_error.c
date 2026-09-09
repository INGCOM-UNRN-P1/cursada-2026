#include <stdio.h>

/*
 * SITUACION (BUG): Modificacion multiple de variable sin puntos de secuencia.
 * EXPLICACION: Evaluar 'i++ + ++i' modifica la variable 'i' mas de una vez en la misma expresion.
 * Esto constituye Comportamiento Indefinido (UB) en C; el resultado depende completamente del compilador.
 */

int main(void) {
    int i = 1;

    // BUG: Modificar la misma variable multiples veces en la misma expresion es UB
    int res = i++ + ++i;
    printf("[BUG / UNDEFINED BEHAVIOR] i++ + ++i = %d (i final = %d)\n", res, i);
    return 0;
}
