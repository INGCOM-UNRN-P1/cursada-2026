/* 04_declaracion_arreglo.c
 *
 * La declaración especifica el tipo, el nombre y la cantidad de elementos.
 * En este ejemplo la capacidad es fija.
 */

#include <stdio.h>

#define CANTIDAD 5

int main(void)
{
    unsigned long long int size = 0;
    scanf("%ulld", &size);
    int arreglo[size];

    size_t largo = sizeof(arreglo) / sizeof(arreglo[0]);

    for (size_t i = 0; i < largo; i++)
    {
        arreglo[i] = (int)(i * i);
    }

    for (size_t i = 0; i < largo; i++)
    {
        printf("%zu -> %d\n", i, arreglo[i]);
    }

    printf("Capacidad: %zu elementos\n", sizeof(arreglo) / sizeof(arreglo[0]));

    return 0;
}
