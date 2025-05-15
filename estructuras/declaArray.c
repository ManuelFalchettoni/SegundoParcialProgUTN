#include <stdio.h>
#include <string.h>
typedef struct{
    int dia;
    int mes;
    int anio;
}FechaNacimiento;
struct Persona{
    char nombre[50];
    int edad;
    FechaNacimiento fecha;
};

int main(){
    /* struct Persona personas[] = {
        {"Matias", 33},
        {"Guido", 24},
        {"Rocio", 33}
    }; */
    
    struct Persona personas[3];
    for (int i = 0; i < 3; i++)
    {
        printf("Ingrese persona %d\n", i + 1);
        printf("Ingrese nombre: \n");
        scanf("%s", personas[i].nombre);
        printf("Ingrese edad: \n");
        scanf("%d", &personas[i].edad);
    }
    
    for (int i = 0; i < 3; i++)
    {
        printf("Persona %d\n", i + 1);
        printf("Nombre: %s\n", personas[i].nombre);
        printf("Edad: %d\n", personas[i].edad);
    }
    
    return 0;
}