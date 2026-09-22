/* 04_heap_dinamico.c
 *
 * La memoria reservada con malloc proviene del heap, un segmento
 * independiente de la pila y de las variables globales. A diferencia
 * de una variable local, sobrevive hasta que se llama a free.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *valor = malloc(sizeof *valor);

    if (valor == NULL)
    {
        return EXIT_FAILURE;
    }

    *valor = 7;
    printf("valor = %d (direccion en heap: %p)\n", *valor, (void *)valor);

    free(valor);
    return EXIT_SUCCESS;
}
