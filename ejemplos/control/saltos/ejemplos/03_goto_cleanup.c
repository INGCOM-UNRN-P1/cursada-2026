#include <stdbool.h>
#include <stdio.h>

/*
 * SITUACION: Sentencia 'goto' para gestion de errores y limpieza centralizada
 * de recursos.EXPLICACION: Uso valido y aceptado de 'goto' en C para saltar a
 * una seccion de desasignacion de recursos (cleanup) evitando la duplicacion de
 * codigo en multiples puntos de retorno.
 */

// Uso valido de goto: Limpieza centralizada de recursos
bool abrir_y_procesar(const char *ruta)
{
    FILE *arch = fopen(ruta, "r");
    if (!arch)
    {
        goto error_cleanup;
    }

    // Operaciones con el archivo...
    fclose(arch);
    return true;

error_cleanup:
    printf("Error al abrir archivo. Ejecutada seccion centralizada de "
           "limpieza.\n");
    return false;
}

int main(void)
{
    abrir_y_procesar("archivo_no_existente.txt");
    return 0;
}
