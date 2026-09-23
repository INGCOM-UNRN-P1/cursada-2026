/*
 * Caso: construir un vector que crece cuando se agota su capacidad,
 * conservando los elementos existentes y liberando el bloque final.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t capacidad = 2;
    size_t cantidad = 0;
    int *vector = malloc(capacidad * sizeof *vector);

    if (vector == NULL)
    {
        return EXIT_FAILURE;
    }

    for (int valor = 10; valor <= 50; valor += 10)
    {
        if (cantidad == capacidad)
        {
            capacidad *= 2;
            int *temporal = realloc(vector, capacidad * sizeof *vector);
            if (temporal == NULL)
            {
                free(vector);
                return EXIT_FAILURE;
            }
            vector = temporal;
        }
        vector[cantidad++] = valor;
    }

    for (size_t i = 0; i < cantidad; i++)
    {
        printf("%d%c", vector[i], i + cantidad == 1 ? '\n' : ' ');
    }

    free(vector);
    return EXIT_SUCCESS;
}
