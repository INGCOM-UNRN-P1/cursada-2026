#include <stdio.h>

/*
 * SITUACION: Mitigacion del error de redondeo acumulado en punto flotante.
 * EXPLICACION: Acumular operaciones en tipo float de 32 bits propaga errores de
 * precision.Se utiliza el tipo double (64 bits) o aritmetica de punto
 * fijo/escalado para reducir la perdida de precision.
 */

int main(void)
{
    // Para evitar la acumulación de error de redondeo en punto flotante,
    // se recomienda usar tipos de mayor precisión (double/long double) o
    // escalado entero.
    double suma = 0.0;
    for (int i = 0; i < 1000; i++)
    {
        suma += 0.1;
    }
    printf("Suma acumulada con double: %.10f\n", suma);
    return 0;
}
