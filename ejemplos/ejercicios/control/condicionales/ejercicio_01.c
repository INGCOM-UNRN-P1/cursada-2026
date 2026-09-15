#include <stdio.h>

int main(void)
{
    int edad = 70;

    if (18 <= edad && edad <= 65)
    {
        printf("Edad %d: Persona en edad laboral\n", edad);
    }
    else
    {
        printf("Edad %d: Fuera de rango laboral\n", edad);
    }
    return 0;
}
