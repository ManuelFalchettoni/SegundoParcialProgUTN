#include <stdio.h>
#include <stdlib.h>

int main(){

    int *ptr;

    ptr = (int *)malloc(5 * sizeof(int));

    if (ptr == NULL)
    {
        printf("Error al asignar memoria\n");
        return 1;
    }

    // Asignamos valores
    for (int i = 0; i < 5; i++)
    {
        ptr[i] = (i + 1) * 10; //Asignamos valores 10, 20 ,30.
    }

    //Imprimimos valores

    //Liberamos memoria
    free(ptr);
    return 0;
}