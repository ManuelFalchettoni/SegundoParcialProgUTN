#include <stdio.h>

int longitud(char *str){
    int cont = 0;
    int *ptr = str;
    int i = 0;
    while (*(ptr + i) != '\0')
    {
        cont++;
        i++;
    }

    return cont;
}
int main(){
    //Usamos un asterisco antes para guardar la primera posicion del string
    char *nombre ="Manuel Falchettoni";
    printf("La longitud del string es %d", longitud(nombre));
    return 0;
}