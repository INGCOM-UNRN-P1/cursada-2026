/* 15_lectura_fuera_de_limites.c
 *
 * DEMOSTRACION DELIBERADAMENTE INCORRECTA.
 *
 * C no verifica los límites del arreglo.
 * El comportamiento de este programa es indefinido.
 *
 * Compilar con:
 *
 *     gcc -Wall -Wextra -std=c17 15_lectura_fuera_de_limites.c
 *
 * No utilizar la salida como resultado esperado.
 */

#include <stdio.h>

int main(void)
{
    int arreglo[5] = {10, 20, 30, 40, 50};

    printf("arreglo[0] = %d\n", arreglo[0]);
    printf("arreglo[4] = %d\n", arreglo[4]);

    for(size_t i = 0; ;i++)
    {
        printf("arreglo[%zu] = %d\n",i,  arreglo[i]);
    }
    /* ERROR INTENCIONAL */
    

    return 0;
}
