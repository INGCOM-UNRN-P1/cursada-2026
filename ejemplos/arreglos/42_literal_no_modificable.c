/* 42_literal_no_modificable.c
 *
 * Una cadena literal no debe utilizarse como buffer modificable.
 *
 * El siguiente ejemplo es DELIBERADAMENTE INCORRECTO.
 * Según el estándar, intentar modificar un literal tiene comportamiento
 * indefinido.
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
    /* ERROR CONCEPTUAL INTENCIONAL */
    modificar("juan");

    return 0;
}
