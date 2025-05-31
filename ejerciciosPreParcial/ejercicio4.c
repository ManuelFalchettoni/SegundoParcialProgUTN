/* Desarrollar un programa en lenguaje C que simule el sistema de compras de una
verdulería. El usuario podrá consultar productos, comprar hasta 4 artículos distintos y
obtener un ticket final detallado.*/
/*Producto Letra Precio por kilo ($)
Banana b 120.50
Manzana m 98.30
Pera p 75.00
Naranja n 85.00
Tomate t 110.00
Lechuga l 45.50
Papa a 60.00
Zanahoria z 50.00*/
/*Al seleccionar “1. Agregar producto”:
 Se deben mostrar los 8 productos con sus letras y precios.
 El usuario debe ingresar:
 La letra del producto que desea comprar.
 La cantidad de kilos que desea comprar.
 Esta operación se puede repetir (volver a elegir la opción 1) hasta que se hayan comprado
4 productos diferentes como máximo.
 Si se intenta agregar un quinto producto, se debe mostrar un mensaje indicando que se
alcanzó el límite, y continuar con la opción 2 automáticamente.
 No se debe permitir comprar dos veces el mismo producto.

Al seleccionar “2. Terminar compra / Salir”:
 El programa debe imprimir un ticket de compra usando una matriz de 4 filas x 3
columnas (float ticket[4][3]), donde cada fila representa un producto comprado y las
columnas representan:
1. Cantidad de kilos
2. Precio por kilo
3. Subtotal (kilos × precio)
 Además, se debe usar un arreglo adicional para almacenar las letras de los productos
comprados (char productos_ticket[4]).
 El ticket debe mostrarse así (ejemplo):
Producto | Kilos | Subtotal
---------------------------
b | 2.00 | $241.00
t | 1.50 | $165.00
---------------------------
TOTAL A PAGAR: $406.00
Si el usuario no compró nada, debe mostrarse un mensaje:
&quot;No se realizaron compras.&quot;
Validaciones obligatorias
 Si el usuario ingresa una letra de producto inválida, debe mostrarse un mensaje de error y
volver a pedir un producto válido.
 Si el usuario intenta comprar el mismo producto más de una vez, también debe notificarse.
 El programa debe permitir volver a la opción 1 cuantas veces quiera el usuario (hasta el
límite de 4 productos).*/
/*
void mostrarMenu(); // Muestra el menú principal

void mostrarProductos(char[], float[], int); // Muestra productos y precios

int buscarIndiceProducto(char[], int, char); // Busca índice del producto ingresado

int productoYaAgregado(char[], int, char); // Verifica si ya se compró el producto

void mostrarTicket(char[], float[][3], int); // Imprime el ticket de compra*/

#include <stdio.h>

#define MAX_PRODUCTOS 8
#define MAX_COMPRA 4

typedef struct { //Productos
    char letra;
    char nombre[20];
    float precio;
} Producto;

typedef struct 
{
    char letra; //Letra del producto
    float kilos;    //Cantidad de kilos comprados
    float precio; //Precio por kilo
    float subtotal; //Kilos * precio
}TicketItem;


void mostrarMenu(){
    printf("=== Verdulería UTN ===\n");
    printf("1. Agregar producto\n");
    printf("2. Terminar compra / Salir\n");
}

void mostrarProductos(Producto productos[]) {
        printf("Productos disponibles:\n");
        for (int i = 0; i < MAX_PRODUCTOS; i++) {
            printf("%c - %s: $%.2f por kilo\n", productos[i].letra, productos[i].nombre, productos[i].precio);
        }
    }

int buscarIndiceProducto(Producto productos[], char letra){

    for (int i = 0; i < MAX_PRODUCTOS; i++)
    {
        if (productos[i].letra == letra)
        {
            return i;
        }
        
    }
    return -1;
}

int productoYaAgregado(TicketItem ticket[], char letra, int cantidadCompras){
    for (int i = 0; i < cantidadCompras; i++)
    {
        if (ticket[i].letra == letra)
        {
            return 1; //Ya fue agregado
        }
    }
    return 0;// No fue agregado anteriormente
}

void mostrarTicket(TicketItem ticket[],int cantidadCompras){
    if (cantidadCompras == 0)
    {
        printf("No se realizaron compras. \n");
        return;
    }
    
    float total = 0;
    printf("Producto | Kilos | Subtotal\n");
    printf("----------------------------\n");

    for (int i = 0; i < cantidadCompras; i++) {
        printf("   %c     | %.2f | $%.2f\n",
        ticket[i].letra,
        ticket[i].kilos,
        ticket[i].subtotal);
        total += ticket[i].subtotal;
    }

    printf("----------------------------\n");
    printf("TOTAL A PAGAR: $%.2f\n", total);

}



int main(){
    int opcion, cantidadComprados = 0;
    Producto productos[MAX_PRODUCTOS] = {
        {'b', "Banana", 120.50},
        {'m', "Manzana", 98.30},
        {'p', "Pera", 75.00},
        {'n', "Naranja", 85.00},
        {'t', "Tomate", 110.00},
        {'l', "Lechuga", 45.50},
        {'a', "Papa", 60.00},
        {'z', "Zanahoria", 50.00}
    };
    //Defino el array de struct Ticket, con maximo 4 productos
    TicketItem ticket[MAX_COMPRA];
    //Primero muestro todos los productos
    mostrarProductos(productos);
    do
    {
        mostrarMenu();
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        if (opcion == 1) {// Agregar producto
            if (cantidadComprados >= MAX_COMPRA) //Primero pregunto si esta lleno las compras
            {
                printf("No puede agregar mas productos. Limite alcanzado. \n");
                continue;
            }else{
            int indice;
            char letraElegida;
            float kilosElegidos;
            
            //Pide la letra del producto
            printf("Ingrese la letra del producto que desea agregar: \n");
            scanf(" %c", &letraElegida);
            //Guardo el indice de esa letra
            indice = buscarIndiceProducto(productos, letraElegida);
            //Verifico si existe ese producto o si ya fue agregado
            if (indice != -1 && productoYaAgregado(ticket, letraElegida, cantidadComprados) != 1)
            {
                printf("Ingrese los kilos que desea: \n");
                scanf("%f", &kilosElegidos);
                ticket[cantidadComprados].letra = productos[indice].letra;
                ticket[cantidadComprados].kilos = kilosElegidos;
                ticket[cantidadComprados].precio = productos[indice].precio;
                ticket[cantidadComprados].subtotal = kilosElegidos * productos[indice].precio;
                cantidadComprados++;
                mostrarTicket(ticket, cantidadComprados);
            }else{
                printf("No se encontro ese producto o ya fue agregado \n");
                continue;
            }
            }
            
            
        } else if (opcion == 2) {// Terminar compra
            mostrarTicket(ticket, cantidadComprados);
        } else {
        printf("Opción inválida\n");
        }
    } while (opcion != 2);
    

    return 0;
}



