/*
 * vasquez: malloc no inicializa el bloque.Muchas veces el contenido previo
 * es cero y el error pasa inadvertido.Con--garbage-memory vasquez rellena
 * cada bloque con 0xA5 y el contador muestra un valor claramente basura:
 * 0xA5A5A5A5 + 1 = -1515870810. La salida del programa aparece en el campo
 * "stdout" del reporte JSON.
 *
 *   vasquez inject
 * memoria_dinamica/diagnostico/07_lectura_sin_inicializar.c--garbage-memory--json
 *
 * Comparar con fundamentos/03_calloc_inicializa_cero.c.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t cantidad = 4;
    int *contadores = malloc(cantidad * sizeof *contadores);
    if (contadores == NULL)
    {
        return EXIT_FAILURE;
    }

    /* Error: se incrementa sin haber puesto los contadores en cero. */
    for (size_t i = 0; i < cantidad; i++)
    {
        contadores[i]++;
    }

    printf("%d\n", contadores[0]);
    free(contadores);
    return EXIT_SUCCESS;
}
