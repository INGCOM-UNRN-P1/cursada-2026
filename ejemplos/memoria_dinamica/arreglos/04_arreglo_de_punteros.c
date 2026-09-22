/*
 * Caso: reservar filas de longitudes independientes mediante un arreglo
 * de punteros y liberar primero cada fila y luego el arreglo de punteros.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const size_t longitudes[] = {2, 4, 3};
    const size_t filas = sizeof longitudes / sizeof longitudes[0];
    int **matriz = malloc(filas * sizeof *matriz);

    if (matriz == NULL)
    {
        return EXIT_FAILURE;
    }

    for (size_t fila = 0; fila < filas; fila++)
    {
        matriz[fila] = malloc(longitudes[fila] * sizeof *matriz[fila]);
        if (matriz[fila] == NULL)
        {
            while (fila > 0)
            {
                free(matriz[--fila]);
            }
            free(matriz);
            return EXIT_FAILURE;
        }
        for (size_t columna = 0; columna < longitudes[fila]; columna++)
        {
            matriz[fila][columna] = (int)(fila + columna);
        }
    }

    for (size_t fila = 0; fila < filas; fila++)
    {
        for (size_t columna = 0; columna < longitudes[fila]; columna++)
        {
            printf("%d ", matriz[fila][columna]);
        }
        putchar('\n');
        free(matriz[fila]);
    }
    free(matriz);

    return EXIT_SUCCESS;
}
