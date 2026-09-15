#include <stdio.h>

/**
 * @brief Descripción de la función buscar_posicion.
 *
 * @param arr Descripción del parámetro arr.
 * @param tam Descripción del parámetro tam.
 * @param clave Descripción del parámetro clave.
 * @return Descripción del valor de retorno.
 */
int buscar_posicion(const int *arr, int tam, int clave)
{
    for (int i = 0; i < tam; i++)
    {
        if (arr[i] == clave)
        {
            return i; // Retorna el indice si lo encuentra
        }
    }
    return -1; // Retorna -1 si no fue encontrado
}

int main(void)
{
    int datos[4] = {10, 20, 30, 40};
    int buscado = 99;

    int pos = buscar_posicion(datos, 4, buscado);

    /* ANALIZAR LA CONDICION DEL IF SEGÚN LA VERACIDAD EN C */
    if (pos)
    {
        printf("Elemento encontrado en el indice: %d\n", pos);
    }
    else
    {
        printf("Elemento no encontrado en el arreglo.\n");
    }

    return 0;
}
