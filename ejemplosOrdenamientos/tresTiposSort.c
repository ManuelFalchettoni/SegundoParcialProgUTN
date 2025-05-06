/*En este ejercicio, trabajarás con un array de 10 calificaciones ya definido. Deberás
implementar tres funciones diferentes de ordenamiento y un menú que permita elegir qué
algoritmo utilizar. Para cada algoritmo, deberás contar y mostrar:
El número de comparaciones realizadas
El número de intercambios ejecutados
El array ordenado resultante*/




#include <stdio.h>

void bubbleSort(float arr[], int n);
void insertionSort(float arr[], int n);
void selectionSort(float arr[], int n);
void imprimirArray(float arr[], int n);

#define LARGO 10

int main(){
    float array[LARGO] = {7.5, 5.0, 9.2, 6.8, 8.1, 4.3, 7.0, 5.5, 9.9, 6.0};
    int num;
    printf("Opcion 1: Bubble Sort\n");
    printf("Opcion 2: Insertion Sort\n");
    printf("Opcion 3: Selection Sort\n");
    printf("Opcion 4: Imprimir array\n");
    printf("Opcion 5: Salir\n");
    do
    {
        printf("Ingrese una opcion: \n");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            bubbleSort(array, LARGO);
            break;
        case 2:
            insertionSort(array, LARGO);
            break;
        case 3:
            selectionSort(array, LARGO);
            break;
        case 4:
            imprimirArray(array, LARGO);
            break;
        default:
            break;
        }

    } while (num != 5);
    
    return 0;
}

void bubbleSort(float arr[], int n){
    printf("Ordenado por Bubble Sort: \n");
    float copia[n];
    for (int i = 0; i < n; i++)
    {
        copia[i] = arr[i];
    }
    int comparaciones = 0;
    int intercambios = 0;

    float temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (copia[j] > copia[j + 1])
            {
                temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
                intercambios++;
            }
            comparaciones++;
        }
        
    }
    printf("Array ordenado\n");
    for (int i = 0; i < n; i++)
    {
        printf("[%.1f] ", copia[i]);
    }
    printf("\nComparaciones: %d \n", comparaciones);
    printf("Intercambios: %d \n", intercambios);
    
    
};
void insertionSort(float arr[], int n){
    printf("Ordenado por Insertion Sort: \n");
    float copia[n];
    for (int i = 0; i < n; i++)
    {
        copia[i] = arr[i];
    }
    int comparaciones = 0;
    int intercambios = 0;
    float temp;
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        temp = copia[i];

        while (j >= 0 && copia[j] > temp)
        {
            copia[j + 1] = copia[j];
            j--;
            comparaciones++;
            intercambios++;
        }
        copia [j + 1] = temp;
        intercambios++;
    }
    printf("Array ordenado\n");
    for (int i = 0; i < n; i++)
    {
        printf("[%.1f] ", copia[i]);
    }
    printf("\nComparaciones: %d \n", comparaciones);
    printf("Intercambios: %d \n", intercambios);
};
void selectionSort(float arr[], int n){
    printf("Ordenado por Selection Sort: \n");
    float copia[n];
    for (int i = 0; i < n; i++)
    {
        copia[i] = arr[i];
    }
    int comparaciones = 0;
    int intercambios = 0;
    int min_idx;
    float temp;
    
    for (int i = 0; i < n - 1; i++)
    {
        //Buscar el indice del valor con menor valor.
        min_idx = i;
        for (int j = i + 1; j < n ; j++)
        {
            if (copia[j] < copia[min_idx])
            {
                min_idx = j;
            }
            comparaciones++;
        }

        if (min_idx != i)
        {
            temp = copia[min_idx];
            copia[min_idx] = copia[i];
            copia[i] = temp;
            intercambios++;
        } 
    } 
    printf("Array ordenado\n");
    for (int i = 0; i < n; i++)
    {
        printf("[%.1f] ", copia[i]);
    }
    printf("\nComparaciones: %d \n", comparaciones);
    printf("Intercambios: %d \n", intercambios);
};
void imprimirArray(float arr[], int n){
    printf("Array original: \n");
    for (int i = 0; i < n; i++)
    {
        printf("[%.1f] ", arr[i]);
    }
    printf("\n");
};