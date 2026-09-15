/* CONTRAEJEMPLO: al retornar, la variable local deja de existir.NO EJECUTAR.
 */

#include <stdio.h>

/**
 * @brief Descripción de la función obtener_direccion.
 * @return Descripción del valor de retorno.
 */
int *obtener_direccion(void)
{
    int local = 42;

    return &local;
}

int main(void)
{
    int *puntero = obtener_direccion();

    /* Comportamiento indefinido: local ya no existe. */
    printf("%d\n", *puntero);

    return 0;
}
