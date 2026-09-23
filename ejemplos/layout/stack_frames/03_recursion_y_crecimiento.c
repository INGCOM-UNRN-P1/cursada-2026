/* 03_recursion_y_crecimiento.c
 *
 * Cada llamada recursiva agrega un nuevo marco de pila.Observar cómo
 * la dirección de la variable local cambia con la profundidad permite
 * visualizar el crecimiento de la pila durante la recursión.
 */

#include <stdio.h>

/**
 * @brief Descripción de la función contar_regresivo.
 *
 * @param nivel Descripción del parámetro nivel.
 */
void contar_regresivo(int nivel)
{
    int marca = nivel;

    printf("nivel %d: marca (direccion: %p)\n", nivel, (void *)&marca);

    if (nivel > 0)
    {
        contar_regresivo(nivel - 1);
    }
}

int main(void)
{
    contar_regresivo(4);

    return 0;
}
