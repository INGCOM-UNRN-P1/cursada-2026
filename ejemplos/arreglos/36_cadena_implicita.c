/* 36_cadena_implicita.c
 *
 * Cuando omitimos la capacidad, el compilador reserva exactamente
 * la cantidad necesaria para los caracteres y el '\0'.
 */

#include <stdio.h>

int main(void)
{
    char cadena[] = "hola";

    printf("capacidad = %zu\n", sizeof(cadena));

    return 0;
}
