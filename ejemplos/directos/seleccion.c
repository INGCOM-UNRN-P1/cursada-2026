#include <stdio.h>

int main(void)
{
    int i = 0;
    scanf("%d", &i);
    switch (i)
    {
        case 0:
            printf("cero\n");
            break;
        case 1:
            printf("uno\n");
            break;
        case 2:
            printf("dos\n");
            break;
        default:
            printf("otro\n");
    }
    return 0;
}
