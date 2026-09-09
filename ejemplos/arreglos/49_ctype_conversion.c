/* 49_ctype_conversion.c
 *
 * En lugar de manipular códigos ASCII manualmente,
 * utilizamos tolower y toupper.
 */

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    char minuscula = 'm';
    char mayuscula = 'M';

    printf("%c -> %c\n", minuscula, toupper((unsigned char)minuscula));

    printf("%c -> %c\n", mayuscula, tolower((unsigned char)mayuscula));

    return 0;
}
