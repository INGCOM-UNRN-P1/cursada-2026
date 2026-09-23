#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * SOLUCION: Validar el divisor antes de una division entera.
 * EXPLICACION: La division entera solo esta definida si el divisor es
 * distinto de 0 y el cociente entra en el tipo.Para int, el unico cociente
 * que no entra es INT_MIN / -1. La funcion informa si pudo dividir y deja el
 * resultado en un parametro de salida.
 *
 * VERIFICACION (desde la raiz de ejemplos/):
 *
 *   gcc -std=c11 -g aritmetica/ejemplos/09_division_entera_verificada_segura.c
 * -o /tmp/reparto_ok nostromo check /tmp/reparto_ok aritmetica/casos_reparto/
 * # 4/4 aprobados
 *
 * Comparar con ../contraejemplos/09_division_entera_por_cero_error.c, que
 * falla con la misma suite de casos.
 */

static bool por_persona(int caramelos, int personas, int *resultado)
{
    if (personas == 0 || (caramelos == INT_MIN && personas == -1))
    {
        return false;
    }
    *resultado = caramelos / personas;
    return true;
}

int main(void)
{
    int caramelos = 0;
    int personas = 0;

    if (scanf("%d %d", &caramelos, &personas) != 2)
    {
        return EXIT_FAILURE;
    }

    int resultado = 0;
    if (!por_persona(caramelos, personas, &resultado))
    {
        printf("no se puede repartir\n");
        return EXIT_SUCCESS;
    }

    printf("%d\n", resultado);
    return EXIT_SUCCESS;
}
