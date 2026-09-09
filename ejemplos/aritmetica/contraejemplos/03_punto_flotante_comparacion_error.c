#include <stdio.h>

/*
 * SITUACION (BUG): Comparacion directa de flotantes usando '=='.
 * EXPLICACION: Operaciones como 0.1 + 0.2 no pueden representarse exactamente en binario IEEE 754.
 * La comparacion (0.1 + 0.2 == 0.3) evalua como FALSA debido a infinitesimales de imprecision.
 */

int main(void) {
    // BUG: Comparar flotantes directamente con == produce resultados falsos por representación IEEE 754
    double a = 0.1 + 0.2;
    double b = 0.3;

    if (a == b) {
        printf("Iguales\n");
    } else {
        printf("[BUG] 0.1 + 0.2 == 0.3 es Falso. a = %.17f, b = %.17f\n", a, b);
    }
    return 0;
}
