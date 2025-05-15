#include <stdio.h>

typedef struct 
{
    int horas;
    int minutos;
    int segundos;
}Tiempo;


//Sumar dos estructuras de tiempo
int main(){
    Tiempo t1, t2, resultado;
    //Ingreso valores
    printf("Ingrese el tiempo 1 (horas minutos segundos): ");
    scanf("%d %d %d", &t1.horas, &t1.minutos, &t1.segundos);
    printf("Ingrese el tiempo 2 (horas minutos segundos): ");
    scanf("%d %d %d", &t2.horas, &t2.minutos, &t2.segundos);
    //Suma de tiempos
    resultado.horas = 0;
    resultado.minutos = 0;
    resultado.segundos = 0;
    // Sumar horas, minutos y segundos
    resultado.horas = t1.horas + t2.horas;
    resultado.minutos = t1.minutos + t2.minutos;
    resultado.segundos = t1.segundos + t2.segundos;
    // Normalizar segundos
    if(resultado.segundos >= 60){
        resultado.minutos += resultado.segundos / 60;
        resultado.segundos = resultado.segundos % 60;
    }
    // Normalizar minutos
    if(resultado.minutos >= 60){
        resultado.horas += resultado.minutos / 60;
        resultado.minutos = resultado.minutos % 60;
    }
    printf("El tiempo total es: %d horas, %d minutos, %d segundos\n", resultado.horas, resultado.minutos, resultado.segundos);
    return 0;
}
