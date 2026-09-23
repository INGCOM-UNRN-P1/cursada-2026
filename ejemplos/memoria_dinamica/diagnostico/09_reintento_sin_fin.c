/*
 * vasquez + nostromo: ante un malloc que devuelve NULL, el programa
 * "reintenta" en un lazo. Si la memoria no aparece, el lazo no termina: el
 * programa no se cae, se cuelga. En una ejecución normal malloc funciona a la
 * primera y el error pasa inadvertido.
 *
 *   gcc -std=c11 -g memoria_dinamica/diagnostico/09_reintento_sin_fin.c -o /tmp/reintento
 *   nostromo run /tmp/reintento
 *   vasquez inject memoria_dinamica/diagnostico/09_reintento_sin_fin.c --fail-malloc-at 1
 *   vasquez inject memoria_dinamica/diagnostico/09_reintento_sin_fin.c --fail-malloc-at 1 --cascade
 *
 * nostromo confirma que el camino feliz funciona. Con un único fallo el
 * segundo intento tiene éxito y vasquez lo da por manejado. Con --cascade
 * todas las llamadas siguientes también fallan: vasquez corta a los 3 s y lo
 * clasifica como INFINITE_LOOP. No usar hal: no hay señal que diagnosticar.
 *
 * Reintentar no crea memoria: la respuesta correcta es liberar lo reservado y
 * terminar con EXIT_FAILURE, como en 04_malloc_verificado.c.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *valores = NULL;

    /* Error: si malloc sigue fallando, este lazo no termina nunca. */
    while (valores == NULL)
    {
        valores = malloc(10 * sizeof *valores);
    }

    valores[0] = 7;
    printf("%d\n", valores[0]);
    free(valores);
    return EXIT_SUCCESS;
}
