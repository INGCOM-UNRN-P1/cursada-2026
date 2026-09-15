#include <stdio.h>

int main(void)
{

    int n = 1;
    while (n % 2 != 0)
    {
        scanf("%d", &n);
    }
    printf("%d\n", n);
    return 0;
}
