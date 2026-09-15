/* La aritmetica de punteros permite recorrer un mismo arreglo. */

#include <stdio.h>

int main(void)
{
    int valores[] = {10, 20, 30, 40};
    int *actual = valores;
    int *fin = valores + (sizeof(valores) / sizeof(valores[0]));

    while (actual < fin)
    {
        printf("%d\n", *actual);
        actual++;
    }

    return 0;
}
