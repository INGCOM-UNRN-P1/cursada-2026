/*
 * Contraejemplo: asignar realloc directamente al único puntero puede
 * perder el bloque original si la ampliación falla.
 */

#include <stdlib.h>

int main(void)
{
    int *valores = malloc(2 * sizeof *valores);
    if (valores == NULL)
    {
        return EXIT_FAILURE;
    }

    valores = realloc(valores, 1000000000000ULL * sizeof *valores);
    if (valores == NULL)
    {
        return EXIT_FAILURE;
    }

    free(valores);
    return EXIT_SUCCESS;
}
