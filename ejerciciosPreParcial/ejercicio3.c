#include <stdio.h>

//3 Sucursales y 4 meses
//Fila sucursal
//Columna mes


void mostrarTotalesPorSucursal(int ventas[3][4]){
    for (int i = 0; i < 3; i++)
    {
        int total = 0;
        for (int j = 0; j < 4; j++)
        {
            total += ventas[i][j];
        }
        printf("Total sucursal %d: %d\n", i + 1, total);
    }
    
} 

void mostrarTotalesPorMes(int ventas[3][4]){
    //Empezamos el array por j (Mes)
    for (int j = 0; j < 4; j++)
    {
        int total = 0;
        for (int i = 0; i < 3; i++)
        {
            total += ventas[i][j];
        }
        printf("Total en el mes %d: %d\n", j + 1, total);
    }
}

int sucursalMaxVentas(int ventas[3][4]){
    int idx_max = 0;
    int max = 0;
    for (int i = 0; i < 3; i++)
    {
        int total = 0;
        for (int j = 0; j < 4; j++)
        {
            total += ventas[i][j];
        }
        if (total > max){
            max = total;
            idx_max = i;
        }
    }
    return idx_max + 1;
}

float promedioVentas(int ventas[3][4]){
    float promedio = 0;
    int total = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            total += ventas[i][j];
        }
    }
        promedio = (float)total / (3 * 4);
        return promedio;
}


int main() {
    int ventas[3][4] = {
        {100, 200, 150, 175},
        {120, 180, 160, 190},
        {130, 210, 170, 185}
    };

    mostrarTotalesPorSucursal(ventas);
    mostrarTotalesPorMes(ventas);
    printf("La sucursal con mas ventas es la %d\n", sucursalMaxVentas(ventas));
    printf("El promedio de ventas es: %.2f\n", promedioVentas(ventas));


    return 0;
}