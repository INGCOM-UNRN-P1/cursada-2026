/* 51_contar_letras.c
 *
 * Segundo ejercicio integrador.
 * No necesitamos conocer previamente el largo: el centinela '\0'
 * permite determinar dónde termina la cadena.
 */

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    char cadena[] = "Hola Mundo 2026";

    size_t letras = 0;

    for (size_t i = 0; cadena[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)cadena[i]))
        {
            letras++;
        }
    }

    printf("Cadena: %s\n", cadena);
    printf("Cantidad de letras: %zu\n", letras);

    return 0;
}
