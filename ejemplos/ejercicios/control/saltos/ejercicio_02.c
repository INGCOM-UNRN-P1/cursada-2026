#include <stdio.h>

int main(void)
{
    int i = 0;
    int iteraciones = 0;

    printf("Procesando numeros impares del 0 al 4:\n");
    while (i < 5)
    {
        iteraciones++;
        if (iteraciones > 10)
        {
            printf(
                "[INTERRUPCION SEGURIDAD] Bucle infinito detectado en i = %d\n",
                i);
            break;
        }

        if (i % 2 == 0)
        {
            continue;
        }

        printf("  Impar: %d\n", i);
        i++;
    }
    return 0;
}
