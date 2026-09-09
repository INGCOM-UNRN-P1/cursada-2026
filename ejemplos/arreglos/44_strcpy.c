/* 44_strcpy.c
 *
 * strcpy copia una cadena.
 * El destino debe tener capacidad suficiente para contener
 * todos los caracteres de origen más '\0'.
 *
 * La función NO conoce la capacidad del destino.
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char origen[] = "hola";
    char destino[20] = {};

    strcpy(destino, origen);

    printf("origen: %s\n", origen);
    printf("destino: %s\n", destino);

    return 0;
}
