/* 23_maximo_sin_modificar.c
 *
 * Si una función solamente inspecciona el arreglo,
 * debemos declararlo const.
 *
 * Además, usamos una variable auxiliar para no modificar el dato original.
 */

#include <stddef.h>
#include <stdio.h>

/**
 * @brief Descripción de la función maximo.
 *
 * @param arreglo Descripción del parámetro arreglo.
 * @param largo Descripción del parámetro largo.
 * @return Descripción del valor de retorno.
 */
int maximo(const int arreglo[], size_t largo)
{
    int max = arreglo[0];

    for (size_t i = 1; i < largo; i++)
    {
        if (arreglo[i] > max)
        {
            max = arreglo[i];
        }
    }

    return max;
}

int main(void)
{
    int arreglo[] = {7, 3, 12, 5, 9};

    size_t largo = sizeof(arreglo) / sizeof(arreglo[0]);

    printf("Maximo: %d\n", maximo(arreglo, largo));

    printf("Primer elemento original: %d\n", arreglo[0]);

    return 0;
}
