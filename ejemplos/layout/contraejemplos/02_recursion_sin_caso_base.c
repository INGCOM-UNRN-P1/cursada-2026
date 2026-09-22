/* CONTRAEJEMPLO: recursión sin caso base. Compila, pero NO EJECUTAR:
 * agrega marcos de pila sin límite hasta agotar la pila (stack overflow).
 */

#include <stdio.h>

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
