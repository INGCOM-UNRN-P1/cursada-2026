/* Una variable static conserva su existencia despues del retorno. */

#include <stdio.h>

/**
 * @brief Descripción de la función obtener_direccion_segura.
 * @return Descripción del valor de retorno.
 */
int *obtener_direccion_segura(void)
{
    static int valor = 42;

    return &valor;
}

int main(void)
{
    int *puntero = obtener_direccion_segura();

    printf("%d\n", *puntero);

    return 0;
}
