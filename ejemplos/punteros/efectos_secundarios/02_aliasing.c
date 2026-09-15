/* Dos punteros pueden ser alias: modifican el mismo objeto. */

#include <stdio.h>

int main(void)
{
    int valor = 7;
    int *primero = &valor;
    int *segundo = &valor;

    *primero = 12;
    printf("a traves de segundo = %d\n", *segundo);

    *segundo += 3;
    printf("a traves de valor = %d\n", valor);

    return 0;
}
