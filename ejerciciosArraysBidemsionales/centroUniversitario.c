#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// En un centro universitario hay 3 carreras: Programación, Alimentos y Seguridad e higiene. Cada carrera tiene 3 años.
// Crea una matriz de 3x3 que almacene la cantidad de alumnos por año y carrera.
// Luego mostrala como tabla y calculá:
// •	La cantidad total de alumnos por carrera (suma por fila).
// •	La cantidad total por año (suma por columna).
// •	La carrera con mayor cantidad de alumnos.
// •	El total general de estudiantes.

#define CARRERAS 3
#define ANIOS 3
#define PROGRAMACION 0
#define ALIMENTOS 1
#define SEGURIDAD 2

void mostrarTabla(int matriz[CARRERAS][ANIOS])
{
    printf("Carrera\t Anio 1\t Anio 2\t Anio 3\n");
    printf("-------------------------------------\n");
    printf("Programacion\t %d\t %d\t %d\n", matriz[PROGRAMACION][0], matriz[PROGRAMACION][1], matriz[PROGRAMACION][2]);
    printf("Alimentos\t %d\t %d\t %d\n", matriz[ALIMENTOS][0], matriz[ALIMENTOS][1], matriz[ALIMENTOS][2]);
    printf("Seguridad\t %d\t %d\t %d\n", matriz[SEGURIDAD][0], matriz[SEGURIDAD][1], matriz[SEGURIDAD][2]);
    printf("-------------------------------------\n");
}

void llenarTabla(int matriz[CARRERAS][ANIOS])
{
    for (int i = 0; i < CARRERAS; i++)
    {
        for (int j = 0; j < ANIOS; j++)
        {
            matriz[i][j] = rand() % 75 + 1; // Generar un número aleatorio entre 1 y 75
        }
    }
}

void calcularTotales(int matriz[CARRERAS][ANIOS], int totalesCarrera[CARRERAS], int totalesAnio[ANIOS])
{
    int totalGeneral = 0; // Inicializar total general
    for (int i = 0; i < CARRERAS; i++)
    {
        totalesCarrera[i] = 0; // Inicializar en 0
    }
    for (int i = 0; i < ANIOS; i++)
    {
        totalesAnio[i] = 0; // Inicializar totales por año
        for (int j = 0; j < CARRERAS; j++)
        {
            totalesCarrera[j] += matriz[j][i]; // Sumar por carrera
            totalesAnio[i] += matriz[j][i];    // Sumar por año
            totalGeneral += matriz[j][i];      // Sumar total general
        }
    }
    printf("Total general de estudiantes: %d\n", totalGeneral);
    printf("Totales por carrera:\n");
    for (int i = 0; i < CARRERAS; i++)
    {
        printf("Carrera %d: %d\n", i + 1, totalesCarrera[i]);
    }
    printf("Totales por anio:\n");
    for (int i = 0; i < ANIOS; i++)
    {
        printf("Anio %d: %d\n", i + 1, totalesAnio[i]);
    }
}

int carreraMayorAlumnos(int matriz[CARRERAS][ANIOS])
{
    int mayor = 0;
    int carreraMayor = 0;
    for (int i = 0; i < CARRERAS; i++)
    {
        int sumaCarrera = 0;
        for (int j = 0; j < ANIOS; j++)
        {
            sumaCarrera += matriz[i][j];
        }
        if (sumaCarrera > mayor)
        {
            mayor = sumaCarrera;
            carreraMayor = i;
        }
    }
    return carreraMayor;
}

int main()
{
    srand(time(NULL));
    // Inicializar la matriz con 0
    int matriz[CARRERAS][ANIOS];
    int totalesCarrera[CARRERAS], totalesAnio[ANIOS];

    llenarTabla(matriz);
    mostrarTabla(matriz);
    calcularTotales(matriz, totalesCarrera, totalesAnio);
    int carreraMayor = carreraMayorAlumnos(matriz);
    printf("La carrera con mayor cantidad de alumnos es: %d\n", carreraMayor + 1); // +1 para mostrar el número de carrera en lugar de índice
    return 0;
}
// El programa crea una matriz de 3x3 que representa la cantidad de alumnos por año y carrera. Luego, muestra la tabla, calcula los totales por carrera y año, determina la carrera con mayor cantidad de alumnos y muestra el total general de estudiantes.
