#include <stdbool.h>
#include <stdio.h>

/* Ejemplo listo para enchufar en el parcial */

int main(void)
{
    int nota = 0;
    scanf("%d", &nota);
    int contador = 0;

    if (nota > 100)
        printf("no valida (por positivo)");
    else if (nota >= 90)
        printf("excelente");
    else if (nota >= 70)
        printf("aprobado");
    else if (nota >= 0)
        printf("desaprobado");
    else if (nota < 0)
        printf("nota no valida (por negativo)");
    else
        printf("¿con que valor de nota pasa por acá?");

    printf(
    return 0;
}
