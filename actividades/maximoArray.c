#include <stdio.h>

void maximo(int arr[], int largo, int *max);
int main(){
    int largo = 5;
    int max = 0;
    int arr[] = {10,20,30,40,50};

    maximo(arr, largo, &max);
    printf("El numero maximo es %d", max);
    return 0;
}
void maximo(int arr[], int largo, int *max){
    int *ptr = arr;
    printf("Posicion inicial de *ptr: %p\n", ptr);
    for (int i = 0; i < largo; i++)
    {
        if (*(ptr + i) > *max)
        {
            *max = *(ptr + i);
        }
    }
    printf("Posicion puntero despues del for: %p", ptr);
}