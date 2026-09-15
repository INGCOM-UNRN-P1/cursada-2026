/* Recibir un puntero permite que la funcion modifique una variable existente.
 */

#include <stdio.h>

/**
 * @brief Descripción de la función incrementar.
 *
 * @param numero Descripción del parámetro numero.
 */
void incrementar(int *numero)
{
    (*numero)++;
}

int main(void)
{
    int contador = 0;

    incrementar(&contador);
    incrementar(&contador);
    printf("contador = %d\n", contador);

    return 0;
}
