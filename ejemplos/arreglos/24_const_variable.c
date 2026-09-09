/* 24_const_variable.c
 *
 * const impide modificar una variable después de su inicialización.
 */
#define MASIMO 1000

#include <stdio.h>

int main(void)
{
    const int MAXIMO = 100;

    printf("MAXIMO = %d\n", MAXIMO);


     
      MAXIMO = 200;
     

    return 0;
}
