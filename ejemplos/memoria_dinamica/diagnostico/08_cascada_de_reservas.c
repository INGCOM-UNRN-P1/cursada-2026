/*
 * vasquez: una lista enlazada con cleanup correcto ante cualquier fallo de
 * malloc. Sirve para recorrer todos los caminos de error: fallar en cada
 * llamada (1, 2, 3, ...), en cascada o de forma probabilística.
 *
 *   vasquez inject memoria_dinamica/diagnostico/08_cascada_de_reservas.c --fail-malloc-at 3 --check-leaks
 *   vasquez inject memoria_dinamica/diagnostico/08_cascada_de_reservas.c --fail-malloc-at 2 --cascade --check-leaks
 *   vasquez stress memoria_dinamica/diagnostico/08_cascada_de_reservas.c -n 20 -p 0.3
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int valor;
    struct nodo *siguiente;
} nodo_t;

static void destruir(nodo_t *lista)
{
    while (lista != NULL)
    {
        nodo_t *siguiente = lista->siguiente;
        free(lista);
        lista = siguiente;
    }
}

static nodo_t *construir(int cantidad)
{
    nodo_t *lista = NULL;

    for (int i = cantidad; i > 0; i--)
    {
        nodo_t *nuevo = malloc(sizeof *nuevo);
        if (nuevo == NULL)
        {
            destruir(lista);
            return NULL;
        }
        nuevo->valor = i;
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    return lista;
}

int main(void)
{
    nodo_t *lista = construir(5);
    if (lista == NULL)
    {
        fprintf(stderr, "No se pudo construir la lista\n");
        return EXIT_FAILURE;
    }

    for (nodo_t *actual = lista; actual != NULL; actual = actual->siguiente)
    {
        printf("%d ", actual->valor);
    }
    printf("\n");
    destruir(lista);
    return EXIT_SUCCESS;
}
