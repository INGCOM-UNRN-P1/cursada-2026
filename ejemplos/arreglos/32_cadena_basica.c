/* 32_cadena_basica.c
 *
 * En C no existe un tipo primitivo string.
 * Una cadena es un arreglo de char terminado por '\0'.
 */

#include <stdio.h>

int main(void)
{
    char cadena[] = "hola";

    printf("%s\n", cadena);

    printf("capacidad = %zu\n", sizeof(cadena));

    return 0;
}
