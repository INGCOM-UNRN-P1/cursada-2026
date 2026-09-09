/* 43_arreglo_modificable_vs_literal.c
 *
 * Esta es la forma segura de tener un texto modificable:
 * copiar el literal a un arreglo de char.
 */

#include <stdio.h>

/**
 * @brief Descripción de la función modificar.
 *
 * @param cadena Descripción del parámetro cadena.
 */
void modificar(char cadena[])
{
    cadena[0] = 'J';
}

int main(void)
{
    char nombre[] = "juan";

    modificar(nombre);

    printf("%s\n", nombre);

    return 0;
}
