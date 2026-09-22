/*
 * Caso: reservar un arreglo con calloc para obtener almacenamiento
 * inicializado en cero antes de modificar algunos elementos.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const size_t cantidad = 4;
    int *contadores = calloc(cantidad, sizeof *contadores);

    if (contadores == NULL)
    {
        fprintf(stderr, "no se pudo reservar el arreglo\n");
        return EXIT_FAILURE;
    }

    contadores[1] = 7;
    for (size_t i = 0; i < cantidad; i++)
    {
        printf("contadores[%zu] = %d\n", i, contadores[i]);
    }

    free(contadores);
    return EXIT_SUCCESS;
}
