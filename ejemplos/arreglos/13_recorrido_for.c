/* 13_recorrido_for.c
 *
 * El patrón fundamental para procesar un arreglo:
 *
 *     size_t i = 0;
 *     i < largo;
 *     i++
 *
 * Nunca debemos recorrer hasta <= largo.
 */

#include <stdio.h>

int main(void)
{
    int arreglo[10] = {};

    size_t largo = sizeof(arreglo) / sizeof(arreglo[0]);

    for (size_t i = 0; i < largo; i++)
    {
        arreglo[i] = (int)(i * i);
    }

    for (size_t i = 0; i < largo; i++)
    {
        printf("%zu -> %d\n", i, arreglo[i]);
    }

    return 0;
}
