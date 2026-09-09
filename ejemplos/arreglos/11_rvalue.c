/* 11_rvalue.c
 *
 * Cuando usamos arreglo[indice] para obtener un valor,
 * estamos utilizando la expresión como R-value.
 */

#include <stdio.h>

int main(void)
{
    int calificaciones[5] = {10, 8, 9, 7, 10};

    int primera = calificaciones[0];

    printf("Primera calificacion: %d\n", primera);
    printf("Otra calificacion: %d\n", calificaciones[2]);

    return 0;
}
