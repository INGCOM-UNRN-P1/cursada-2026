#include <stdio.h>
#include <stdlib.h>

/*
 * SITUACION (BUG): Condicion de corte que el tipo del contador no alcanza.
 * EXPLICACION: Un unsigned char llega hasta 255. La condicion 'i < 300' es
 * siempre verdadera: al pasar de 255, el contador vuelve a 0 (aritmetica
 * modular de los sin signo) y el lazo no termina nunca.No hay senial ni
 * caida: el programa simplemente se cuelga.
 *
 * DIAGNOSTICO (desde la raiz de ejemplos/):
 *
 *   gcc -std=c11 -g
 * control/lazos/contraejemplos/04_lazo_infinito_rango_del_tipo_error.c -o
 * /tmp/lazo nostromo run /tmp/lazo--timeout 1          # TIMEOUT
 *
 * nostromo corta la ejecucion al segundo y la clasifica como TIMEOUT.NO usar
 * hal con este programa: hal espera una caida que nunca ocurre, se queda
 * esperando a GDB y termina con un error de tiempo agotado a los 10 s.hal
 * sirve para seniales (SIGSEGV, SIGFPE, SIGABRT), no para cuelgues.
 *
 * El compilador avisa del problema con -Wextra ("comparison is always true
 * due to limited range of data type"); con -Werror ni siquiera compila.Por
 * eso el comando de arriba no usa -Wextra.
 *
 * Solucion: declarar el contador del mismo tipo que el limite (int o size_t).
 */

int main(void)
{
    long total = 0;

    // BUG: 'i' nunca llega a 300; el lazo es infinito
    for (unsigned char i = 0; i < 300; i++)
    {
        total += i;
    }

    printf("%ld\n", total);
    return EXIT_SUCCESS;
}
