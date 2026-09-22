/*
 * Caso: crear nodos enlazados dinámicamente, recorrer una lista y liberar
 * todos sus nodos desde el primero hasta el último.
 */

#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    int valor;
    struct Nodo *siguiente;
};

int main(void)
{
    struct Nodo *lista = NULL;

    for (int valor = 3; valor >= 1; valor--)
    {
        struct Nodo *nuevo = malloc(sizeof *nuevo);
        if (nuevo == NULL)
        {
            while (lista != NULL)
            {
                struct Nodo *siguiente = lista->siguiente;
                free(lista);
                lista = siguiente;
            }
            return EXIT_FAILURE;
        }
        nuevo->valor = valor;
        nuevo->siguiente = lista;
        lista = nuevo;
    }

    for (struct Nodo *actual = lista; actual != NULL; actual = actual->siguiente)
    {
        printf("%d%c", actual->valor, actual->siguiente == NULL ? '\n' : ' ');
    }

    while (lista != NULL)
    {
        struct Nodo *siguiente = lista->siguiente;
        free(lista);
        lista = siguiente;
    }

    return EXIT_SUCCESS;
}
