/* El operador -> accede a un campo mediante un puntero a struct. */

#include <stdio.h>

struct Punto
{
    int x;
    int y;
};

/**
 * @brief Descripción de la función trasladar.
 *
 * @param punto Descripción del parámetro punto.
 * @param dx Descripción del parámetro dx.
 * @param dy Descripción del parámetro dy.
 */
void trasladar(struct Punto *punto, int dx, int dy)
{
    punto->x += dx;
    punto->y += dy;
}

int main(void)
{
    struct Punto punto = {2, 3};

    trasladar(&punto, 5, -1);
    printf("(%d, %d)\n", punto.x, punto.y);

    return 0;
}
