/* 17_variable_no_inicializada.c
 *
 * Otro ejemplo de comportamiento indefinido:
 * una variable automática local no inicializada no tiene un valor
 * que podamos utilizar legítimamente.
 */

#include <stdio.h>

int main(void)
{
    int x;

    /* ERROR INTENCIONAL */
    printf("%d\n", x);

    return 0;
}
