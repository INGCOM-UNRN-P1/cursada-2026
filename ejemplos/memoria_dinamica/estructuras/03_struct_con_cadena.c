/*
 * Caso: una estructura posee dos recursos dinámicos independientes:
 * primero se libera la cadena interna y después la estructura contenedora.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Producto
{
    char *nombre;
    double precio;
};

int main(void)
{
    const char texto[] = "cuaderno";
    struct Producto *producto = malloc(sizeof *producto);
    if (producto == NULL)
    {
        return EXIT_FAILURE;
    }

    producto->nombre = malloc(strlen(texto) + 1);
    if (producto->nombre == NULL)
    {
        free(producto);
        return EXIT_FAILURE;
    }

    strcpy(producto->nombre, texto);
    producto->precio = 1250.0;
    printf("%s: %.2f\n", producto->nombre, producto->precio);

    free(producto->nombre);
    free(producto);
    return EXIT_SUCCESS;
}
