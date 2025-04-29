#include <stdio.h>

//•	Los elementos que no se inicialicen tendrán valores basura si el array es local.
//•	Los elementos que no se inicialicen tendrán el valor 0 si el array es global o está declarado como static.
//Crea un array bidimensional de 3 filas por 4 columnas de enteros. Asigná manualmente algunos valores a ciertas posiciones (por ejemplo: [0][0], [1][2], etc.), dejando el resto vacíos.
//Mostrá el contenido de la matriz con printf.
//•	Usá un bucle for para recorrer las filas y otro bucle for anidado para recorrer las columnas.

int main(){
    int matriz[3][4] = {0}; // Inicializa la matriz con ceros
    // Asignación manual de algunos valores
    matriz[0][0] = 1;
    matriz[1][2] = 5;
    matriz[2][3] = 10;
    // Mostrar la matriz
    for (int i = 0; i < 3; i++)//3 filas
    {
        for (int j = 0; j < 4; j++)//4
        {
            printf("[%d] ", matriz[i][j]); // Imprime el elemento en la posición [i][j]
        }
        printf("\n"); // Salto de línea después de cada fila
    }
    return 0;
}
