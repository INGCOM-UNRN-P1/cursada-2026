#include <stdio.h>

int main(void)
{
    int contador = 0;

    printf("Incrementando contador...\n");
    /* ATENCION: Analizar minuciosamente la sintaxis de la siguiente linea */
    while (contador < 5)
        ;
    {
        printf("  contador = %d\n", contador);
        contador++;
    }
    return 0;
}
