/* 40_cadena_funcion_const.c
 *
 * Una función que solamente consulta una cadena debe recibirla como const.
 * También recibe su capacidad porque el arreglo no transporta esa información
 * al entrar en la función.
 */

#include <stddef.h>
#include <stdio.h>

/**
 * @brief Descripción de la función imprimir_cadena.
 *
 * @param cadena Descripción del parámetro cadena.
 * @param capacidad Descripción del parámetro capacidad.
 */
void imprimir_cadena(const char cadena[], size_t capacidad)
{
    printf("Cadena: %s\n", cadena);
    printf("Capacidad: %zu\n", capacidad);
}

int main(void)
{
    char cadena[] = "Martin";

    imprimir_cadena(cadena, sizeof(cadena));

    return 0;
}
