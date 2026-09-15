#include <stdbool.h>
#include <stdio.h>

/*
 * SITUACION: Evaluacion de veracidad (Truthiness) de valores en C.
 * EXPLICACION: En C no existe tipo booleano primitivo nativo previo a C99.
 * REGLA GENERAL:
 *   - El valor 0 (entero 0, flotante 0.0, caracter '\0', puntero NULL) evalua
 * como FALSO.
 *   - Cualquier valor DISTINTO DE CERO (enteros positivos/negativos como -1,
 * chars, punteros validos) evalua como VERDADERO.Desde C99, <stdbool.h> define
 * 'bool', 'true' (1) y 'false' (0).
 */

int main(void)
{
    int cero = 0;
    int negativo = -1;
    int positivo = 42;
    char caracter = 'A';
    char nulo = '\0';
    void *ptr = NULL;

    printf("Evaluacion de Veracidad en C:\n");

    if (!cero)
    {
        printf("  0 evalua como FALSO.\n");
    }

    if (negativo)
    {
        printf("  -1 evalua como VERDADERO (cualquier entero != 0 es "
               "verdadero).\n");
    }

    if (positivo)
    {
        printf("  42 evalua como VERDADERO.\n");
    }

    if (caracter)
    {
        printf("  'A' (ASCII %d) evalua como VERDADERO.\n", caracter);
    }

    if (!nulo)
    {
        printf("  '\\0' (valor ASCII 0) evalua como FALSO.\n");
    }

    if (!ptr)
    {
        printf("  Puntero NULL evalua como FALSO.\n");
    }

    bool booleano = true;
    printf("  stdbool bool verdadero: %d\n", booleano);

    return 0;
}
