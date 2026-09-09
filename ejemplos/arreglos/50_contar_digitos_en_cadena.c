/* 50_contar_digitos_en_cadena.c
 *
 * Cerramos integrando arreglos, cadenas, recorridos, size_t y ctype.h.
 *
 * La cadena se recorre hasta '\0'.
 * Cada carácter se clasifica con isdigit.
 */

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    char cadena[] = "Programacion 1 - 2026";

    size_t cantidad_digitos = 0;

    for (size_t i = 0; cadena[i] != '\0'; i++)
    {
        if (isdigit((unsigned char)cadena[i]))
        {
            cantidad_digitos++;
        }
    }

    printf("Cadena: %s\n", cadena);
    printf("Cantidad de digitos: %zu\n", cantidad_digitos);

    return 0;
}
