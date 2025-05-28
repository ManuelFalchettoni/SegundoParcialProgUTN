#include <stdio.h>

typedef struct 
{
    int legajo;
    char nombre[30];
    float sueldo;
}Empleado;

void mostrarEmpleados(Empleado arr[], int largo){
    for (int i = 0; i < largo; i++)
    {
        printf("%d - ", arr[i].legajo);
        printf("%s - ", arr[i].nombre);
        printf("%.2f \n", arr[i].sueldo);
    }
    
}
void buscarPorLegajo(Empleado arr[], int largo, int legajo){
    for (int i = 0; i < largo; i++)
    {
        if (arr[i].legajo == legajo)
        {
            printf("%d - ", arr[i].legajo);
            printf("%s - ", arr[i].nombre);
            printf("%.2f \n", arr[i].sueldo);
            return;
        }
    }
    printf("No se encontro ese legajo \n");
    
}

void aumentarSueldos(Empleado arr[], int largo, float porcentaje){
    for (int i = 0; i < largo; i++)
    {
        arr[i].sueldo += arr[i].sueldo *(porcentaje/ 100);
    }
    
}

int main(){
    int largo = 5;
    Empleado arr[] = {
        {1234, "Matias", 10000},
        {6283, "Sofia", 5000},
        {2534, "Santino", 2500},
        {8199, "Manuel", 15000},
        {5000, "Rocio", 7500}
    };
    mostrarEmpleados(arr, largo);
    buscarPorLegajo(arr, largo, 2534);
    aumentarSueldos(arr, largo, 10);
    printf("-----------------------\n");
    mostrarEmpleados(arr, largo);

    return 0;
}