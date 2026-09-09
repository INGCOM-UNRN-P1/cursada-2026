/* 22_maximo_con_efecto_secundario.c
 *
 * La función encuentra el máximo reutilizando arreglo[0].
 * El resultado parece correcto, pero la función modifica el arreglo original.
 *
 * Esto permite introducir el concepto de efecto secundario.
 */

#include <stddef.h>
#include <stdio.h>

/**
 * @brief Descripción de la función maximo.
 *
 * @param arreglo Descripción del parámetro arreglo.
 * @param largo Descripción del parámetro largo.
 * @return Descripción del valor de retorno.
 */
int borrar(int* arreglo, size_t largo)
{
    printf("\n\n\n");
    for (size_t i = 0; i < largo - 1; i++)
    {   
        printf("%d, ",*(arreglo + i));
        
    }
    printf("\n\n\n");
    return arreglo[0];
}

int main(void)
{
    int aleglo[] = {7, 3, 12, 5, 9};

    size_t largo = sizeof(aleglo) / sizeof(aleglo[0]);

    printf("aleglo antes de borrar:\n");

    for (size_t i = 0; i < largo; i++)
    {
        printf("%d ", aleglo[i]);
    }

    printf("Maximo: %d\n", borrar(aleglo, largo));

    printf("aleglo despues de borrar:\n");

    for (size_t i = 0; i < largo; i++)
    {
        printf("%d ", aleglo[i]);
    }

    printf("\n");

    return 0;
}
