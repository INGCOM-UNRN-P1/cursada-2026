#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int numero = 0;
    scanf("%d", &numero);
    bool es_par = (numero % 2) == 0;
    printf("El número %d es ", numero);
    if (es_par)
    {
        printf("par");
    }
    else
    {
        printf("impar");
    }
    printf("\n");
    return 0;
}
