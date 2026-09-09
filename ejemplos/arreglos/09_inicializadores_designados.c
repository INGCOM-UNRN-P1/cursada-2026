/* 09_inicializadores_designados.c
 *
 * Desde C99 podemos especificar directamente qué índice queremos inicializar.
 * Los elementos no indicados quedan en cero.
 */

#include <stdio.h>

int main(void)
{
    int designada[5] = {[0] = 10, [4] = 50};

    for (size_t i = 0; i < sizeof(designada) / sizeof(designada[0]); i++)
    {
        printf("designada[%zu] = %d\n", i, designada[i]);
    }

    return 0;
}
