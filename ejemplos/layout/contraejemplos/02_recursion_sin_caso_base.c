/* CONTRAEJEMPLO: recursión sin caso base.Compila, pero NO EJECUTAR:
 * agrega marcos de pila sin límite hasta agotar la pila (stack overflow).
 */

#include <stdio.h>

/**
 * @brief Descripción de la función recursion_infinita.
 *
 * @param nivel Descripción del parámetro nivel.
 */
void recursion_infinita(int nivel)
{
    printf("nivel %d\n", nivel);
    recursion_infinita(nivel + 1);
}

int main(void)
{
    recursion_infinita(0);

    return 0;
}
