#include <stdio.h>
void aMayusculas(char *nombre){
    int i = 0;

    while (nombre[i] != '\0')
    {
        if (nombre[i] >= 'a' && nombre[i] <= 'z')
        {
            nombre[i] = nombre[i] - 32;
        }
        i++;
    }
    printf("%s", nombre);
}
int main(){
    char nombre[] = "Matias!";
    printf("%s\n", nombre);
    aMayusculas(nombre);
    return 0;
}