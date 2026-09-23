/*
 * vasquez: el programa funciona mientras malloc tiene éxito, pero no
 * verifica el resultado. Con vasquez se fuerza que malloc devuelva NULL y el
 * error latente aparece como una caída (SIGSEGV).
 *
 *   gcc -std=c11 -g memoria_dinamica/diagnostico/03_malloc_sin_verificar.c -o /tmp/sin_verificar
 *   nostromo run /tmp/sin_verificar             # 16: sin fallos, parece correcto
 *   vasquez inject memoria_dinamica/diagnostico/03_malloc_sin_verificar.c --fail-malloc-at 1
 *
 * No usar 'hal check --fail-malloc-at': en hal 0.1.0 la inyección alcanza
 * también a GDB y hal consume memoria sin límite (más de 12 GB).
 *
 * Comparar con 04_malloc_verificado.c.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t cantidad = 5;
    int *cuadrados = malloc(cantidad * sizeof *cuadrados);

    for (size_t i = 0; i < cantidad; i++)
    {
        cuadrados[i] = (int)(i * i);
    }

    printf("%d\n", cuadrados[cantidad - 1]);
    free(cuadrados);
    return EXIT_SUCCESS;
}
