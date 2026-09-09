/* 35_cadena_sin_terminador.c
 *
 * ERROR INTENCIONAL.
 *
 * Cuatro bytes alcanzan para guardar H, o, l, a,
 * pero no dejan espacio para '\0'.
 *
 * Por lo tanto el objeto no contiene una cadena C válida.
 */

#include <stdio.h>

int main(void)
{
    char cadena[4] = {'h', 'o', 'l', 'a'};

    /* No es seguro utilizar %s con este objeto. */

    for (size_t i = 0; i < sizeof(cadena); i++)
    {
        printf("%c", cadena[i]);
    }

    printf("\n");

    return 0;
}
