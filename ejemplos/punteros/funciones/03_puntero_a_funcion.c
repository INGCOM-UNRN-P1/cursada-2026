/* Un puntero a funcion permite seleccionar una operacion. */

#include <stdio.h>

typedef int (*Operacion)(int, int);

/**
 * @brief Descripción de la función sumar.
 *
 * @param izquierda Descripción del parámetro izquierda.
 * @param derecha Descripción del parámetro derecha.
 * @return Descripción del valor de retorno.
 */
int sumar(int izquierda, int derecha)
{
    return izquierda + derecha;
}

/**
 * @brief Descripción de la función multiplicar.
 *
 * @param izquierda Descripción del parámetro izquierda.
 * @param derecha Descripción del parámetro derecha.
 * @return Descripción del valor de retorno.
 */
int multiplicar(int izquierda, int derecha)
{
    return izquierda * derecha;
}

/**
 * @brief Descripción de la función mostrar_resultado.
 *
 * @param operacion Descripción del parámetro operacion.
 * @param izquierda Descripción del parámetro izquierda.
 * @param derecha Descripción del parámetro derecha.
 */
void mostrar_resultado(Operacion operacion, int izquierda, int derecha)
{
    printf("resultado = %d\n", operacion(izquierda, derecha));
}

int main(void)
{
    mostrar_resultado(sumar, 3, 4);
    mostrar_resultado(multiplicar, 3, 4);

    return 0;
}
