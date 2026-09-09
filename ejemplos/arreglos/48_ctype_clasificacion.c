/* 48_ctype_clasificacion.c
 *
 * ctype.h ofrece funciones para clasificar caracteres:
 *
 * isalpha, isdigit, isspace, isupper, islower, etc.
 */

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    char caracteres[] = {'A', 'a', '7', ' ', '.', '\n'};

    size_t cantidad = sizeof(caracteres) / sizeof(caracteres[0]);

    for (size_t i = 0; i < cantidad; i++)
    {
        char c = caracteres[i];

        printf("'%c': ", c);

        if (isalpha((unsigned char)c))
        {
            printf("letra ");
        }

        if (isdigit((unsigned char)c))
        {
            printf("digito ");
        }

        if (isspace((unsigned char)c))
        {
            printf("espacio/control ");
        }

        printf("\n");
    }

    return 0;
}
