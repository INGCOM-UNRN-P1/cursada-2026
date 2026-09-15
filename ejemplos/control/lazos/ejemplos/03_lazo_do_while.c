#include <stdio.h>

/*
 * SITUACION: Lazo de repeticion con evaluacion al final 'do-while'.
 * EXPLICACION: Garantiza que el cuerpo del lazo se ejecute al menos una vez, ya
 * que la condicion se evalua al final de la iteracion.
 */

int main(void)
{
    printf("Lazo do-while:\n");
    int opcion = 0;
    do
    {
        printf("  Se ejecuta al menos una vez (opcion = %d)\n", opcion);
    } while (opcion != 0);

    return 0;
}
