/* 03_pila_variables_locales.c
 *
 * Las variables locales automáticas viven en el marco de pila de la
 * función que las declara. Su dirección cambia según la profundidad
 * de la llamada, a diferencia de una variable global.
 */

#include <stdio.h>

void mostrar_direccion_local(void)
{
    int local = 1;

    printf("local en mostrar_direccion_local (direccion en pila): %p\n",
           (void *)&local);
}

int main(void)
{
    int local = 0;

    printf("local en main (direccion en pila): %p\n", (void *)&local);
    mostrar_direccion_local();

    return 0;
}
