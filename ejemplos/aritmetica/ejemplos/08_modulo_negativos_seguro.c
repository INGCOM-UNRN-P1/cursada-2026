#include <stdio.h>

/*
 * SITUACION: Operador modulo (%) con dividendo negativo en C99+.
 * EXPLICACION: Segun el estandar C99 y posteriores, a % b conserva el signo del
 * dividendo 'a'.Este ejemplo ilustra el comportamiento determinista de la
 * operacion.
 */

int main(void)
{
    // En C99+, el operador % mantiene el signo del dividendo (el numero a la
    // izquierda)
    int a = -7;
    int b = 3;
    int mod = a % b;

    printf("Operacion modulo en C99+: %d %% %d = %d\n", a, b, mod);
    return 0;
}
