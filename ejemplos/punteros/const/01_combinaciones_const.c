/* const puede restringir el contenido, la direccion o ambos. */

#include <stdio.h>

/**
 * @brief Descripción de la función leer_sin_modificar.
 *
 * @param puntero Descripción del parámetro puntero.
 */
void leer_sin_modificar(const int *puntero)
{
    printf("%d\n", *puntero);
}

int main(void)
{
    int primero = 1;
    int segundo = 2;
    const int valor_fijo = 3;

    int *modificable = &primero;
    const int *contenido_constante = &primero;
    int *const direccion_constante = &segundo;
    const int *const ambos_constantes = &valor_fijo;

    *modificable = 10;
    direccion_constante[0] = 20;
    contenido_constante = &segundo;

    leer_sin_modificar(ambos_constantes);
    printf("%d %d %d\n", primero, segundo, *contenido_constante);

    return 0;
}
