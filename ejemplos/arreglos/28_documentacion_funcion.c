/* 28_documentacion_funcion.c
 *
 * Cuando una función recibe un arreglo, su contrato debe indicar:
 *
 * - qué representa el arreglo;
 * - qué representa la capacidad;
 * - qué precondiciones deben cumplirse;
 * - si el arreglo será modificado;
 * - qué queda garantizado al terminar.
 */

/**
 * Ordena un arreglo de enteros en el lugar.
 *
 * @param arreglo arreglo cuyos elementos serán ordenados.
 * @param capacidad cantidad de elementos válidos.
 *
 * Precondición:
 *     arreglo apunta a un arreglo válido de capacidad elementos.
 *
 * Postcondición:
 *     los mismos elementos quedan ordenados de menor a mayor.
 *
 * Efecto secundario:
 *     modifica el contenido de arreglo.
 */
void ordena(int arreglo[], size_t capacidad)
{
    for (size_t i = 0; i < capacidad; i++)
    {
        for (size_t j = i + 1; j < capacidad; j++)
        {
            if (arreglo[j] < arreglo[i])
            {
                int temporal = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = temporal;
            }
        }
    }
}
