/* CONTRAEJEMPLO: avanzar mas alla del arreglo y desreferenciar es invalido.NO
 * EJECUTAR. */

#include <stdio.h>

int main(void)
{
    int valores[] = {10, 20, 30};
    int *puntero = valores + 3;

    /* La direccion one-past puede calcularse, pero no desreferenciarse. */
    printf("%d\n", *puntero);

    return 0;
}
