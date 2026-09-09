#include <stdio.h>

/*
 * SITUACION: Condicional switch-case estructurado.
 * EXPLICACION: Selecciona una rama de ejecucion segun el valor de un entero o caracter.
 * Cada caso finaliza con 'break' para evitar la ejecucion en cascada no deseada.
 */

int main(void) {
    char opcion = 'B';

    switch (opcion) {
        case 'A':
            printf("Opcion A seleccionada\n");
            break;
        case 'B':
            printf("Opcion B seleccionada\n");
            break;
        default:
            printf("Opcion invalida\n");
            break;
    }
    return 0;
}
