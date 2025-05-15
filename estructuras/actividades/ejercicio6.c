#include <stdio.h>

typedef struct 
{
    char titular[50];
    int numeroCuenta;
    float saldo;
}CuentaBancaria;

void ingresarDinero(CuentaBancaria *cb1, float cantidad){
    cb1->saldo += cantidad;
    printf("El saldo es %.2f", cb1->saldo);
}
int main(){
    CuentaBancaria cb1 = {"Manuel", 2313, 125000};
    float cantidad;
    printf("Ingrese la cantidad de dinero a depositar: \n");
    scanf("%f", &cantidad);

    ingresarDinero(&cb1, cantidad);





    return 0;
}