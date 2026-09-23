#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    char *cadena = malloc(sizeof(char) * 100);
    //    if (cadena == NULL){
    //        printf("Changos, nos quedamos sin memoria\n");
    //    }
    cadena[0] = 'h';
    cadena[1] = 'o';
    cadena[2] = '\0';
    printf("%p\n%p\n", cadena, &cadena);

    free(cadena);

    cadena = NULL;
    return 0;
}
