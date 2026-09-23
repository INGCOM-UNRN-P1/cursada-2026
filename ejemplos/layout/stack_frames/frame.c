#include <stdio.h>

/**
 * @brief Descripción de la función puntero.
 * @return Descripción del valor de retorno.
 */
char *puntero()
{
    char cadena[] = "hello world";
    return cadena;
}

int main(void)
{
    printf("%s\n", puntero());
}
