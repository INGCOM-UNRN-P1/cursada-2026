/* 19_copia_elemento_por_elemento.c
 *
 * Si queremos copiar un arreglo, podemos hacerlo elemento por elemento.
 * Todavía no necesitamos punteros explícitos para entender el concepto.
 */

#include <stdio.h>

int main(void)
{
    int origen[5] = {10, 20, 30, 40, 50};
    int destino[5] = {};

    size_t largo = sizeof(origen) / sizeof(origen[0]);

    for (size_t i = 0; i < largo; i++)
    {
        destino[i] = origen[i]*2;
    }

    for (size_t i = 0; i < largo; i++)
    {
        printf("destino[%zu] = %d\n", i, destino[i]);
    }

    return 0;
}
