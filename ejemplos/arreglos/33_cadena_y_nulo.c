/* 33_cadena_y_nulo.c
 *
 * "hola" tiene cuatro caracteres visibles,
 * pero necesita cinco bytes:
 *
 *     h o l a \0
 *
 * El último byte indica dónde termina la cadena.
 */

#include <stddef.h>
#include <stdio.h>

#define MAX 10

int main(void)
{
    char cadena[40] = "holamundo";
    size_t i = 0;
    printf("%s\n", cadena);
    char zaraza = 'a';
    for (; i < MAX; i++)
    {
        printf("cadena[%zu] = %c\n", i, cadena[i]);
    }
    zaraza = 'b';
    printf("%s\n", cadena+5);
    return 0;
}
