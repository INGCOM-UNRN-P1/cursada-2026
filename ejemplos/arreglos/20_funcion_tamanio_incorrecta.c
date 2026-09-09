/* 20_funcion_tamanio_incorrecta.c
 *
 * Parece tentador encapsular sizeof en una función.
 * Pero el parámetro arreglo[] no conserva la información de capacidad.
 *
 * En un parámetro de función, el arreglo se trata como una dirección.
 */

#include <stddef.h>
#include <stdio.h>

#define MAX_ARREGLO 100

/**
 * @brief Descripción de la función largo.
 *
 * @param arreglo Descripción del parámetro arreglo.
 * @return Descripción del valor de retorno.
 */
size_t largo(int arreglo[], size_t sz_arreglo)
{
    return sizeof(arreglo) / sizeof(arreglo[0]);
}

int main(void)
{
    int arreglo[1000] = {};
    size_t longitu = largo(arreglo);

    printf("calculo : %zu\n", 
        sizeof(arreglo) / sizeof(arreglo[0]));
    printf("longitu : %zu\n", 
        longitu);
    return 0;
}
