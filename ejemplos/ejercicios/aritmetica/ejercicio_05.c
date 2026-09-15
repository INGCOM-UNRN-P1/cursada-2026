#include <stdio.h>

int main(void)
{
    int numero = 4;

    if (numero & 1 == 0)
    {
        printf("El numero %d es Par\n", numero);
    }
    else
    {
        printf("El numero %d es Impar\n", numero);
    }
    return 0;
}
