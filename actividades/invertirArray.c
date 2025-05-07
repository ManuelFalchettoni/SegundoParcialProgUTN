#include <stdio.h>

void invertirArray(int arr[], int largo){
    int temp;
    int *ptr = arr;
    int j = largo - 1;
    for (int i = 0; i < j; i++)
    {
        temp = *(ptr + i);
        *(ptr + i) = *(ptr + j);
        *(ptr + j) = temp;
        j--;
    }
    
}
int main(){
    int largo = 10;
    int arr[] = {10,20,30,40,50,60,70,80,90,100};
    printf("Array original: \n");
    for (int i = 0; i < largo; i++)
    {
        printf("[%d] ", arr[i]);
    }
    printf("\n");
    invertirArray(arr, largo);

    printf("Array invertido: \n");
    for (int i = 0; i < largo; i++)
    {
        printf("[%d] ", arr[i]);
    }
    
    return 0;
}