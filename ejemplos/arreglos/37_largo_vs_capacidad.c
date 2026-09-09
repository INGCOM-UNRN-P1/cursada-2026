/* 37_largo_vs_capacidad.c
 *
 * Diferenciamos dos conceptos:
 *
 * largo     = caracteres antes de '\0'
 * capacidad = bytes reservados para el arreglo
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char cadena[100] = "hola";

    printf("largo = %zu\n", strlen(cadena));
    printf("capacidad = %zu\n", sizeof(cadena));

    return 0;
}
