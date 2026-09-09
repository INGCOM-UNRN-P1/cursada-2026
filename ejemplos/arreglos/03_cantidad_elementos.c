/* 03_cantidad_elementos.c
 *
 * Esta expresión es una de las herramientas fundamentales de C:
 *
 *     sizeof(arreglo) / sizeof(arreglo[0])
 *
 * El tamaño total dividido por el tamaño de una celda nos da la cantidad
 * de elementos del arreglo.
 */

#include <stdio.h>

int main(void)
{
    int arreglo[10] = {};

    size_t largo = sizeof(arreglo) / sizeof(arreglo[0]);

    printf("Cantidad de elementos: %zu\n", largo);

    return 0;
}
