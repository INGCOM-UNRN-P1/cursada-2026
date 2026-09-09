/* 16_escritura_fuera_de_limites.c
 *
 * Leer fuera de límites ya es un error.
 * Escribir fuera de límites puede corromper memoria.
 *
 * Este ejemplo existe exclusivamente para discutir el problema.
 */

#include <stdio.h>

int main(void)
{
    int arreglo[5] = {10, 20, 30, 40, 50};

    /* ERROR INTENCIONAL */
    arreglo[10] = 1234;

    for(size_t i = 0; ;i++)
    {
        arreglo[i] = 1234;
        printf("arreglo[%zu] = %d\n",i,  arreglo[i]);
    }
    printf("El programa no tiene un resultado definido.\n");

    return 0;
}
