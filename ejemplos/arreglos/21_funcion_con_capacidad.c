/* 21_funcion_con_capacidad.c
 *
 * La función necesita recibir explícitamente la capacidad.
 *
 * Esta es la forma que vamos a adoptar durante la clase:
 *
 *     funcion(arreglo, capacidad)
 */

#include <stddef.h>
#include <stdio.h>

/**
 * @brief Descripción de la función imprimir_arreglo.
 *
 * @param arreglo Descripción del parámetro arreglo.
 * @param capacidad Descripción del parámetro capacidad.
 */
void imprimir_arreglo(const int arreglo[], size_t capacidad)
{
    for (size_t i = 0; i < capacidad; i++)
    {
        printf("%d ", arreglo[i]);
    }

    printf("\n");
}

int main(void)
{
    int arreglo[] = {10, 20, 30, 40, 50};

    size_t capacidad = sizeof(arreglo) / sizeof(arreglo[0]);

    imprimir_arreglo(arreglo, capacidad);

    return 0;
}
