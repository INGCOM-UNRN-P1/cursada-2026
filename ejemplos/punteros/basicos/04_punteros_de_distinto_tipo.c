/* Un puntero de tipo char permite observar los bytes de un entero. */

#include <stdio.h>

int main(void)
{
    int entero = 65;
    unsigned char *byte = (unsigned char *)&entero;

    printf("entero = %d\n", entero);
    printf("primer byte = %u\n", (unsigned)*byte);

    return 0;
}
