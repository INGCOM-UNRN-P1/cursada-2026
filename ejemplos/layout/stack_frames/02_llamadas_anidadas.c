/* 02_llamadas_anidadas.c
 *
 * Las llamadas anidadas apilan marcos sucesivos, uno encima del otro.
 * En la mayoría de las arquitecturas comunes la pila crece hacia
 * direcciones de memoria menores a medida que se anidan más llamadas.
 */

#include <stdio.h>

/**
 * @brief Descripción de la función nivel_3.
 */
void nivel_3(void)
{
    int local = 3;

    printf("nivel_3: local = %d (direccion: %p)\n", local, (void *)&local);
}

/**
 * @brief Descripción de la función nivel_2.
 */
void nivel_2(void)
{
    int local = 2;

    printf("nivel_2: local = %d (direccion: %p)\n", local, (void *)&local);
    nivel_3();
}

/**
 * @brief Descripción de la función nivel_1.
 */
void nivel_1(void)
{
    int local = 1;

    printf("nivel_1: local = %d (direccion: %p)\n", local, (void *)&local);
    nivel_2();
}

int main(void)
{
    nivel_1();

    return 0;
}
