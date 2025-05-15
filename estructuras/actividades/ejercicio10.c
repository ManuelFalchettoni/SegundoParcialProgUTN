#include <stdio.h>
#include <string.h>

typedef struct 
{
    int codigo;
    char categoria;
    char nombre[30];
    int salario;
}Empleado;

void informacionTotal(Empleado arr[]){
    int cantMayor20k = 0;
    int cantMenor5kYC = 0;
    int max_idx = 0, min_idx = 0;
    int importeTotal = 0, totalA = 0, totalB = 0, totalC = 0;
    float promedio;

    for (int i = 0; i < 5; i++)
    {
        //Suma cada salario para el total
        importeTotal += arr[i].salario;
        //Mayores a 20000
        if (arr[i].salario > 20000)
        {
            cantMayor20k++;
        }
        //Menor de 5000 y categoria C
        if (arr[i].salario < 5000 && arr[i].categoria == 'C')
        {
            cantMenor5kYC++;
        }
        //Salario mayor
        if(arr[max_idx].salario < arr[i].salario){
            max_idx = i;
        }
        //Sueldo minimo
        if (arr[min_idx].salario > arr[i].salario)
        {
            min_idx = i;
        }
        //Sueldos por categoria
        if (arr[i].categoria == 'A')
        {
            totalA += arr[i].salario;
        }else if (arr[i].categoria == 'B')
        {
            totalB += arr[i].salario;
        }else{
            totalC += arr[i].salario;
        }
        if (strcmp(arr[i].nombre, "Juan") == 0)
        {
            printf("Codigo: %d\n",arr[i].codigo);
            printf("Categoria: %c\n", arr[i].categoria);
            printf("Nombre: %s\n", arr[i].nombre);
            printf("Salario: %d\n", arr[i].salario);
        }    
    }
    
    printf("El importe total es: %d\n", importeTotal);
    printf("Cantidad de empleados que ganan mas que 20k: %d\n", cantMayor20k);
    printf("Cantidad menos de 5k y categoria C: %d\n", cantMenor5kYC);
    printf("El codigo del empleado que mas gana es: %d\n", arr[max_idx].codigo);
    printf("El sueldo mas bajo es: %d\n", arr[min_idx].salario);
    promedio = (float)importeTotal / 5;
    printf("El salario promedio es: %.2f\n", promedio);


}

int main(){
    Empleado arr[] = {
        {1, "A", "Manuel", 50000},
        {2, "B", "Juan", 3500},
        {3, "C", "Santi" ,25000},
        {4, "B", "Mati", 15000},
        {5, "C", "Valen" ,2000}
    };

    informacionTotal(arr);




    return 0;
}