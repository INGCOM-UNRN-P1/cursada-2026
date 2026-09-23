/*
 * vasquez: la segunda reserva verifica NULL, pero al abandonar no libera la
 * primera.El camino feliz no pierde memoria; el camino de error sí.Solo se
 * observa forzando el fallo de la segunda llamada a malloc.vasquez da el
 * escenario por manejado (no hay caída), pero advierte la reserva previa sin
 * liberar en la rama de error.
 *
 *   vasquez inject
 * memoria_dinamica/diagnostico/05_fuga_en_camino_de_error.c--fail-malloc-at 2
 * --check-leaks
 *
 * La versión correcta es robustos/02_cleanup_contra_error.c.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *primero = malloc(3 * sizeof *primero);
    if (primero == NULL)
    {
        return EXIT_FAILURE;
    }

    int *segundo = malloc(4 * sizeof *segundo);
    if (segundo == NULL)
    {
        /* Error: primero queda sin liberar. */
        return EXIT_FAILURE;
    }

    primero[0] = 10;
    segundo[0] = 20;
    printf("%d %d\n", primero[0], segundo[0]);
    free(segundo);
    free(primero);
    return EXIT_SUCCESS;
}
