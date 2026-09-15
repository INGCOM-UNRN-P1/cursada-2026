/* Un puntero puede apuntar a cualquier elemento de un arreglo. */

#include <stdio.h>

int main(void)
{
    int valores[] = {4, 8, 15, 16, 23, 42};
    int *seleccionado = &valores[4];

    printf("seleccionado = %d\n", *seleccionado);
    *seleccionado = 99;
    printf("valores[4] = %d\n", valores[4]);

    return 0;
}
