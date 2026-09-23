/*
 * Diagnóstico con hal: escribir a través de un puntero NULL provoca un
 * SIGSEGV determinista.hal ejecuta el programa bajo GDB, captura la señal y
 * señala la línea y la variable responsables.
 *
 *   daedalus compile memoria_dinamica/diagnostico/01_desreferencia_nula.c -o
 * /tmp/nula nostromo run /tmp/nula                      # SEGFAULT hal check
 * memoria_dinamica/diagnostico/01_desreferencia_nula.c
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Descripción de la función cargar.
 *
 * @param destino Descripción del parámetro destino.
 * @param valor Descripción del parámetro valor.
 */
static void cargar(int *destino, int valor)
{
    *destino = valor;
}

int main(void)
{
    int *dato = NULL;

    cargar(dato, 42);
    printf("%d\n", *dato);
    return EXIT_SUCCESS;
}
