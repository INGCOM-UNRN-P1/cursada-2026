/*
 * Caso: calcular el tamaño de una reserva a partir del objeto apuntado,
 * evitando repetir el tipo y reduciendo errores al cambiar su declaración.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double *mediciones = malloc(3 * sizeof *mediciones);

    if (mediciones == NULL)
    {
        return EXIT_FAILURE;
    }

    mediciones[0] = 1.5;
    mediciones[1] = 2.5;
    mediciones[2] = 3.5;
    printf("%.1f %.1f %.1f\n", mediciones[0], mediciones[1], mediciones[2]);

    free(mediciones);
    return EXIT_SUCCESS;
}
