#include <stdio.h>

/*
 * SITUACION (BUG): Uso desestructurado de 'goto' (Codigo Espagueti).
 * EXPLICACION: Saltar con 'goto' hacia el interior de lazos o salteando
 * inicializaciones rompe la estructura del programa, dificulta el seguimiento
 * del estado de las variables y produce bugs indetectables.
 */

int main(void)
{
    int x = 1;

    // BUG: goto espagueti saltando arbitrariamente dentro de un lazo
    goto dentro_lazo;

    for (int i = 0; i < 3; i++)
    {
    dentro_lazo:
        printf("[BUG] Salto espagueti a 'dentro_lazo'. i = %d, x = %d\n", i, x);
    }
    return 0;
}
