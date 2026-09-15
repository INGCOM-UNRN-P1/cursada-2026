/* El intercambio modifica dos argumentos mediante sus direcciones. */

#include <stdio.h>

/**
 * @brief Descripción de la función intercambiar.
 *
 * @param izquierda Descripción del parámetro izquierda.
 * @param derecha Descripción del parámetro derecha.
 */
void intercambiar(int *izquierda, int *derecha)
{
    int temporal = *izquierda;
    *izquierda = *derecha;
    *derecha = temporal;
}

int main(void)
{
    int primero = 10;
    int segundo = 20;

    intercambiar(&primero, &segundo);
    printf("primero = %d, segundo = %d\n", primero, segundo);

    return 0;
}
