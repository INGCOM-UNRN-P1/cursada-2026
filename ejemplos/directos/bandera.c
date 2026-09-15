#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int numero = 3;
    bool bandera = true;
    while (bandera)
    {
        printf("%d, ", numero);
        numero--;
        bandera = numero > 0;
    }
    return 0;
}
