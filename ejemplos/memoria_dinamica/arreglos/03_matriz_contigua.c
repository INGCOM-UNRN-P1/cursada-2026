/*
 * Caso: representar una matriz dinámica como un único bloque contiguo,
 * traduciendo fila y columna a fila * columnas + columna.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const size_t filas = 2;
    const size_t columnas = 3;
    int *matriz = malloc(filas * columnas * sizeof *matriz);

    if (matriz == NULL)
    {
        return EXIT_FAILURE;
    }

    for (size_t fila = 0; fila < filas; fila++)
    {
        for (size_t columna = 0; columna < columnas; columna++)
        {
            matriz[fila * columnas + columna] = (int)(fila * 10 + columna);
            printf("%d ", matriz[fila * columnas + columna]);
        }
        putchar('\n');
    }

    free(matriz);
    return EXIT_SUCCESS;
}
