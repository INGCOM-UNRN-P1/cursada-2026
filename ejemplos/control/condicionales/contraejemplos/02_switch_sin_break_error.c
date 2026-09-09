#include <stdio.h>

/*
 * SITUACION (BUG): Omision de 'break' en 'switch' (Fall-through involuntario).
 * EXPLICACION: Si un 'case' no finaliza con 'break', la ejecucion continua ejecutando las instrucciones
 * de los casos subsiguientes independientemente de sus etiquetas.
 */

int main(void) {
    int opcion = 1;

    // BUG: La omision de break causa fall-through involuntario hacia el caso siguiente
    switch (opcion) {
        case 1:
            printf("[BUG] Caso 1 ejecutado\n");
            /* Intentional fallthrough omission bug */
        case 2:
            printf("[BUG] Caso 2 ejecutado por fall-through no deseado\n");
            break;
    }
    return 0;
}
