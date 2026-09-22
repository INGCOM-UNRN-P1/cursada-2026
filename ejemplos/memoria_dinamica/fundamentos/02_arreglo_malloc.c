/*
 * Caso: reservar dinámicamente un arreglo de cinco enteros y recorrerlo
 * mediante índices dentro de la cantidad solicitada.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const size_t cantidad = 5;
    int *valores = malloc(cantidad * sizeof *valores);

    if (valores == NULL)
    {
        fprintf(stderr, "no se pudo reservar el arreglo\n");
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < cantidad; i++)
    {
        valores[i] = (int)(i + 1) * 10;
        printf("valores[%zu] = %d\n", i, valores[i]);
    }

    free(valores);
    return EXIT_SUCCESS;
}
