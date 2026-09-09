#include <stdio.h>

/*
 * SITUACION (BUG): Unsigned Integer Underflow / Wraparound.
 * EXPLICACION: Restar 1 a un unsigned int con valor 0 no produce un numero negativo ni da error;
 * envuelve el valor directamente a UINT_MAX (4294967295 en sistemas de 32 bits).
 */

int main(void) {
    // BUG: Restar un valor mayor a un unsigned int produce wraparound (underflow) a UINT_MAX
    unsigned int cero = 0;
    printf("[BUG] Unsigned 0 - 1 (Underflow): %u\n", cero - 1);
    return 0;
}
