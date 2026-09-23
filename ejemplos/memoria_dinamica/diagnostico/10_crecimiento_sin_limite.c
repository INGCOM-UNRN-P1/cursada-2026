/*
 * nostromo: el vector crece con realloc de forma correcta (puntero temporal,
 * verificación de NULL), pero la condición de corte nunca se cumple:
 * 'cantidad' avanza de a 2 y el objetivo es impar.El programa pide memoria
 * hasta agotar la del sistema.
 *
 * Ejecutar SOLO dentro de nostromo, con un límite de memoria:
 *
 *   gcc -std=c11 -g memoria_dinamica/diagnostico/10_crecimiento_sin_limite.c -o
 * /tmp/crecimiento nostromo run /tmp/crecimiento--memory 32
 *
 * Con 32 MB, realloc devuelve NULL cerca de ese límite.Como el código maneja
 * el error, el programa informa "sin memoria" y termina con EXIT_FAILURE
 * (nostromo lo clasifica como NON_ZERO). Fuera del sandbox el mismo programa
 * consumiría toda la RAM de la máquina antes de fallar.
 *
 * Por el mismo motivo NO ejecutarlo con hal ni con vasquez: ninguno de los
 * dos limita la memoria.vasquez corta a los 3 s, pero en ese tiempo el
 * programa ya puede haber reservado varios GB.
 *
 * Corrección: cortar con 'cantidad < objetivo' en lugar de '!='.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t capacidad = 4;
    size_t cantidad = 0;
    size_t objetivo = 1001;
    int *valores = malloc(capacidad * sizeof *valores);
    if (valores == NULL)
    {
        return EXIT_FAILURE;
    }

    /* Error: cantidad es siempre par y nunca vale 1001. */
    while (cantidad != objetivo)
    {
        if (cantidad + 2 > capacidad)
        {
            int *nuevo = realloc(valores, 2 * capacidad * sizeof *valores);
            if (nuevo == NULL)
            {
                fprintf(stderr, "sin memoria con %zu elementos\n", cantidad);
                free(valores);
                return EXIT_FAILURE;
            }
            valores = nuevo;
            capacidad = 2 * capacidad;
        }
        valores[cantidad] = (int)cantidad;
        valores[cantidad + 1] = (int)cantidad + 1;
        cantidad = cantidad + 2;
    }

    printf("%zu\n", cantidad);
    free(valores);
    return EXIT_SUCCESS;
}
