/* Los parametros de salida permiten devolver mas de un resultado. */

#include <stdio.h>

/**
 * @brief Descripción de la función dividir.
 *
 * @param dividendo Descripción del parámetro dividendo.
 * @param divisor Descripción del parámetro divisor.
 * @param cociente Descripción del parámetro cociente.
 * @param resto Descripción del parámetro resto.
 */
void dividir(int dividendo, int divisor, int *cociente, int *resto)
{
    *cociente = dividendo / divisor;
    *resto = dividendo % divisor;
}

int main(void)
{
    int cociente;
    int resto;

    dividir(17, 5, &cociente, &resto);
    printf("cociente = %d, resto = %d\n", cociente, resto);

    return 0;
}
