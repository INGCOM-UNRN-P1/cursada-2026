/* 01_marco_simple.c
 *
 * Cada llamada a una función crea un marco de pila (stack frame) que
 * contiene sus variables locales y parámetros.El marco se destruye
 * automáticamente al retornar la función.
 */

#include <stdio.h>

/**
 * @brief Descripción de la función imprimir_marco.
 */
void imprimir_marco(void)
{
    int valor_local = 5;

    printf("dentro de imprimir_marco: valor_local = %d (direccion: %p)\n",
           valor_local, (void *)&valor_local);
}

int main(void)
{
    printf("antes de llamar a imprimir_marco\n");
    imprimir_marco();
    printf("despues de llamar a imprimir_marco\n");

    return 0;
}
