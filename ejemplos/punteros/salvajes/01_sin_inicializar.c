/* CONTRAEJEMPLO: el puntero no tiene un destino valido. NO EJECUTAR. */

#include <stdio.h>

int main(void)
{
    int *puntero;

    /* Comportamiento indefinido: el valor del puntero es indeterminado. */
    printf("%d\n", *puntero);

    return 0;
}
