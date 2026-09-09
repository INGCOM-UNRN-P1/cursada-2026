/* 46_strcmp.c
 *
 * Las cadenas NO se comparan con ==.
 * strcmp compara sus contenidos.
 *
 * Resultado:
 *   0->iguales
 *   <0->primera menor
 *   >0->primera mayor
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char primero[] = "ana";
    char segundo[] = "ana";
    char tercero[] = "juan";

    printf("strcmp(primero, segundo) = %d\n", strcmp(primero, segundo));

    printf("strcmp(primero, tercero) = %d\n", strcmp(primero, tercero));

    printf("strcmp(tercero, primero) = %d\n", strcmp(tercero, primero));

    return 0;
}
