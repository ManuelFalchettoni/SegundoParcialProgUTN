#include <stdio.h>
#define FILAS 3
#define COLUMNAS 3

void llenarArray(int arr[FILAS][COLUMNAS]){

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            printf("Ingrese una fecha (dd mm aaaa): ");
            scanf("%d", &arr[i][j]);
        }
        
    }
    



}
void mostrarArray(int arr[FILAS][COLUMNAS]){
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            printf("%d \t", arr[i][j]);
        }
        printf("\n");
    }
    
}
int main(){
    int matriz[FILAS][COLUMNAS];
    llenarArray(matriz);
    printf("Las fechas ingresadas son:\n");
    mostrarArray(matriz);
    return 0;
}