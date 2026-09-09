/* 39_tres_cadenas.c
 *
 * Comparamos largo y capacidad en diferentes declaraciones.
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char primera[] = "Hola Mundo";
    char segunda[6] = "Programacion";
    char tercera[] = "Adios Mundo\n";

    printf("primera: %s\n", primera);
    printf("largo: %zu\n", strlen(primera));
    printf("capacidad: %zu\n\n", sizeof(primera));

    /*
     * segunda no debe tratarse como una cadena C válida:
     * la capacidad no permite almacenar todo "Programacion"
     * junto con el terminador.
     */
    printf("segunda: capacidad = %zu\n", sizeof(segunda));

    segunda[8] = 'Z';
    printf("segunda: %s\n", segunda);
    printf("tercera: %s\n", tercera);
    printf("largo: %zu\n", strlen(tercera));
    printf("capacidad: %zu\n", sizeof(tercera));

    return 0;
}
