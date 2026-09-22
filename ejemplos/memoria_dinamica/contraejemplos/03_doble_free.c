/*
 * Contraejemplo: liberar dos veces el mismo bloque no es una operación
 * válida y puede corromper el allocator o abortar el proceso.
 */

#include <stdlib.h>

int main(void)
{
    int *valor = malloc(sizeof *valor);
    if (valor == NULL)
    {
        return EXIT_FAILURE;
    }

    free(valor);
    free(valor);
    return EXIT_SUCCESS;
}
