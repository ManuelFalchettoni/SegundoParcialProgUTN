#include <stdio.h>

void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
int main(){
    int inter = 7;
    int barca = 6;

    swap(&inter, &barca);

    printf("Inter %d \n", inter);
    printf("Barca %d \n", barca);
    return 0;
}