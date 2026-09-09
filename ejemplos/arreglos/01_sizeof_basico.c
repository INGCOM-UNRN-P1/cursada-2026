/* 01_sizeof_basico.c
 * 
 * Antes de hablar de arreglos necesitamos poder medir memoria.
 * sizeof no es una función: es un operador conocido por el compilador.
 * Observemos el tamaño de distintos tipos y variables.
 */

#include <stddef.h>
#include <stdio.h>

int main(void)
{
    char caracter = 'A';
    int entero = 42;
    double real = 3.14;

    printf("sizeof(char) = %zu bytes\n", sizeof(char));
    printf("sizeof(int) = %zu bytes\n", sizeof(int));
    printf("sizeof(double) = %zu bytes\n", sizeof(double));

    printf("sizeof(caracter) = %zu bytes\n", sizeof(caracter));
    printf("sizeof(entero) = %zu bytes\n", sizeof(entero));
    printf("sizeof(real) = %zu bytes\n", sizeof(real));

    return 0;
}
