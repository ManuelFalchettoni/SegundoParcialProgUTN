#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Crea una matriz de 6 filas por 10 columnas con números aleatorios entre 0 y 1000.
//Mostra la matriz y luego informa:
//•	El valor maximo y su posicion (fila y columna).
//•	El valor minimo y su posicion.

int main(){
    int matriz[6][10];
    int i, j;
    int max, min;
    int posMax[2], posMin[2];
    srand(time(NULL)); // Inicializa la semilla para números aleatorios

    // Llenar la matriz con números aleatorios entre 0 y 1000
    for(i = 0; i < 6; i++){
        for(j = 0; j < 10; j++){
            matriz[i][j] = rand() % 1001; // Números aleatorios entre 0 y 1000
        }
    }

    // Mostrar la matriz
    printf("Matriz:\n");
    for(i = 0; i < 6; i++){
        for(j = 0; j < 10; j++){
            printf("%4d ", matriz[i][j]);
        }
        //Indicar el fin de la fila
        printf("\n----------------------------\n");
    }

    // Inicializar max y min con el primer elemento de la matriz
    max = matriz[0][0];
    min = matriz[0][0];
    posMax[0] = 0; posMax[1] = 0;
    posMin[0] = 0; posMin[1] = 0;

    // Buscar el valor maximo y minimo y sus posiciones
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (matriz[i][j] > max){
                max = matriz[i][j];
                posMax[0] = i;//Fila
                posMax[1] = j;//Columna
            }
            if (matriz[i][j] < min){
                min = matriz[i][j];
                posMin[0] = i;//Fila
                posMin[1] = j;//Columna
            }
        }   
    }
    
    // Mostrar el valor maximo y su posicion
    printf("Valor maximo: %d en posicion (%d, %d)\n", max, posMax[0], posMax[1]);
    // Mostrar el valor minimo y su posicion
    printf("Valor minimo: %d en posicion (%d, %d)\n", min, posMin[0], posMin[1]);




    return 0;
}
