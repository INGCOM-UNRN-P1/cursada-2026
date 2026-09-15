/* CONTRAEJEMPLO: el objeto local deja de existir al cerrar su bloque.NO
 * EJECUTAR. */

#include <stdio.h>

int main(void)
{
    int *puntero;

    {
        int local = 99;
        puntero = &local;
        printf("dentro del bloque = %d\n", *puntero);
    }

    /* Comportamiento indefinido: local ya no existe. */
    printf("fuera del bloque = %d\n", *puntero);

    return 0;
}
