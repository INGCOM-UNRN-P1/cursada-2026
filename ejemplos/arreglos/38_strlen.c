/* 38_strlen.c
 *
 * strlen recorre la cadena hasta encontrar '\0'.
 * No cuenta el byte nulo.
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char cadena[] = "Programacion";

    printf("Cadena: %s\n", cadena);
    printf("Largo: %zu\n", strlen(cadena));

    return 0;
}
