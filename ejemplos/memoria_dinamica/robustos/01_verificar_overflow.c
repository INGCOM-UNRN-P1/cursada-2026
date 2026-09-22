/*
 * Caso: comprobar que cantidad * sizeof(elemento) no desborde size_t
 * antes de llamar a malloc con un tamaño calculado externamente.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t cantidad = 100;
    if (cantidad > SIZE_MAX / sizeof(int))
    {
        fprintf(stderr, "tamanio solicitado demasiado grande\n");
        return EXIT_FAILURE;
    }

    int *valores = malloc(cantidad * sizeof *valores);
    if (valores == NULL)
    {
        return EXIT_FAILURE;
    }

    valores[0] = 1;
    valores[cantidad - 1] = 2;
    printf("%d %d\n", valores[0], valores[cantidad - 1]);
    free(valores);

    return EXIT_SUCCESS;
}
