#include <stdio.h>

/*
 * SITUACION (BUG): Efectos secundarios no ejecutados por evaluacion de cortocircuito.
 * EXPLICACION: En 'A && B', si A es falso, B no se evalua. Si B contiene un incremento (b++),
 * este no se llevara a cabo, produciendo un comportamiento no deseado si se esperaba la mutacion.
 */

int main(void) {
    int a = 0;
    int b = 10;

    // BUG: La evaluacion de cortocircuito hace que (b++) nunca se ejecute si (a != 0) es falso
    if (a != 0 && (b++ > 0)) {
        // Bloque no ejecutado
    }

    printf("[BUG] b no se incremento debido al cortocircuito del operador &&: b = %d\n", b);
    return 0;
}
