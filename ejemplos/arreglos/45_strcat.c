/* 45_strcat.c
 *
 * strcat agrega la cadena origen al final de destino.
 * Nuevamente, destino debe tener espacio suficiente.
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char destino[30] = "Hola";
    char origen[] = " mundo";

    strcat(destino, origen);

    printf("%s\n", destino);

    return 0;
}
