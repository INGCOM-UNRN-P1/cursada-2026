/* En una expresion, el nombre del arreglo se convierte en puntero al primer
 * elemento. */

#include <stdio.h>

int main(void)
{
    int notas[] = {6, 8, 10};
    int *inicio = notas;

    for (size_t i = 0; i < sizeof(notas) / sizeof(notas[0]); i++)
    {
        printf("notas[%zu] = %d, *(inicio + %zu) = %d\n", i, notas[i], i,
               *(inicio + i));
    }

    return 0;
}
