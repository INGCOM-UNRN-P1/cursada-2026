/* 12_lvalue.c
 *
 * La misma expresión puede identificar una celda como destino.
 * Del lado izquierdo de una asignación funciona como L-value.
 */

#include <stdio.h>

int main(void)
{
    int edades[4] = {20, 25, 22, 28};

    printf("Edad tres: %d\n", edades[2]);

    edades[2] = 23;

    printf("Nueva edad tres: %d\n", edades[2]);

    return 0;
}
