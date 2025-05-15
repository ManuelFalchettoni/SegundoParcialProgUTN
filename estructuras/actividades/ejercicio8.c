#include <stdio.h>

typedef struct 
{
    float longitud;
    float diametro;
}Tornillo;

void pedirInfo(Tornillo arr[], int largo){
    for (int i = 0; i < largo; i++)
    {
        printf("Ingrese las medidas del tornillo: (longitud Diametro)\n");
        scanf("%f %f", &arr[i].longitud, &arr[i].diametro);
    }
}
void calcularMedia(Tornillo arr[], int largo){
    float sumaLongitud = 0;
    float sumaDiametro = 0;

    for (int i = 0; i < largo; i++)
    {
        sumaDiametro += arr[i].diametro;
        sumaLongitud += arr[i].longitud;
    }
    float promLongitud;
    float promDiametro;
    promDiametro = sumaDiametro / largo;
    promLongitud = sumaLongitud / largo;

    printf("Promedio de Diametro: %.2f\n", promDiametro);
    printf("Promedio de Longitud: %.2f\n", promLongitud);
}
int main(){
    int largo = 2;
    Tornillo arr[largo];

    pedirInfo(arr, largo);
    calcularMedia(arr, largo);

    return 0;
}