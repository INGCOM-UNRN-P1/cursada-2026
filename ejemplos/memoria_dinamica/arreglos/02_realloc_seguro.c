/*
 * Caso: reducir un arreglo dinámico usando un puntero temporal, porque
 * sobrescribir el puntero original antes de comprobar realloc puede perderlo.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t cantidad = 6;
    int *valores = malloc(cantidad * sizeof *valores);

    if (valores == NULL)
    {
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < cantidad; i++)
    {
        valores[i] = (int)i;
    }

    cantidad = 3;
    int *temporal = realloc(valores, cantidad * sizeof *valores);
    if (temporal == NULL)
    {
        free(valores);
        return EXIT_FAILURE;
    }
    valores = temporal;

    for (size_t i = 0; i < cantidad; i++)
    {
        printf("%d%c", valores[i], i + cantidad == 1 ? '\n' : ' ');
    }

    free(valores);
    return EXIT_SUCCESS;
}
