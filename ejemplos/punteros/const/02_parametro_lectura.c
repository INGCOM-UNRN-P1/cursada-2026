/* const en un parametro documenta que la funcion solo lee el objeto. */

#include <stdio.h>

/**
 * @brief Descripción de la función sumar.
 *
 * @param valores Descripción del parámetro valores.
 * @param cantidad Descripción del parámetro cantidad.
 * @return Descripción del valor de retorno.
 */
int sumar(const int *valores, size_t cantidad)
{
    int total = 0;

    for (size_t i = 0; i < cantidad; i++)
    {
        total += valores[i];
    }

    return total;
}

int main(void)
{
    const int valores[] = {2, 4, 6};

    printf("suma = %d\n", sumar(valores, 3));

    return 0;
}
