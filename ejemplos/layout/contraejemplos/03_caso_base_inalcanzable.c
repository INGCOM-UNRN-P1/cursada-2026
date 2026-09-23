/* CONTRAEJEMPLO: la recursión tiene caso base, pero la entrada nunca lo
 * alcanza.factorial(0) salta el caso n == 1 y, como n es unsigned long,
 * n - 1 da la vuelta a ULONG_MAX: los marcos se apilan hasta agotar la pila
 * (stack overflow) y el programa muere con SIGSEGV.
 *
 * Ejecutar SOLO dentro de nostromo (desde la raíz de ejemplos/):
 *
 *   gcc -std=c11 -g layout/contraejemplos/03_caso_base_inalcanzable.c -o
 * /tmp/factorial nostromo run /tmp/factorial 5        # 120 nostromo run
 * /tmp/factorial 0        # SEGFAULT
 *
 * nostromo lo reporta en décimas de segundo.hal no es la herramienta para
 * este caso: al intentar recorrer cientos de miles de marcos, GDB supera el
 * tiempo límite de hal.Con marcos grandes (pocos niveles) hal sí termina,
 * pero confunde el desborde de pila con una dirección de retorno pisada.
 *
 * Corrección: usar n <= 1 como caso base.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Descripción de la función factorial.
 *
 * @param n Descripción del parámetro n.
 * @return Descripción del valor de retorno.
 */
static unsigned long factorial(unsigned long n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "uso: %s <n>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned long n = strtoul(argv[1], NULL, 10);
    printf("%lu\n", factorial(n));

    return EXIT_SUCCESS;
}
