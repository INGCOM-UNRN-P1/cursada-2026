#include <stdio.h>

int main(void)
{
    int nivel_acceso = 1; // 1: Usuario, 2: Editor, 3: Admin

    printf("Permisos asignados:\n");
    switch (nivel_acceso)
    {
        case 1:
            printf("  - Lectura de contenido\n");
        case 2:
            printf("  - Edicion de contenido\n");
            break;
        case 3:
            printf("  - Administracion total\n");
            break;
        default:
            printf("  - Sin acceso\n");
            break;
    }
    return 0;
}
