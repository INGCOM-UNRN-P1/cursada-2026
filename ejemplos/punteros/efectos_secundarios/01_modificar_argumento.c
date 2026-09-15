/* Efecto secundario: la llamada cambia una variable visible en main. */

#include <stdio.h>

/**
 * @brief Descripción de la función poner_en_cero.
 *
 * @param valor Descripción del parámetro valor.
 */
void poner_en_cero(int *valor)
{
    *valor = 0;
}

int main(void)
{
    int saldo = 100;

    printf("antes = %d\n", saldo);
    poner_en_cero(&saldo);
    printf("despues = %d\n", saldo);

    return 0;
}
