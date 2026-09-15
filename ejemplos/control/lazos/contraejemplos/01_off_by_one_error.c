#include <stdio.h>

/*
 * SITUACION (BUG): Error fuera por uno (Off-by-one) en lazo for.
 * EXPLICACION: Utilizar '<=' en lugar de '<' al iterar un arreglo de N
 * elementos provoca que el lazo intente acceder al indice N, sobrepasando los
 * limites del arreglo (Buffer Overflow / Desbordamiento de buffer).
 */

int main(void)
{
    int arr[3] = {10, 20, 30};

    // BUG: Error fuera por uno (Off-by-one) al usar <= en lugar de < sobre la
    // longitud del arreglo
    printf("[BUG] Acceso fuera de limites (Off-by-one):\n");
    for (int i = 0; i <= 3; i++)
    {
        printf("  Indice %d: %d\n", i, arr[i]);
    }
    return 0;
}
