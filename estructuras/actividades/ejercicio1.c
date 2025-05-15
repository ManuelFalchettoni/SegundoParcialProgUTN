#include <stdio.h>


typedef struct 
{
    char nombre[50];
    int edad;
    int legajo;
}Estudiante;

int main(){
    Estudiante e1 = {"Manuel", 22, 123654};
    Estudiante e2 = {"Matias", 33, 123456};

    printf("Persona 1 \n");
    printf("Nombre: %s\n", e1.nombre);
    printf("Edad: %d\n", e1.edad);
    printf("Legajo:  %d\n",e1.legajo);

    printf("Persona 2 \n");
    printf("Nombre: %s\n", e2.nombre);
    printf("Edad: %d\n", e2.edad);
    printf("Legajo:  %d\n",e2.legajo);



    return 0;
}
