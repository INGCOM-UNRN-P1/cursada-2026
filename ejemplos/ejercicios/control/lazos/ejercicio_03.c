#include <stdio.h>

int main(void)
{
    int valores[5] = {10, -5, 20, -3, 30};
    int total_evaluaciones = 0;

    printf("Procesando arreglo...\n");
    for (int i = 0; i < 5; i++)
    {
        total_evaluaciones++;
        if (valores[i] < 0)
        {
            i--;
        }
        if (total_evaluaciones > 10)
        {
            printf("[INTERRUPCION SEGURIDAD] Bucle infinito detectado.\n");
            break;
        }
    }
    return 0;
}
