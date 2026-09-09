#include <stdio.h>

/*
 * SITUACION (BUG): Confuncion sobre el alcance de 'break' en lazos anidados.
 * EXPLICACION: 'break' solo interrumpe el lazo mas interno que lo contiene. No sale de los lazos envolventes superiores.
 */

int main(void) {
    // BUG: Suponer que break rompe todos los lazos anidados.
    // En C, break solo interrumpe el lazo inmediatamente mas interno.
    printf("[BUG] break solo rompe el lazo interno:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == 1) break; // Sale del lazo j, pero el lazo i continua iterando
            printf("  i=%d, j=%d\n", i, j);
        }
        printf("  El lazo exterior i=%d sigue ejecutandose\n", i);
    }
    return 0;
}
