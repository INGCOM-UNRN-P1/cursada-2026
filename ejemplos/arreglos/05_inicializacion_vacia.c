/* 05_inicializacion_vacia.c
 *
 * Una declaración local sin inicialización no garantiza valores útiles.
 * Para enseñar esto no conviene depender de una salida concreta:
 * simplemente mostramos la forma correcta de inicializar.
 */

#include <stdio.h>

int main(void)
{
    int arreglo[5] = {};
    size_t len = sizeof(arreglo) / sizeof(arreglo[0]);
    for (size_t i = 0; i < len ; i++)
    {
        printf("arreglo[%zu] = %d\n", i, arreglo[i]);
    }

    return 0;
}
