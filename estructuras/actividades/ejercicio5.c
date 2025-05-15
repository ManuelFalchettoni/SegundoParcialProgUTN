#include <stdio.h>
#include <math.h>

typedef struct 
{
    int dia;
    int mes;
    int anio;
}Fecha;
int fechasEnDias(Fecha f){
    return f.anio * 365 + f.mes * 30 + f.dia;
}
int diferenciaDias(Fecha f1, Fecha f2){
    return abs(fechasEnDias(f2) - fechasEnDias(f1));
};

int main(){
    Fecha f1 = {9, 10, 2002};
    Fecha f2 = {5, 11, 2004};

    printf("La diferencia en dias es: %d",diferenciaDias(f1, f2));
    return 0;
}