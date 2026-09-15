/* 02_sizeof_arreglo.c
 *
 * Ahora pasamos de un elemento individual a un arreglo.
 * sizeof(arreglo) mide todo el bloque reservado, no solamente un elemento.
 */

#include <stdio.h>

int main(void)
{
    int arreglo[8] = {};
    size_t largo = sizeof(arreglo);
    printf("sizeof(int) = %zu bytes\n", sizeof(int));
    printf("sizeof(arreglo) = %zu bytes\n", sizeof(arreglo));
    printf("cantidad de elementos = %zu\n",
           sizeof(arreglo) / sizeof(arreglo[0]));

    return 0;
}
