/*
 * Caso: centralizar la liberación de recursos en una salida de cleanup,
 * de modo que cada reserva realizada se libere también ante un error.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int resultado = EXIT_FAILURE;
    int *primero = NULL;
    int *segundo = NULL;

    primero = malloc(3 * sizeof *primero);
    if (primero == NULL)
    {
        goto cleanup;
    }

    segundo = malloc(4 * sizeof *segundo);
    if (segundo == NULL)
    {
        goto cleanup;
    }

    primero[0] = 10;
    segundo[0] = 20;
    printf("%d %d\n", primero[0], segundo[0]);
    resultado = EXIT_SUCCESS;

cleanup:
    free(segundo);
    free(primero);
    return resultado;
}
