#include <stdio.h>

typedef struct 
{
    char nombre[60];
    int edad;
}Alumno;

void ingresarAlumnos(Alumno arr[], int largo){
    char nombre;
    int cont = 0;
    do
    {
        printf("Ingrese el nombre del alumno: \n");
        scanf("%s", &nombre);
        if (nombre == '*');
        {
            break;
        }
        arr[cont].nombre = nombre;

        printf("Ingrese la edad del alumno: %d");
        scanf("%d", &arr[cont].edad);




        cont++;
    } while (cont < largo);
    int cantMayor30 = 0;
    float promedio;

    for (int i = 0; i < largo; i++)
    {
        if (arr[i].edad >= 30)
        {
            cantMayor30++;
        }
        
    }
    
    
}

int main(){
    int largo = 5;
    Alumno arr[largo];

    //Falta agregar propiedad notas 




    return 0;
}