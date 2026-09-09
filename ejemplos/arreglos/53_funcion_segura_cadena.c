/* 53_funcion_segura_cadena.c
 *
 * Ejemplo de cierre alineado con la regla de la cátedra:
 *
 * toda función que manipula una cadena recibe la capacidad del buffer
 * y no debe escribir fuera de ella.
 *
 * La función copia como máximo capacidad - 1 caracteres y garantiza '\0'.
 */

#include <stddef.h>

/**
 * @brief Descripción de la función copiar_seguro.
 *
 * @param destino Descripción del parámetro destino.
 * @param capacidad Descripción del parámetro capacidad.
 * @param origen Descripción del parámetro origen.
 */
void copiar_seguro(char destino[], size_t capacidad, const char origen[])
{
    if (capacidad == 0)
    {
        return;
    }

    size_t i = 0;

    while (i + 1 < capacidad && origen[i] != '\0')
    {
        destino[i] = origen[i];
        i++;
    }

    destino[i] = '\0';
}
