/*
 * Caso: liberar un bloque y asignar NULL al puntero para dejar explícito
 * que ya no posee un objeto válido; free(NULL) también es seguro.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *buffer = malloc(16);

    if (buffer == NULL)
    {
        return EXIT_FAILURE;
    }

    buffer[0] = 'C';
    buffer[1] = '\0';
    printf("%s\n", buffer);

    free(buffer);
    buffer = NULL;
    free(buffer);

    return EXIT_SUCCESS;
}
