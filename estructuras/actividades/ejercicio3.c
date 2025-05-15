#include <stdio.h>

#define PI 3.1416

typedef struct 
{
    float radio;
}Circulo;

void calcularCirculos(Circulo c1, Circulo c2){
    float area1 = PI * c1.radio * c1.radio;
    float area2 = PI * c2.radio * c2.radio;

    float perimetro1 = 2 * PI * c1.radio;
    float perimetro2 = 2 * PI * c2.radio;

    //Primer circulo
    printf("Area del primer circulo: %.2f\n", area1);
    printf("Perimetro del primer circulo: %.2f\n", perimetro1);
    //Segundo circulo
    printf("Area del segundo circulo: %.2f\n", area2);
    printf("Perimetro del segundo circulo: %.2f\n", perimetro2);


}

int main(){

    Circulo c1 = {7.67};
    Circulo c2 = {5.67};

    calcularCirculos(c1, c2);


    return 0;
}