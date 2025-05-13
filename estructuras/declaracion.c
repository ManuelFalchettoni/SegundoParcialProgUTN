#include <stdio.h>
#include <string.h>

struct Alumno
{
    char nombre[40];
    int edad;
    int legajo;
};
//Comporbacion de dos estructuras iguales
int sonIguales(struct Alumno al1, struct Alumno al2){
    return (al1.edad == al2.edad && al1.legajo == al2.legajo && strcmp(al1.nombre, al2.nombre) == 0);
}
//Aumentar valor por referencia
void cumplirAnios(struct Alumno *al1){
    al1->edad += 1;
}
int main(){

    // Alumno 1
    struct Alumno a1;
    strcpy(a1.nombre, "Guido");
    a1.edad = 24;
    a1.legajo = 123456;

    //Alumno 2
    struct Alumno a2 ={"Guido", 24, 123456};

    if (sonIguales(a1, a2))
    {
        printf("Son iguales! \n");
    }else{
        printf("Son diferentes! \n");
    }
    
    printf("Nombre: %s\n", a1.nombre);
    printf("Edad: %d\n", a1.edad);
    printf("Legajo: %d\n", a1.legajo);

    //Alaumno 2
    printf("Nombre: %s\n", a2.nombre);
    printf("Edad: %d\n", a2.edad);
    printf("Legajo: %d\n", a2.legajo);
    
    //Aumentamos el valor
    cumplirAnios(&a1);

    if (sonIguales(a1, a2))
    {
        printf("Son iguales! \n");
    }else{
        printf("Son diferentes! \n");
    }
    
    printf("Nombre: %s\n", a1.nombre);
    printf("Edad: %d\n", a1.edad);
    printf("Legajo: %d\n", a1.edad);

    //Alaumno 2
    printf("Nombre: %s\n", a2.nombre);
    printf("Edad: %d\n", a2.edad);
    printf("Legajo: %d\n", a2.edad);

    return 0;
}
