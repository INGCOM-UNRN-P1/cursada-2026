#include <stdio.h>

/*
 * SITUACION: Uso claro de operadores de incremento prefijo y postfijo.
 * EXPLICACION: ++i incrementa la variable y evalua al nuevo valor.
 * i++ evalua al valor actual y luego realiza el incremento. Se usan en sentencias separadas para evitar ambiguedad.
 */

int main(void) {
    int i = 5;

    // Uso claro y separado de prefijo y postfijo
    int a = ++i; // i se incrementa a 6, a recibe 6
    printf("Prefijo ++i: i = %d, a = %d\n", i, a);

    int b = i++; // b recibe 6, i se incrementa a 7
    printf("Postfijo i++: i = %d, b = %d\n", i, b);
    return 0;
}
