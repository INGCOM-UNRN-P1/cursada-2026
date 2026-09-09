#include <stdio.h>

/*
 * SITUACION: Lazo de repeticion determinado 'for'.
 * EXPLICACION: Estructura de control iterativa con inicializacion, condicion de continuidad e incremento definidos en la cabecera.
 */

int main(void) {
    printf("Lazo for:\n");
    for (int i = 0; i < 3; i++) {
        printf("  i = %d\n", i);
    }
    return 0;
}
