#include <stdio.h>

int main(void)
{
    printf("Lazo do-while:\n");
    int opcion = 0;
    do
    {
        scanf("%d", &opcion);
        printf("  Se ejecuta al menos una vez (opcion = %d)\n", opcion);
    } while (opcion != 0);

    return 0;
}
