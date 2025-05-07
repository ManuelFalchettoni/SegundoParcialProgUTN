/*Crear un programa que permita al usuario ingresar 15 números en un arreglo de enteros. El programa debe calcular diversas estadísticas sobre este arreglo utilizando funciones que reciban los datos por referencia y modifiquen variables a través de punteros.

 Requisitos: 
1. Crear las siguientes funciones: 
•	Una función para leer datos en un arreglo (recibe el 	arreglo y modifica su contenido)
 	
•	Una función para calcular múltiples estadísticas de un arreglo: suma, promedio, mayor, menor, cantidad de pares e impares 	(todos estos valores deben ser modificados por referencia, 	NO deben 	ser retornados por la función)
 	
•	Una función para imprimir un arreglo

2. Utilizar paso por referencia en todas las funciones que modifiquen datos.

3. El programa principal debe:
- Solicitar al usuario que ingrese los elementos del arreglo
- Mostrar el arreglo completo - Mostrar todas las estadísticas calculadas (suma, promedio, mayor valor, menor valor, cantidad de números pares y cantidad de números impares)
IMPORTANTE: 
- Debes utilizar aritmética de punteros en lugar de notación de índices donde sea posible.
- Para modificar variables dentro de las funciones, debes pasarlas por referencia (usando punteros).
- Recuerda que para modificar el valor al que apunta un puntero debes usar el operador de indirección (*).
PISTAS: 
- Para pasar una variable por referencia, debes pasar su dirección de memoria: &variable
- Para declarar un parámetro que recibe una referencia, usa un puntero: int *parametro
- Para acceder o modificar el valor referenciado, usa: *parametro - En arreglos, puedes acceder a los elementos con aritmética de punteros: *(arr + i) en lugar de arr[i]
- Para calcular estadísticas, debes inicializar los valores (por ejemplo, el mayor y menor pueden inicializarse con el primer elemento del arreglo)*/

#include <stdio.h>

void llenarArray(int *arr, int largo){
    int *ptr = arr;
    for (int i = 0; i < largo; i++)
    {
        printf("Ingrese un numero entero: \n");
        scanf("%d", ptr + i);
    }
    //Imprimir array
    for (int i = 0; i < largo; i++)
    {
        printf("[%d] ", *(ptr + i));
    }
    
}
void calcularValores(int *arr, int largo, int *suma, int *promedio, int *mayor, int *menor, int *pares, int *impares){
    int *ptr = arr;
    
    for (int i = 0; i < largo; i++)
    {
        //Encontrar minimo
        if (*(ptr + i) < *menor)
        {
            *menor = *(ptr + i);
        }
        if (*(ptr + i) > *mayor)
        {
            *mayor = *(ptr + i);
        }
        if (*(ptr + i) % 2 == 0)
        {
            (*pares)++;
        }else{
            (*impares)++;
        }
        *suma += *(ptr + i);
    }
    *promedio = *suma / largo;

    printf("El mayor es %d\n", *mayor);
    printf("El menor es %d\n", *menor);
    printf("La suma es %d\n", *suma);
    printf("El promedio es %d\n", *promedio);
    printf("La cantidad de impares es %d\n", *impares);
    printf("La cantidad de pares es %d\n", *pares);
    
}
void imprimirArray(int *arr, int largo){
    int *ptr = arr;
    for (int i = 0; i < largo; i++)
    {
        printf("[%d] ", *(ptr + i));
    }
    
}

int main(){
    int mayor = 0, promedio = 0, suma = 0,menor = 10000, pares = 0, impares = 0, largo = 15;
    int arr[] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150};
    //llenarArray(arr, largo);
    calcularValores(arr, largo, &suma, &promedio, &mayor, &menor, &pares, &impares);
    imprimirArray(arr, largo);
    return 0;
}


