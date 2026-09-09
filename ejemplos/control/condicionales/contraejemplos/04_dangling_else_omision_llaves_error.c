#include <stdio.h>

/*
 * SITUACION (BUG): Omision de llaves y problema del 'Dangling Else'.
 * EXPLICACION: En C la indentacion no define bloques. Omitir '{}' hace que solo la primera linea pertenezca al 'if',
 * y los 'else' se asocian siempre al 'if' no emparejado mas cercano.
 */

int main(void) {
    int x = 10;
    int y = 5;

    // BUG: Omitir llaves y confiar en la indentacion genera ejecuciones no deseadas (Dangling else / Indentation bug)
    if (x < 0)
        printf("x es negativo\n");
        printf("[BUG] Esta linea se ejecuta SIEMPRE porque no esta dentro del if!\n");

    if (x > 0)
        if (y < 0)
            printf("y es negativo\n");
    else
        printf("[BUG] El 'else' se asocia al 'if (y < 0)' mas cercano, no al 'if (x > 0)'\n");

    return 0;
}
