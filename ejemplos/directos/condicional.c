#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int x = 2;
    int y = 20;

    if (x > 5)
    {
        if (y < 15)
        {
            printf("En rango\n");
        }
        else
        {
            printf("y es muy grande\n");
        }
    }
    else
    {
        printf("x es muy chico\n");
    }

    return 0;
}
