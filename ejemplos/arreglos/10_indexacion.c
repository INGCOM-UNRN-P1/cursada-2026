/* 10_indexacion.c
 *
 * Los índices comienzan en cero.
 * Para un arreglo de N elementos, los índices válidos son 0 ... N-1.
 */

#include <stdio.h>

int main(void)
{
    int arreglo[5] = {10, 20, 30, 40, 50};

    printf("primer elemento = %d\n", arreglo[0]);
    printf("segundo elemento = %d\n", arreglo[1]);
    printf("ultimo elemento = %d\n", arreglo[4]);

    return 0;
}
