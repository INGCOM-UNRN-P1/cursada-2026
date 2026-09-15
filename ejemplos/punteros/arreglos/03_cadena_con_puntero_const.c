/* Una cadena literal no debe modificarse: se observa mediante const char*. */

#include <stdio.h>

/**
 * @brief Descripción de la función imprimir.
 *
 * @param texto Descripción del parámetro texto.
 */
void imprimir(const char *texto)
{
    while (*texto != '\0')
    {
        putchar(*texto);
        texto++;
    }
    putchar('\n');
}

int main(void)
{
    const char *mensaje = "punteros y cadenas";

    imprimir(mensaje);
    return 0;
}
