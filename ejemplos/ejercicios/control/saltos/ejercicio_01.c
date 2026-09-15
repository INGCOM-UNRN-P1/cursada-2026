#include <stdio.h>

int main(void)
{
    int matriz[3][3] = {{1, 2, 3}, {4, 99, 6}, {7, 8, 9}};
    int buscado = 99;
    int encontrado = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Evaluando [%d][%d] = %d\n", i, j, matriz[i][j]);
            if (matriz[i][j] == buscado)
            {
                encontrado = 1;
                printf("Elemento %d encontrado. Saliendo...\n", buscado);
                break;
            }
        }
    }

    if (encontrado)
    {
        printf("Busqueda finalizada con exito.\n");
    }
    return 0;
}
