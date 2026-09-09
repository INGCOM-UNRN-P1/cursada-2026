/* 18_arr1_no_es_arr2.c
 *
 * Los arreglos no se pueden asignar mediante el operador =.
 * No podemos escribir arr1 = arr2.
 *
 * Este programa NO debe compilar.
 */

#include <stdio.h>

int main(void)
{
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {10, 20, 30, 40, 50};

    /* ERROR DE COMPILACION INTENCIONAL */
    arr1 = arr2;

    return 0;
}
