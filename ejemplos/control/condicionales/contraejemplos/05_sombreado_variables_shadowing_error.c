#include <stdio.h>

/*
 * SITUACION (BUG): Sombreado de variables (Variable Shadowing).
 * EXPLICACION: Declarar una variable dentro de un bloque interno con el mismo nombre que una variable externa
 * oculta la variable externa, provocando que modificaciones dentro del bloque no afecten a la externa.
 */

int main(void) {
    int valor = 100;

    if (valor > 50) {
        // BUG: Re-declarar 'valor' en un bloque interno oculta (shadowing) la variable externa
        int valor = 5;
        printf("[BUG] Valor dentro del bloque interno: %d\n", valor);
    }

    printf("Valor en el bloque externo: %d\n", valor);
    return 0;
}
