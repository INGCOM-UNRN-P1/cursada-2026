#include <stdio.h>

int main(void)
{
    printf("Iniciando cuenta regresiva:\n");
    for (unsigned int i = 5; i >= 0; i--)
    {
        printf("  i = %u\n", i);
        if (i > 10)
        {
            printf("detenido.\n");
            break;
        }
    }
    return 0;
}
