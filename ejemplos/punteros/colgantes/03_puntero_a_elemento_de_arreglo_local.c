/* CONTRAEJEMPLO: el arreglo local desaparece al retornar. NO EJECUTAR. */

#include <stdio.h>

/**
 * @brief Descripción de la función primer_elemento.
 * @return Descripción del valor de retorno.
 */
int *primer_elemento(void)
{
    int valores[] = {10, 20, 30};

    return &valores[0];
}

int main(void)
{
    int *puntero = primer_elemento();

    /* Comportamiento indefinido: el arreglo local ya no existe. */
    printf("%d\n", *puntero);

    return 0;
}
