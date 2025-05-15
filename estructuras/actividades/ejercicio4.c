#include <stdio.h>

typedef struct 
{
    int id;
    char nombre[50];
    int salario;
}Empleado;

void llenarDatos(Empleado arr[], int largo){
    printf("Llenar informacion empleados: \n");
    for (int i = 0; i < largo; i++)
    {
        printf("Empleado numero %d\n", i +1);
        printf("Ingrese ID del empleado: \n");
        scanf("%d", &arr[i].id);
        printf("Ingrese nombre del empleado: \n");
        scanf("%s",arr[i].nombre);
        printf("Ingrese salario del empleado: \n");
        scanf("%d",&arr[i].salario);
    }
    
};

void buscarMayor(Empleado arr[], int largo){
    int max_idx = 0;

    for (int i = 0; i < largo; i++)
    {
        if (arr[max_idx].salario < arr[i].salario)
        {
            max_idx = i;
        }
    }

    printf("Empleado con mayor salario: \n");
    printf("Nombre: %s\n", arr[max_idx].nombre);
    printf("ID: %d\n", arr[max_idx].id);
    printf("Salario: %d\n", arr[max_idx].salario);
    
};
int main(){
    int largo = 5;
    Empleado arr[largo];

    llenarDatos(arr, largo);
    buscarMayor(arr, largo);
    





    return 0;
}
