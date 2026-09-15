#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int nota = 6;
    bool esta_aprobado = (nota >= 4) && (nota < 8);
    if (esta_aprobado)
    {
        printf("Aprobó!\n");
    }
    printf("adios!\n");
    return 0;
}
