/* 05_variables_locales_no_sobreviven.c
 *
 * Al retornar una función, su marco de pila se recicla. La misma
 * región de memoria puede reaparecer en la siguiente llamada porque
 * ningún dato persiste entre invocaciones de funciones distintas.
 */

#include <stdio.h>

void primera_llamada(void)
{
    int local = 111;

    printf("primera_llamada: local = %d (direccion: %p)\n",
           local, (void *)&local);
}

void segunda_llamada(void)
{
    int local;

    /* El valor observado puede coincidir con el de la llamada anterior
     * porque ambas funciones reutilizan la misma región de la pila. */
    printf("segunda_llamada: local sin inicializar (direccion: %p)\n",
           (void *)&local);
}

int main(void)
{
    primera_llamada();
    segunda_llamada();

    return 0;
}
