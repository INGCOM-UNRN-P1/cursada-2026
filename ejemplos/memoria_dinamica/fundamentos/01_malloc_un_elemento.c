/*
 * Caso: reservar espacio para un único entero, validar la reserva,
 * usar el objeto y liberar exactamente una vez su almacenamiento.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *numero = malloc(sizeof *numero);

    if (numero == NULL)
    {
        fprintf(stderr, "no se pudo reservar memoria\n");
        return EXIT_FAILURE;
    }

    *numero = 42;
    printf("numero = %d\n", *numero);
    free(numero);

    return EXIT_SUCCESS;
}
