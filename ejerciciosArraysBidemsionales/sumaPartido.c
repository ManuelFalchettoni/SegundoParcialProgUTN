//Instrucciones:
/*Declarar una matriz de enteros de 2 filas x 4 columnas para representar los puntos por cuarto.
*Usar un array de caracteres bidimensional para guardar los nombres de los dos equipos: char
equipos[2][20];
Pedir al usuario que ingrese los nombres de los equipos (sin espacios). El 2 indica la cantidad de strings
que vamos a guardar y el 20 determina el largo máximo de cada cadena de caracteres. Es decir podemos
guardar 2 strings de como máximo 20 caracteres.
*Usar bucles anidados para cargar los puntos anotados por cada equipo en cada cuarto.
*Mostrar una tabla alineada con los puntos por cuarto y el total de cada equipo.
*Calcular y mostrar:
El total de puntos por equipo
Qué equipo ganó
En qué cuarto hubo la mayor diferencia de puntos (usar abs())
¿Qué cuarto fue el más parejo (menor diferencia)?*/

#include <stdio.h>
#include <stdlib.h>
#define FILAS 2
#define COLUMNAS 4
#define cantidadCaracteres 20

void llenarArray(int arr[FILAS][COLUMNAS], char equipos[FILAS][cantidadCaracteres]){
    for (int i = 0; i < FILAS; i++)
    {
        printf("%s\n", equipos[i]);
        for (int j = 0; j < COLUMNAS; j++)
        {
            printf("Ingrese los puntos en el cuarto numero %d: ", j + 1);
            scanf("%d", &arr[i][j]);
        }      
    }
}
void llenarEquipos(char equipos[FILAS][cantidadCaracteres]){
    for (int i = 0; i < FILAS; i++)
    {
        printf("Ingrese el nombre del equipo numero %d: ", i + 1);
        scanf("%s", equipos[i]);
    }
}
void calcularPuntosPorEquipo(int arr[FILAS][COLUMNAS], char equipos[FILAS][cantidadCaracteres], int *totalEquipo1, int *totalEquipo2){
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            if (i == 0)
            {
                *totalEquipo1 += arr[i][j];
            }
            else
            {
                *totalEquipo2 += arr[i][j];
            }
        }
    }
    printf("El total de puntos de %s es: %d\n",equipos[0], *totalEquipo1);
    printf("El total de puntos de %s es: %d\n",equipos[1], *totalEquipo2);
    //Mostrar equipo ganador 
    if (*totalEquipo1 > *totalEquipo2)
    {
        printf("El equipo ganador es %s\n", equipos[0]);
    }
    else if (*totalEquipo1 < *totalEquipo2)
    {
        printf("El equipo ganador es %s\n", equipos[1]);
    }
    else
    {
        printf("Empate entre %s y %s\n", equipos[0], equipos[1]);
    }
}
void calcularDiferencia(int arr[FILAS][COLUMNAS]){
    int mayorDiferencia = 0;
    int indiceCuartoMayorDiferencia = 0;
    int diferenciaMin = 1000;
    int indiceCuartoParejo = 0;
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            if (abs(arr[0][j] - arr[1][j]) > mayorDiferencia)
            {
                mayorDiferencia = abs(arr[0][j] - arr[1][j]);
                indiceCuartoMayorDiferencia = j;
            }
            if (abs(arr[0][j] - arr[1][j]) < diferenciaMin)
            {
                diferenciaMin = abs(arr[0][j] - arr[1][j]);
                indiceCuartoParejo = j;
            }
            
        }
    }
    printf("El cuarto con mayor diferencia es el cuarto %d\n", indiceCuartoMayorDiferencia + 1);
    printf("El cuarto mas parejo fue el %d\n", indiceCuartoParejo + 1);
}
void mostrarMatriz(int arr[FILAS][COLUMNAS], char equipos[FILAS][cantidadCaracteres], int totalEquipo1, int totalEquipo2){
    for (int i = 0; i < 5; i++)
    {
        printf("| %15d", i);
    }
    printf("| %15s\n",  "total");
    for (int i = 0; i < FILAS; i++)
    {
        printf("%15s", equipos[i]);
        for (int j = 0; j < COLUMNAS; j++)
        {
            printf("%15d", arr[i][j]);
        }
    if (i != 1)
    {
        printf("%15d", totalEquipo1);
    }else{
        printf("%15d", totalEquipo2);
    }
    printf("\n");
    }
    
    
}

int main(){
    char equipos[FILAS][cantidadCaracteres];
    llenarEquipos(equipos);
    int arr[FILAS][COLUMNAS];
    llenarArray(arr, equipos);
    int totalEquipo1 = 0;
    int totalEquipo2 = 0;
    calcularPuntosPorEquipo(arr, equipos, &totalEquipo1, &totalEquipo2);
    calcularDiferencia(arr);
    mostrarMatriz(arr, equipos, totalEquipo1, totalEquipo2);
    return 0;
}