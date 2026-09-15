#include <stdio.h>

/*
 * SITUACION (BUG): Error de precedencia entre operadores relacionales y bit a
 * bit.EXPLICACION: En C, '==' tiene mayor precedencia que '&'.La expresion 'a
 * & b == 2' se evalua como 'a & (b == 2)' en lugar de '(a & b) == 2', alterando
 * el resultado.
 */

int main(void)
{
    int a = 6; // 0110 en binario
    int b = 2; // 0010 en binario

    // BUG: El operador relacional '==' tiene mayor precedencia que el operador
    // a nivel de bits '&'. La expresion (a & b == 2) se evalua como (a & (b ==
    // 2)), produciendo 6 & 1 = 0.
    if (a & b == 2)
    {
        printf("Evaluacion correcta\n");
    }
    else
    {
        printf("[BUG] 'a & b == 2' evaluo como 'a & (b == 2)' por falta de "
               "parentesis.\n");
    }
    return 0;
}
