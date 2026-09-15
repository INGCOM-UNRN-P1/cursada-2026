#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

/*
 * SITUACION: Prevencion de Overflow en enteros firmados (signed int).
 * EXPLICACION: En C, el desbordamiento de enteros con signo es Comportamiento
 * Indefinido (UB). Para evitarlo, se valida antes de operar si la suma
 * superaria INT_MAX o seria menor que INT_MIN.
 */

// Detección previa de overflow en suma de enteros signed
bool sumar_seguro_int(int a, int b, int *resultado)
{
    if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b))
    {
        return false;
    }
    *resultado = a + b;
    return true;
}

int main(void)
{
    int res = 0;
    if (sumar_seguro_int(INT_MAX, 1, &res))
    {
        printf("Suma exitosa: %d\n", res);
    }
    else
    {
        printf("Overflow prevenido antes de realizar la operacion.\n");
    }
    return 0;
}
