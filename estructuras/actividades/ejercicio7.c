#include <stdio.h>
#include <string.h>


typedef struct 
{
    char titulo[50];
    char autor[50];
    int anio;
    int prestado;
}FichaLibro;

int sonIguales(FichaLibro libro1, FichaLibro libro2){
    return (strcmp(libro1.titulo, libro2.titulo) && (strcmp(libro1.autor, libro2.autor)) && (libro1.anio == libro2.anio) && (libro1.prestado == libro2.prestado));


}

int main(){
    FichaLibro libro1 = {"Game of Thrones", "Lampard", 2010, 1};
    FichaLibro libro2 = {"Harry Potter", "Messi", 2007, 0};

    if (sonIguales(libro1, libro2))
    {
        printf("Son iguales!!\n");
    }else{
        printf("Son diferentes!\n");
    }
    return 0;
}