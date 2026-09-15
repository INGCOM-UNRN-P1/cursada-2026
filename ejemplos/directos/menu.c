#include <stdio.h>

int main(void)
{
    char c = '0';
    int i = 0;
    do
    {
        scanf("%c", &c);
        switch (c)
        {
            case 'a':
                printf("Opcion A\n");
                break;
            case 'y':
                printf("Opcion y\n");
                i++;
                break;
            default:
                printf("Opcion incorrecta\n");
        }
    } while (i < 3);
    return 0;
}
