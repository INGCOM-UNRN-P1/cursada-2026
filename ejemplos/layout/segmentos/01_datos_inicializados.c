/* 01_datos_inicializados.c
 *
 * Una variable global con un valor distinto de cero al declararse
 * se almacena en el segmento de datos (.data), no en la pila ni el heap.
 * Su dirección es fija durante toda la ejecución del programa.
 */

#include <stdio.h>

int contador_global = 100;

int main(void)
{
    printf("contador_global = %d (direccion: %p)\n",
           contador_global, (void *)&contador_global);

    return 0;
}
