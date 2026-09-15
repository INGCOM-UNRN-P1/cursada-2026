#include <stdio.h>

/*
 * SITUACION: Estructura condicional if / else if / else.
 * EXPLICACION: Permite la ejecucion ramificada de bloques de
 * codigo segun condiciones booleanas excluyentes.
 */

int main(void)
{
    int nota = 85;

    if (nota >= 90)
    {
        printf("Excelente\n");
    }
    else if (nota >= 70)
    {
        printf("Aprobado\n");
    }
    else
    {
        printf("Desaprobado\n");
    }
    return 0;
}
