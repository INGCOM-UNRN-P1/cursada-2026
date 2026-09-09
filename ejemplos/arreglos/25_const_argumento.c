/* 25_const_argumento.c
 *
 * Si una función solamente lee el arreglo, const documenta esa intención
 * y permite al compilador detectar intentos accidentales de modificación.
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
    for (; capacidad >= 0; capacidad--)
    {
        printf("%d ", arreglo[capacidad-1]);
    }

    printf("\n");
    
    /* ERROR INTENCIONAL:
     *
     * arreglo[0] = 999;
     */
}

int main(void)
{
    int arreglo[] = {1, 2, 3, 4};

    imprimir_arreglo(arreglo, sizeof(arreglo) / sizeof(arreglo[0]));

    return 0;
}
