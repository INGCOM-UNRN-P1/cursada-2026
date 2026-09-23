#include <stdio.h>

/*
 * SITUACION (BUG): Punto y coma involuntario al final de 'while'.
 * EXPLICACION: Escribir 'while (condicion);' crea un lazo con cuerpo vacio.Si
 * la condicion depende del cuerpo, el programa entra en un lazo infinito
 * bloqueante antes de llegar a las llaves.
 */

int main(void)
{
    // BUG: Colocar punto y coma inmediatamente despues de la condicion de while
    // genera un lazo infinito de cuerpo vacio.
    printf("[BUG DEMO] 'while (condicion);' genera un lazo infinito "
           "bloqueante.\n");

    /*
        int k = 0;
        while (k < 5); {
            k++;
        }
    */
    return 0;
}
