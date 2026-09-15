#include <stdio.h>

/*
 * SITUACION (BUG): Acumulacion de error de redondeo en flotantes.
 * EXPLICACION: Sumar repetidamente 0.1f en precision simple 1000 veces
 * no da 100.0, sino un valor desviado (ej: 100.003357) debido a la acumulacion
 * del margen de error binario.
 */

int main(void)
{
    // BUG: Sumar valores en float de 32 bits acumula error de precisión
    // imprevisto
    float suma = 0.0f;
    for (int i = 0; i < 1000; i++)
    {
        suma += 0.1f;
    }
    printf("[BUG] Sumar 0.1f 1000 veces genera: %f (Esperado: 100.000000)\n",
           suma);
    return 0;
}
