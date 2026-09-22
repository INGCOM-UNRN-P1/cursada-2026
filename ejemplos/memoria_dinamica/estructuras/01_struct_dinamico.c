/*
 * Caso: reservar una estructura completa, inicializar sus campos mediante
 * -> y liberar el objeto cuando deja de ser necesario.
 */

#include <stdio.h>
#include <stdlib.h>

struct Persona
{
    char inicial;
    int edad;
};

int main(void)
{
    struct Persona *persona = malloc(sizeof *persona);

    if (persona == NULL)
    {
        return EXIT_FAILURE;
    }

    persona->inicial = 'M';
    persona->edad = 20;
    printf("%c tiene %d anos\n", persona->inicial, persona->edad);

    free(persona);
    return EXIT_SUCCESS;
}
