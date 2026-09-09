/* 07_inicializacion_parcial.c
 *
 * Si damos menos valores que la capacidad del arreglo,
 * los elementos restantes se inicializan en cero.
 */

#include <stdio.h>

int main(void)
{
    int parcial[5] = {1, 2};

    for (size_t i = 0; i < sizeof(parcial) / sizeof(parcial[0]); i++)
    {
        printf("parcial[%zu] = %d\n", i, parcial[i]);
    }

    return 0;
}
