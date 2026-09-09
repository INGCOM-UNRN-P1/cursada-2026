/* 27_retorno_arreglo_incorrecto.c
 *
 * NO COMPILAR.
 *
 * Este ejemplo representa el intento de devolver un arreglo local.
 * La idea permite explicar por qué la memoria local de una función
 * no puede utilizarse de esta manera después del return.
 */

#include <stdio.h>

/* ERROR DE DISEÑO / DECLARACION INTENCIONAL */

int *crear_arreglo(void)
{
    int retorno[3] = {10, 20, 30};

    return retorno;
}

int main(void)
{
    int *arreglo = crear_arreglo();

    printf("%d\n", arreglo[0]);

    return 0;
}
