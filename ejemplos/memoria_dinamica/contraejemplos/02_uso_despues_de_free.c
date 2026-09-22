/*
 * Contraejemplo: desreferenciar un puntero después de free produce
 * comportamiento indefinido; sirve para identificar un use-after-free.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *valor = malloc(sizeof *valor);
    if (valor == NULL)
    {
        return EXIT_FAILURE;
    }

    *valor = 10;
    free(valor);
    printf("%d\n", *valor);
    return EXIT_SUCCESS;
}
