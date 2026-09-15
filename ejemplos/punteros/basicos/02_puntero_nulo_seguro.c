/* NULL representa que el puntero no apunta a un objeto. */

#include <stdio.h>

/**
 * @brief Descripción de la función imprimir_si_existe.
 *
 * @param valor Descripción del parámetro valor.
 */
void imprimir_si_existe(const int *valor)
{
    if (valor != NULL)
    {
        printf("valor = %d\n", *valor);
    }
    else
    {
        printf("no hay valor apuntado\n");
    }
}

int main(void)
{
    int numero = 42;
    int *puntero = NULL;

    imprimir_si_existe(puntero);
    puntero = &numero;
    imprimir_si_existe(puntero);

    return 0;
}
