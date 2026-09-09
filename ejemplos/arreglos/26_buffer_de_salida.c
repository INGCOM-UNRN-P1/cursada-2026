/* 26_buffer_de_salida.c
 *
 * Una función no debe intentar retornar un arreglo local.
 * El llamador reserva el destino y se lo entrega a la función.
 *
 * Este patrón introduce el concepto de buffer de salida.
 */

#include <stddef.h>
#include <stdio.h>

/**
 * @brief Descripción de la función cuadrados.
 *
 * @param entrada Descripción del parámetro entrada.
 * @param salida Descripción del parámetro salida.
 * @param capacidad Descripción del parámetro capacidad.
 */
void cuadrados(const int entrada[], int salida[], size_t capacidad)
{
    for (size_t i = 0; i < capacidad; i++)
    {
        salida[i] = entrada[i] * entrada[i];
    }
}

int main(void)
{
    int entrada[] = {1, 2, 3, 4, 5};
    int salida[5] = {};

    size_t capacidad = sizeof(entrada) / sizeof(entrada[0]);

    cuadrados(entrada, salida, capacidad);

    for (size_t i = 0; i < capacidad; i++)
    {
        printf("%d ", salida[i]);
    }

    printf("\n");

    return 0;
}
