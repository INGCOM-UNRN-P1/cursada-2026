#include <stdio.h>

int main(void)
{
    int iteraciones = 0;
    printf("Iterando flotante de 0.0 a 1.0:\n");
    for (float x = 0.0f; x != 1.0f; x += 0.1f)
    {
        iteraciones++;
        if (iteraciones > 15)
        {
            printf("detenido en x = %f\n", x);
            break;
        }
    }
    return 0;
}
