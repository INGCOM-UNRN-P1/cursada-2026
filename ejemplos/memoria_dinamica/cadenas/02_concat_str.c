/*
 * Caso: construir dinámicamente una cadena concatenada calculando antes
 * la capacidad total para incluir ambos textos y el terminador.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char izquierda[] = "memoria ";
    const char derecha[] = "dinamica";
    size_t capacidad = strlen(izquierda) + strlen(derecha) + 1;
    char *resultado = malloc(capacidad);

    if (resultado == NULL)
    {
        return EXIT_FAILURE;
    }

    strcpy(resultado, izquierda);
    strcat(resultado, derecha);
    printf("%s\n", resultado);
    free(resultado);

    return EXIT_SUCCESS;
}
