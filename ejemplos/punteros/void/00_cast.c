#include <stdio.h>

int main(void)
{

    int numero = 1000;
    void *ptr = &numero;
    int *int_ptr = (int *)ptr;

    printf("%zu/%zu/%zu\n", sizeof(numero), sizeof(ptr), sizeof(int_ptr));

    printf("Es %d \n", (*(int*)ptr)*2);
    printf("Es %d \n", *int_ptr);
    return 0;
}
