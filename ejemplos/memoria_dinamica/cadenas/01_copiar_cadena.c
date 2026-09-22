/*
 * Caso: reservar exactamente el espacio de una cadena, copiarla y
 * conservar el terminador nulo mediante strlen + 1.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char original[] = "memoria";
    char *copia = malloc((strlen(original) + 1) * sizeof *copia);

    if (copia == NULL)
    {
        return EXIT_FAILURE;
    }

    strcpy(copia, original);
    printf("%s\n", copia);
    free(copia);

    return EXIT_SUCCESS;
}
