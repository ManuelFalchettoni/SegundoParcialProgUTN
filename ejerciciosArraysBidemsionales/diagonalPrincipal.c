//Crea una matriz de 10x10 con números aleatorios entre 200 y 300.
//Mostrá la matriz. Luego:
//•	Calculá el máximo, mínimo y promedio de los elementos de esa diagonal.
//•	Mostrá los elementos que están en la diagonal principal (de [0][0] a [9][9]).

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int matriz[10][10];
    int i, j, maximo, minimo, suma = 0;
    float promedio;
    srand(time(NULL)); // Inicializa la semilla para números aleatorios

    // Llenar la matriz con números aleatorios entre 200 y 300
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            matriz[i][j] = rand() % 101 + 200; // Números entre 200 y 300
        }
    }

    // Mostrar la matriz
    printf("Matriz:\n");
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            printf("%3d ", matriz[i][j]);// %3d para alinear los números en minimos de 3 espacios
        }
        printf("\n--------------------\n");
    }

    // Inicializar maximo y minimo con el primer elemento de la diagonal
    maximo = matriz[0][0];
    minimo = matriz[0][0];
    // Calcular el máximo, mínimo y suma de los elementos de la diagonal principal
    for(i = 0; i < 10; i++){
        suma += matriz[i][i]; // Sumar los elementos de la diagonal
        if(matriz[i][i] > maximo){
            maximo = matriz[i][i]; // Encontrar el máximo
        }
        if(matriz[i][i] < minimo){
            minimo = matriz[i][i]; // Encontrar el mínimo
        }
    }
    // Calcular el promedio
    promedio = (float)suma / 10.0; // Promedio de los elementos de la diagonal

    //Mostrar elementos de la diagonal principal
    printf("\nElementos de la diagonal principal:\n");
    for(i = 0; i < 10; i++){
        printf("%3d ", matriz[i][i]); // Mostrar los elementos de la diagonal
    }
    printf("\n--------------------\n");

    // Mostrar resultados
    printf("Maximo: %d\n", maximo);
    printf("Minimo: %d\n", minimo);
    printf("Promedio: %.2f\n", promedio);
    return 0;
}
