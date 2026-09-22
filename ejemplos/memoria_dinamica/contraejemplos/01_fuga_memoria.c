/*
 * Contraejemplo: se pierde el único puntero al bloque reservado antes de
 * llamar a free; el programa termina con una fuga de memoria intencional.
 */

#include <stdlib.h>

int main(void)
{
    int *valor = malloc(sizeof *valor);
    if (valor == NULL)
    {
        return EXIT_FAILURE;
    }

    *valor = 10;
    valor = NULL;
    return EXIT_SUCCESS;
}
