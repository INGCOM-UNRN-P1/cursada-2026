/* 30_ascii.c
 *
 * Para introducir ASCII mostramos la relación entre carácter y valor.
 * La representación numérica es útil, pero no debemos convertir esto
 * en una dependencia innecesaria de números mágicos.
 */

#include <stdio.h>

int main(void)
{
    printf("'A' = %d\n", 'A');
    printf("'a' = %d\n", 'a');
    printf("'0' = %d\n", '0');
    printf("' ' = %d\n", ' ');

    return 0;
}
