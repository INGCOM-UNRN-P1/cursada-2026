/* 41_cadena_modificable.c
 *
 * Si una función tiene permitido modificar el arreglo,
 * no utilizamos const en el parámetro.
 */

#include <stddef.h>
#include <stdio.h>

/**
 * @brief Descripción de la función poner_mayuscula_inicial.
 *
 * @param cadena Descripción del parámetro cadena.
 * @param capacidad Descripción del parámetro capacidad.
 */
void poner_mayuscula_inicial(char cadena[], size_t capacidad)
{
    if (capacidad == 0 || cadena[0] == '\0')
    {
        return;
    }

    if (cadena[0] >= 'a' && cadena[0] <= 'z')
    {
        cadena[0] = (char)(cadena[0] - 'a' + 'A');
    }
}

int main(void)
{
    char cadena[] = "juan";

    poner_mayuscula_inicial(cadena, sizeof(cadena));

    printf("%s\n", cadena);

    return 0;
}
