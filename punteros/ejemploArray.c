#include <stdio.h>


int main(){
    int array[3] = {20, 30, 40};
    int *p = array;

    printf("Lo que tiene p: %p \n", p);
    printf("Lo que tiene *p: %d \n", *p);
    p++;
    printf("Lo que tiene p: %p \n", p);
    printf("Lo que tiene *p: %d \n", *p);
    return 0;
}