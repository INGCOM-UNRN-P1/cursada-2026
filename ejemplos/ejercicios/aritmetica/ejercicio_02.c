#include <stdio.h>

int main(void)
{
    int descuento = 15;
    int total = 100;
    double porcentaje = (descuento / total) * 100;

    printf("Porcentaje de descuento: %.2f%%\n", porcentaje);
    return 0;
}
