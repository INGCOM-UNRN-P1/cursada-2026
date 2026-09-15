/* La direccion siguiente al ultimo elemento se puede comparar, pero no leer. */

#include <stdio.h>

int main(void)
{
    int valores[] = {10, 20, 30};
    int *fin = valores + 3;

    printf("cantidad de elementos = %td\n", fin - valores);
    printf("fin se usa como limite, no como *fin\n");

    return 0;
}
