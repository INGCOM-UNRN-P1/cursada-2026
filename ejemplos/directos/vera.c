#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int numero = -3;
    while (numero)
    {
        printf("%d, ", numero);
        numero++;
    }
    return 0;
}
