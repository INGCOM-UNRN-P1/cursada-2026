/* 52_transformar_cadena.c
 *
 * Integración final:
 *
 * - arreglo de char
 * - capacidad
 * - recorrido
 * - const cuando solo leemos
 * - modificación explícita cuando corresponde
 * - ctype.h
 */

#include <ctype.h>
#include <stdio.h>

/**
 * @brief Descripción de la función pasar_a_mayusculas.
 *
 * @param cadena Descripción del parámetro cadena.
 * @param capacidad Descripción del parámetro capacidad.
 */
void pasar_a_mayusculas(char cadena[], size_t capacidad)
{
    for (size_t i = 0; i < capacidad && cadena[i] != '\0'; i++)
    {
        cadena[i] = (char)toupper((unsigned char)cadena[i]);
    }
}

int main(void)
{
    char cadena[] = "Programacion 1";

    pasar_a_mayusculas(cadena, sizeof(cadena));

    printf("%s\n", cadena);

    return 0;
}
