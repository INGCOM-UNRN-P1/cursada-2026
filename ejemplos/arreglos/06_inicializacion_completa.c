/* 06_inicializacion_completa.c
 *
 * Podemos proporcionar todos los elementos explícitamente.
 * La posición 0 recibe el primer valor, la posición 1 el segundo, etc.
 */

#include <stdio.h>

int main(void)
{
    int completa[5] = {1, 2, 3, 4, 5};

    for (size_t i = 0; i < sizeof(completa) / sizeof(completa[0]); i++)
    {
        printf("completa[%zu] = %d\n", i, completa[i]);
    }

    return 0;
}
