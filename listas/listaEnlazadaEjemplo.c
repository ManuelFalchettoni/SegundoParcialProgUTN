#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int numero; //Valor del nodo
    struct Nodo* siguiente; //Puntero al siguiente nodo
}Nodo;

Nodo* crearNodo (int valor){
    //Reservar memoria para el nuevo nodo
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo)); //Puntero a un nuevo nodo

    //Verificar si se puedo asignar memoria
    if (nuevoNodo == NULL)
    {
        printf("Error: No se pudo asignar memoria para el nodo\n");
        exit(1);
    }

    //Inicializar el nodo con el valor dado y sin siguiente nodo
    nuevoNodo->numero = valor; //Guardamos el valor
    nuevoNodo->siguiente = NULL; //Al ser el ultimo de la lista no tendria siguiente

    return nuevoNodo;
}

void insertarAlFinal(Nodo** cabeza, int valor){
    //Crear un nuevo nodo 
    Nodo* nuevoNodo = crearNodo(valor); //Un puntero a un nuevo nodo


    //Si la lista esta vacia, el nuevo nodo sera la cabeza
    if (*cabeza == NULL)
    {
        *cabeza = nuevoNodo;
        return;
    }

    //Encontrar al ultimo nodo
    Nodo* temp = *cabeza;
    while (temp->siguiente != NULL)
    {
        temp = temp->siguiente;
    }

    //Insertar el nuevo nodo despues del ultimo nodo
    temp->siguiente = nuevoNodo;
    
}

void insertarAlInicio(Nodo** cabeza, int valor){
//Crear un nuevo nodo

Nodo* nuevoNodo = crearNodo(valor);

//El siguiente del nuevo nodo guardamos el que estaba primero
nuevoNodo->siguiente = *cabeza;

//La nueva cabeza sera el nuevo nodo (Es decir el primero ahora sera el nuevoNodo que agregamos al inicio)
*cabeza = nuevoNodo;
}

int buscar(Nodo* cabeza, int valor){
    Nodo* actual = cabeza;

    while (actual != NULL)
    {
        if (actual->numero == valor)
        {
            return 1;
        }
        actual = actual->siguiente;
    }
}

int eliminar(Nodo** cabeza, int valor){
    //Si la lista esta vacia
    if (*cabeza == NULL)
    {
        return 0;
    }
    

    //Si el valor esta en la cabeza
    if ((*cabeza)->numero == valor)
    {
        Nodo* temp = *cabeza;
        *cabeza = (*cabeza)->siguiente;
        free(temp);
    }

    //Buscar el nodo a eliminar 
    Nodo* actual = *cabeza;
    //Siempre el actual va a ser una anterior al nodo a eliminar
    while (actual->siguiente != NULL && actual->siguiente->numero != valor)
    {
        actual = actual->siguiente;
    }
    
    //Si se encontro el valor
    if (actual->siguiente != NULL)
    {
        Nodo* temp = actual->siguiente;
        actual->siguiente = temp->siguiente;
        free(temp);
        return 1;
    }
    

    //Si llegamos aqui el valor no se encontro
    return 0;
}

void imprimirLista(Nodo** cabeza){
    Nodo* actual = cabeza;

    if (actual == NULL)
    {
        printf("La lista esta vacia\n");
        return;
    }


    printf("Lista: \n");
    //Recorrer la lista e imprimir cada valor
    while (actual != NULL)
    {
        printf("%d -> ", actual->numero);
        actual = actual->siguiente;
    }

    printf("NULL\n");
    
    
}

void liberarLista(Nodo** cabeza) {
    Nodo* actual = *cabeza;
    Nodo* siguiente;
    
    // Liberar cada nodo
    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    
    // Establecer la cabeza como NULL (lista vacía)
    *cabeza = NULL;
}

int main(){
    Nodo* lista = NULL;  // Inicializar una lista vacía
    
    // Insertar algunos valores
    insertarAlFinal(&lista, 10);
    insertarAlFinal(&lista, 20);
    insertarAlInicio(&lista, 5);
    insertarAlFinal(&lista, 30);
    
    // Imprimir la lista
    imprimirLista(lista);
    
    // Buscar valores
    printf("¿El valor 20 está en la lista? %s\n",buscar(lista, 20) ? "Sí" : "No");//Operador de IF acotado
    printf("¿El valor 25 está en la lista? %s\n",buscar(lista, 25) ? "Sí" : "No");
    
    // Eliminar un valor
    printf("Eliminando el valor 20...\n");
    eliminar(&lista, 20);
    imprimirLista(lista);
    
    // Liberar la memoria al final
    liberarLista(&lista);
    printf("Memoria liberada\n");
    
    return 0;
}

