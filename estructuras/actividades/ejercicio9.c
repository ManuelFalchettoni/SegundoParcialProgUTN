#include <stdio.h>

typedef struct {
    int codigo;
    char descripcion[80];
    float precio;
}Producto;

void cargarArray(Producto arr[], int largo){
    for (int i = 0; i < largo; i++)
    {
        printf("Ingrese la informacion del producto %d\n", i +1);
        printf("Ingrese el codigo del producto: \n");
        scanf("%d", &arr[i].codigo);
        printf("Ingrese la descripcion del producto \n");
        scanf(" %[^\n]", arr[i].descripcion);
        printf("Ingrese el precio del producto \n");
        scanf("%f", &arr[i].precio);
    }
    
}

void imprimirArray(Producto arr[], int largo){
    for (int i = 0; i < largo; i++)
    {
        printf("Informacion del producto %d\n", i + 1);
        printf("Codigo: %d\n", arr[i].codigo);
        printf("Descripcion: %s\n", arr[i].descripcion);
        printf("Precio: %.2f\n", arr[i].precio);
    }
    
}

void mostrarPrecioMayor(Producto arr[], int largo){
    int max_idx = 0;

    for (int i = 0; i < largo; i++)
    {
        if (arr[max_idx].precio < arr[i].precio)
        {
            max_idx = i;
        }
    }
    printf("El articulo mas caro es: %s", arr[max_idx].descripcion);    
}

int main(){
    int largo = 6;
    Producto arr[largo];

    cargarArray(arr, largo);
    imprimirArray(arr, largo);
    mostrarPrecioMayor(arr, largo);



    return 0;
}