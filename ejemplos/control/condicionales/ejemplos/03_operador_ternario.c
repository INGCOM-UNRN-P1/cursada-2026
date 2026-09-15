#include <stdio.h>

/*
 * SITUACION : Operador condicional ternario ( ? : ).
 * EXPLICACION: Sintaxis compacta para asignaciones o retornos condicionales
 * simples de la forma (condicion) ? exp1 : exp2.
 */

int main(void)
{
    int edad = 20;

    // Uso limpio del operador ternario para asignaciones condicionales simples
    const char *estado = (edad >= 18) ? "Mayor de edad" : "Menor de edad";
    printf("Estado: %s\n", estado);
    return 0;
}
