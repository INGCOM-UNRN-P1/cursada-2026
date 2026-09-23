#include <stdio.h>
#include <stdlib.h>

/*
 * SITUACION (BUG): Division entera sin validar el divisor.
 * EXPLICACION: A diferencia de 1.0 / 0.0 (ver 05_division_por_cero_error.c),
 * la division ENTERA por cero no produce inf: el procesador lanza SIGFPE y el
 * programa muere. Hay un segundo caso menos conocido: INT_MIN / -1 tampoco
 * entra en un int (el resultado seria INT_MAX + 1) y tambien termina en
 * SIGFPE. Ambos son comportamiento indefinido segun el estandar.
 *
 * DIAGNOSTICO (desde la raiz de ejemplos/):
 *
 *   # 1. Ejecutar primero en el sandbox: clasifica el fallo sin riesgos.
 *   gcc -std=c11 -g aritmetica/contraejemplos/09_division_entera_por_cero_error.c -o /tmp/reparto
 *   nostromo run /tmp/reparto --stdin "10 3"            # 3
 *   nostromo run /tmp/reparto --stdin "10 0"            # FPE
 *   nostromo check /tmp/reparto aritmetica/casos_reparto/   # 2/4 aprobados
 *
 *   # 2. nostromo informo una senial (FPE): recien ahi, hal explica la causa.
 *   hal check aritmetica/contraejemplos/09_division_entera_por_cero_error.c --stdin "10 0"
 *   hal check aritmetica/contraejemplos/09_division_entera_por_cero_error.c --stdin "-2147483648 -1"
 *
 * Con "10 0", hal senala la linea 35 y nombra al divisor: 'personas' = 0.
 * Con "-2147483648 -1" el titulo de hal sigue diciendo "division por cero":
 * la explicacion es generica para SIGFPE. La tabla de argumentos muestra la
 * causa real (caramelos=-2147483648, personas=-1).
 *
 * La version correcta es ../ejemplos/09_division_entera_verificada_segura.c.
 */

static int por_persona(int caramelos, int personas)
{
    // BUG: no se valida que el divisor sea distinto de 0 ni el caso INT_MIN / -1
    return caramelos / personas;
}

int main(void)
{
    int caramelos = 0;
    int personas = 0;

    if (scanf("%d %d", &caramelos, &personas) != 2)
    {
        return EXIT_FAILURE;
    }

    printf("%d\n", por_persona(caramelos, personas));
    return EXIT_SUCCESS;
}
