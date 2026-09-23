/*
 * Caso: documentar con una función de destrucción que el contenedor posee
 * la cadena y es responsable de liberarla junto con la estructura.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mensaje
{
    char *texto;
};

/**
 * @brief Descripción de la función destruir_mensaje.
 *
 * @param mensaje Descripción del parámetro mensaje.
 */
void destruir_mensaje(struct Mensaje *mensaje)
{
    if (mensaje != NULL)
    {
        free(mensaje->texto);
        free(mensaje);
    }
}

int main(void)
{
    const char origen[] = "ownership explicito";
    struct Mensaje *mensaje = malloc(sizeof *mensaje);
    if (mensaje == NULL)
    {
        return EXIT_FAILURE;
    }

    mensaje->texto = malloc(strlen(origen) + 1);
    if (mensaje->texto == NULL)
    {
        destruir_mensaje(mensaje);
        return EXIT_FAILURE;
    }
    strcpy(mensaje->texto, origen);

    puts(mensaje->texto);
    destruir_mensaje(mensaje);
    return EXIT_SUCCESS;
}
