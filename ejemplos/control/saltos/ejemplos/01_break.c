#include <stdio.h>

/*
 * SITUACION: Sentencia de salto 'break'.
 * EXPLICACION: Interrumpe inmediatamente la ejecucion del lazo (for, while,
 * do-while) o switch mas interno en el que se encuentra.
 */

int main(void)
{
    printf("Uso correcto de break para salir del lazo:\n");
    for (int i = 1; i <= 10; i++)
    {
        if (i > 5)
        {
            printf("  Lazo interrumpido en i = %d\n", i);
            break;
        }
        printf("  i = %d\n", i);
    }
    return 0;
}
