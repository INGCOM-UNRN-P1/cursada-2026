#include <stdio.h>

/*
 * SITUACION: Sentencia de salto 'continue'.
 * EXPLICACION: Omite el resto del cuerpo del lazo actual y salta inmediatamente
 * a la siguiente iteracion (o evaluacion de condicion).
 */

int main(void)
{
    printf("Uso correcto de continue para omitir iteraciones pares:\n");
    for (int i = 1; i <= 6; i++)
    {
        if (i % 2 == 0)
        {
            continue; // Salta directamente a la siguiente iteracion
        }
        printf("  Impar: %d\n", i);
    }
    return 0;
}
