/* CONTRAEJEMPLO: una cadena literal no es un arreglo modificable.NO EJECUTAR.
 */

#include <stdio.h>

int main(void)
{
    char *mensaje = "solo lectura";

    /* Comportamiento indefinido: se intenta modificar una cadena literal. */
    mensaje[0] = 'S';
    puts(mensaje);

    return 0;
}
