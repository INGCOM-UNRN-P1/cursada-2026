/* 47_comparacion_incorrecta.c
 *
 * ERROR CONCEPTUAL.
 *
 * == compara expresiones de puntero/dirección, no el contenido textual.
 * Para comparar cadenas debemos usar strcmp.
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[] = "hola";
    char b[] = "hola";

    if (a == b)
    {
        printf("Las cadenas son iguales\n");
    }
    else
    {
        printf("Las direcciones no son iguales\n");
    }

    if (strcmp(a, b) == 0)
    {
        printf("El contenido es igual\n");
    }

    return 0;
}
