/*
 * Diagnóstico con hal: un índice fuera de rango sobre un bloque dinámico
 * lejos del final termina en una caída.hal muestra la pila de llamadas y el
 * valor del índice en el momento de la señal.
 *
 *   daedalus compile memoria_dinamica/diagnostico/02_indice_fuera_de_rango.c -o
 * /tmp/rango nostromo run /tmp/rango                     # SEGFAULT hal check
 * memoria_dinamica/diagnostico/02_indice_fuera_de_rango.c
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Descripción de la función sumar.
 *
 * @param valores Descripción del parámetro valores.
 * @param cantidad Descripción del parámetro cantidad.
 * @return Descripción del valor de retorno.
 */
static long sumar(const int *valores, size_t cantidad)
{
    long total = 0;

    for (size_t i = 0; i < cantidad; i++)
    {
        total += valores[i];
    }
    return total;
}

int main(void)
{
    size_t cantidad = 4;
    int *valores = malloc(cantidad * sizeof *valores);
    if (valores == NULL)
    {
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < cantidad; i++)
    {
        valores[i] = (int)i;
    }

    /* Error: se pasa una cantidad que no corresponde al bloque reservado. */
    printf("%ld\n", sumar(valores, cantidad * 100000000));
    free(valores);
    return EXIT_SUCCESS;
}
