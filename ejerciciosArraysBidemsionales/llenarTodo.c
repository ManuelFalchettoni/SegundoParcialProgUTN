#include <stdio.h>

//Crea un array de 2 filas por 5 columnas. Pedí al usuario que ingrese números enteros y completá toda la matriz con esos valores.
//Luego mostrala en formato de tabla.

int main(){
    int matriz[2][5]; // Declaración de la matriz de 2 filas y 5 columnas
    // Pedir al usuario que ingrese los números
    for (int i = 0; i < 2; i++) { // Recorre las filas
        for (int j = 0; j < 5; j++) { // Recorre las columnas
            printf("Elemento [%d][%d]: ", i, j); // Solicita el elemento en la posición [i][j]
            scanf("%d", &matriz[i][j]); // Lee el número ingresado por el usuario
        }
    }
    // Mostrar la matriz en formato de tabla
    printf("\nMatriz:\n");
    for (int i = 0; i < 2; i++) { // Recorre las filas
        for (int j = 0; j < 5; j++) { // Recorre las columnas
            printf("[%d] ", matriz[i][j]); // Imprime el elemento en la posición [i][j]
        }
        printf("\n"); // Salto de línea después de cada fila
    }
    return 0;
}
