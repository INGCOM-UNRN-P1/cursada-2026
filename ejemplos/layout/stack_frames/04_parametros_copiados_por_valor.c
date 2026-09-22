/* 04_parametros_copiados_por_valor.c
 *
 * Los parámetros pasados por valor se copian dentro del marco de pila
 * de la función invocada. Modificar la copia no afecta al argumento
 * original que sigue en el marco de la función que llamó.
 */

#include <stdio.h>

void incrementar(int valor)
{
    valor = valor + 1;
    printf("dentro de incrementar: valor = %d (direccion: %p)\n",
           valor, (void *)&valor);
}

int main(void)
{
    int numero = 10;

    printf("en main antes: numero = %d (direccion: %p)\n",
           numero, (void *)&numero);
    incrementar(numero);
    printf("en main despues: numero = %d (sin cambios)\n", numero);

    return 0;
}
