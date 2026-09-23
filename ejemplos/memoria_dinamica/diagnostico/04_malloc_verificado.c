/*
 * vasquez: la misma lógica que 03_malloc_sin_verificar.c, pero verificando
 * el resultado de malloc.Bajo inyección de fallos el programa termina de
 * forma controlada con EXIT_FAILURE en lugar de caerse.
 *
 *   vasquez inject
 * memoria_dinamica/diagnostico/04_malloc_verificado.c--fail-malloc-at 1
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t cantidad = 5;
    int *cuadrados = malloc(cantidad * sizeof *cuadrados);
    if (cuadrados == NULL)
    {
        fprintf(stderr, "Sin memoria para %zu enteros\n", cantidad);
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < cantidad; i++)
    {
        cuadrados[i] = (int)(i * i);
    }

    printf("%d\n", cuadrados[cantidad - 1]);
    free(cuadrados);
    return EXIT_SUCCESS;
}
