#include <stdio.h>

int main(void)
{
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printf("Inicializando matriz a cero...\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            matriz[i][j] = 0;
        }
    }
    return 0;
}
