#include <stdio.h>
#include <stdbool.h>

/*
 * SITUACION: Prevencion de division por cero.
 * EXPLICACION: Dividir por cero produce fallos de ejecucion o valores especiales (inf/NaN).
 * Se valida explícitamente que el divisor sea distinto de cero antes de realizar la division.
 */

bool dividir_seguro(double dividendo, double divisor, double *resultado) {
    if (divisor == 0.0) {
        return false;
    }
    *resultado = dividendo / divisor;
    return true;
}

int main(void) {
    double res = 0.0;
    if (dividir_seguro(10.0, 0.0, &res)) {
        printf("Resultado: %f\n", res);
    } else {
        printf("Division rechazada: el divisor es cero.\n");
    }
    return 0;
}
