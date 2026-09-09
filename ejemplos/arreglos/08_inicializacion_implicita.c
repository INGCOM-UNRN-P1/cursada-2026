/* 08_inicializacion_implicita.c
 *
 * También podemos omitir la capacidad cuando existe una lista
 * de inicialización.El compilador cuenta los elementos.
 *
 * Importante: esto sigue siendo un arreglo de tamaño fijo.
 */

#include <stdio.h>

int main(void)
{
    int implicita[] = {1, 2, 3};

    printf("Capacidad: %zu\n", sizeof(implicita) / sizeof(implicita[0]));

    return 0;
}
