/* CONTRAEJEMPLO: comparar direcciones de objetos no relacionados no tiene
 * un orden garantizado por el estándar de C. NO ASUMIR el resultado.
 */

#include <stdio.h>

int main(void)
{
    int variable_a = 1;
    int variable_b = 2;

    /* Comportamiento no especificado: el estandar no garantiza que
     * &variable_a sea menor o mayor que &variable_b, porque no
     * pertenecen al mismo arreglo u objeto. */
    if (&variable_a < &variable_b)
    {
        printf("variable_a antes que variable_b (no garantizado)\n");
    }
    else
    {
        printf("variable_b antes que variable_a (no garantizado)\n");
    }

    return 0;
}
