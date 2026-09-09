#include <stdio.h>

/*
 * SITUACION: Lazo de repeticion condicionado 'while'.
 * EXPLICACION: Evalua la condicion antes de cada iteracion; el cuerpo se ejecuta cero o mas veces mientras la condicion sea verdadera.
 */

int main(void) {
    printf("Lazo while:\n");
    int contador = 3;
    while (contador > 0) {
        printf("  contador = %d\n", contador);
        contador--;
    }
    return 0;
}
