#include <stdio.h>

/*
 * SITUACION (BUG): Truncamiento por division entera no deseada.
 * EXPLICACION: Al evaluar 'a / b' con a=5 y b=2 (ambos int), C realiza division
 * entera (resultado 2). Asignar dicho resultado a una variable double
 * produce 2.000000 en lugar de 2.500000.
 */

int main(void)
{
    int a = 5;
    int b = 2;

    // BUG: La division entre enteros trunca los decimales antes de la
    // asignacion a double
    double resultado = a / b;
    printf("[BUG] 5 / 2 asignado a double produce: %f (Esperado: 2.500000)\n",
           resultado);
    return 0;
}
