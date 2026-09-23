/* 05_mapa_de_direcciones.c
 *
 * Comparación ilustrativa de direcciones entre datos globales
 * inicializados, bss, heap y pila para visualizar que provienen de
 * regiones distintas.El orden exacto entre ellas no está garantizado
 * por el estándar de C y depende del sistema operativo.
 */

#include <stdio.h>
#include <stdlib.h>

int global_inicializada = 42;
int global_bss;

int main(void)
{
    int local = 0;
    int *dinamica = malloc(sizeof *dinamica);

    if (dinamica == NULL)
    {
        return EXIT_FAILURE;
    }

    printf("datos (global inicializada):     %p\n",
           (void *)&global_inicializada);
    printf("bss   (global sin inicializar):   %p\n", (void *)&global_bss);
    printf("heap  (malloc):                   %p\n", (void *)dinamica);
    printf("pila  (variable local):           %p\n", (void *)&local);

    free(dinamica);
    return EXIT_SUCCESS;
}
