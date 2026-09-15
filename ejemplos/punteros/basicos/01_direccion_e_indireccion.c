/* La direccion se obtiene con &, y el contenido apuntado con *. */

#include <stdio.h>

int main(void)
{
    int edad = 20;
    int *puntero = &edad;

    printf("edad = %d\n", edad);
    printf("&edad = %p\n", (void *)&edad);
    printf("puntero = %p\n", (void *)puntero);
    printf("*puntero = %d\n", *puntero);

    *puntero = 21;
    printf("edad despues de *puntero = 21: %d\n", edad);

    return 0;
}
