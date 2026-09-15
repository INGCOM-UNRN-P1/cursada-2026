#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/*
 * SITUACION (BUG): Errores comunes al asumir veracidad en C.
 * EXPLICACION 1: Creer que codigos de error negativos (-1) evaluan como FALSO
 * en condicionales 'if (err)'.En C, -1 es DISTINTO DE CERO y por ende evalua
 * como VERDADERO.EXPLICACION 2: Comparar directamente 'if (flags == true)'
 * cuando 'flags' contiene valores de bits como 2 o 4. 'true' es la macro (1),
 * por lo que '2 == 1' evalua como FALSO aunque 'if (flags)' sea VERDADERO.
 */

int main(void)
{
    // BUG 1: Tratar retorno de strcmp o funciones que devuelven -1 como falso
    const char *str1 = "hola";
    const char *str2 = "chau";

    // strcmp devuelve <0 o >0 si son distintas, 0 si son iguales
    if (strcmp(str1, str2))
    {
        printf("[BUG TIPICO] strcmp devuelve distinto de 0 (evalua VERDADERO), "
               "pero se interpreto como si fueran iguales.\n");
    }

    // BUG 2: Comparacion explicita con 'true' (1) en valores enteros con flags
    // de bits
    int mascara_bit = 2; // Representa el segundo bit activo (0010)

    if (mascara_bit)
    {
        printf("[CORRECTO] 'if (mascara_bit)' evalua como VERDADERO.\n");
    }

    if (mascara_bit == true)
    {
        // No se ejecuta porque 2 == 1 es FALSO
    }
    else
    {
        printf(
            "[BUG TIPICO] 'if (mascara_bit == true)' dio FALSO porque 2 != 1 "
            "(true es la constante 1).\n");
    }

    return 0;
}
