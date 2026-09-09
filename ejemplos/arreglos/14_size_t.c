/* 14_size_t.c
 *
 * Las variables que representan tamaños o índices deben ser size_t.
 * Esto hace explícita la relación entre la variable y el tamaño de memoria.
 */

#include <stddef.h>
#include <stdio.h>

int main(void)
{
    int arreglo[10] = {};

    size_t largo = sizeof(arreglo) / sizeof(arreglo[0]);

    for (size_t indice = 0; indice < largo; indice++)
    {
        printf("indice = %zu\n", indice);
    }

    return 0;
}
