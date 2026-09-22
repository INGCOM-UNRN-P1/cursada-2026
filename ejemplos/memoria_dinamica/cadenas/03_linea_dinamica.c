/*
 * Caso: leer una línea de longitud desconocida con un buffer que crece
 * mediante realloc, sin almacenar el salto de línea en el resultado.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t capacidad = 8;
    size_t longitud = 0;
    char *linea = malloc(capacidad);

    if (linea == NULL)
    {
        return EXIT_FAILURE;
    }

    int caracter;
    while ((caracter = getchar()) != '\n' && caracter != EOF)
    {
        if (longitud + 1 >= capacidad)
        {
            capacidad *= 2;
            char *temporal = realloc(linea, capacidad);
            if (temporal == NULL)
            {
                free(linea);
                return EXIT_FAILURE;
            }
            linea = temporal;
        }
        linea[longitud++] = (char)caracter;
    }
    linea[longitud] = '\0';

    printf("linea: %s\n", linea);
    free(linea);
    return EXIT_SUCCESS;
}
