/* Un puntero a puntero agrega un nivel de indirección. */

#include <stdio.h>

int main(void)
{
    int valor = 10;
    int *puntero = &valor;
    int **puntero_a_puntero = &puntero;

    **puntero_a_puntero = 25;
    printf("valor = %d\n", valor);
    printf("**puntero_a_puntero = %d\n", **puntero_a_puntero);

    return 0;
}
