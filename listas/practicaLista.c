#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Nodo
{
    int numero;
    struct Nodo* siguiente;
}Nodo;

Nodo* crearNodo(int valor){
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));

    //Verificar si se puedo asignar memoria
    if (nuevoNodo == NULL)
    {
        printf("Error: No se pudo asignar memoria para el nodo\n");
        exit(1);
    }

    nuevoNodo->numero = valor;
    nuevoNodo->siguiente = NULL;

    return nuevoNodo;
}

void insertarAlFinal(Nodo** cabeza, int valor){
    //Crear el nodo a agregar al final
    Nodo* nuevoNodo = crearNodo(valor);
    //Si la lista esta vacia lo agregamos al principio, y es nuestra nueva cabeza.
    if(*cabeza == NULL){
        *cabeza = nuevoNodo;
        return;
    }

    //Encontrar ultimo nodo
    Nodo* temp = *cabeza;
    while (temp->siguiente != NULL)
    {
        temp = temp->siguiente;
    }
    //Guardamos al final
    temp->siguiente = nuevoNodo;
}

void mostrarLista(Nodo** cabeza){

    Nodo* actual = cabeza;




}

int main(){
    srand(time(NULL));
    Nodo* lista = NULL;







    return 0;
}