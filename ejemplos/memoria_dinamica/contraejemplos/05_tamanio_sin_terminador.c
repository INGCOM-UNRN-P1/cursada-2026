/*
 * Contraejemplo: reservar strlen caracteres no deja espacio para '\0';
 * copiar luego la cadena escribe un byte fuera del bloque.
 */

#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char texto[] = "C";
    char *copia = malloc(strlen(texto));
    if (copia == NULL)
    {
        return EXIT_FAILURE;
    }

    strcpy(copia, texto);
    free(copia);
    return EXIT_SUCCESS;
}
