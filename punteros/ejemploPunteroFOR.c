#include <stdio.h>

int main(){
    char nombre[] = "Matias!";
    char *p = nombre;
    while(*p != '\0'){
        printf("%c", *p);
        p++;
    }
    return 0;
}