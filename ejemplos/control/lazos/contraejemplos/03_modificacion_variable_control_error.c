#include <stdio.h>

/*
 * SITUACION (BUG): Alteracion de la variable de control dentro del cuerpo del
 * lazo 'for'.EXPLICACION: Modificar la variable de iteracion ('i') dentro del
 * cuerpo del lazo rompe el calculo del numero de iteraciones y puede derivar en
 * lazos infinitos impredecibles.
 */

int main(void)
{
    // BUG: Modificar la variable de control 'i' dentro del cuerpo del lazo
    // altera la iteraciones esperadas
    printf("[BUG] Modificacion indeseada de la variable de control:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("  i = %d\n", i);
        i--; // Al decrementar i dentro del cuerpo, se produce un lazo infinito
        if (i < -2)
        {
            printf("  [Interrupcion forzada para evitar cuelgue]\n");
            break;
        }
    }
    return 0;
}
