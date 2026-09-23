/*
 * vasquez: asignar el resultado de realloc sobre el mismo puntero pierde el
 * bloque original cuando realloc falla.Se fuerza el fallo del primer
 * realloc: vasquez informa la caída por puntero nulo y el bloque perdido.
 *
 *   gcc -std=c11 -g memoria_dinamica/diagnostico/06_realloc_sin_temporal.c -o
 * /tmp/sin_temporal nostromo run /tmp/sin_temporal              # 4: sin
 * fallos, parece correcto vasquez inject
 * memoria_dinamica/diagnostico/06_realloc_sin_temporal.c--fail-realloc-at 1
 * --check-leaks
 *
 * La versión correcta es arreglos/02_realloc_seguro.c.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t capacidad = 2;
    int *valores = malloc(capacidad * sizeof *valores);
    if (valores == NULL)
    {
        return EXIT_FAILURE;
    }

    valores[0] = 1;
    valores[1] = 2;

    capacidad = capacidad * 2;
    valores = realloc(valores, capacidad * sizeof *valores);

    valores[2] = 3;
    valores[3] = 4;
    printf("%d\n", valores[3]);
    free(valores);
    return EXIT_SUCCESS;
}
