/* 34_capacidad_cadena.c
 *
 * La capacidad es el espacio físico reservado.
 * En una cadena válida debe existir espacio para '\0'.
 */

#include <stdio.h>

int main(void)
{
    char cadena[10] = "hola";

    printf("cadena = \"%s\"\n", cadena);
    printf("capacidad = %zu\n", sizeof(cadena));

    return 0;
}
