/* 02_datos_no_inicializados_bss.c
 *
 * Una variable global sin inicializador explícito se ubica en el
 * segmento .bss. El sistema garantiza que arranca en cero, a diferencia
 * de una variable local automática sin inicializar.
 */

#include <stdio.h>

int contador_bss;

int main(void)
{
    printf("contador_bss = %d (direccion: %p)\n",
           contador_bss, (void *)&contador_bss);

    return 0;
}
