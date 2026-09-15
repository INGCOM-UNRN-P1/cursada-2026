/* CONTRAEJEMPLO: una direccion numerica no crea un objeto valido.NO EJECUTAR.
 */

#include <stdio.h>

int main(void)
{
    int *puntero = (int *)0x1234;

    /* Comportamiento indefinido: la direccion no proviene de un objeto. */
    printf("%d\n", *puntero);

    return 0;
}
