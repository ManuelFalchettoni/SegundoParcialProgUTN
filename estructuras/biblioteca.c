#include <stdio.h>
#include <string.h>

// Estructura Libro
typedef struct {
    char titulo[100];
    char isbn[20];
    char autor[50];
    char editorial[50];
    int prestado; // 0: disponible, 1: prestado
} Libro;

// Prototipos de funciones
void inicializarBiblioteca(Libro biblioteca[], int *cantidadLibros);//Por referencia ya que necesitamos modificar el valor de cantidadLibros para futuras funciones
void mostrarMenu(int *opcionMenu); //Paso por referencia
void crearLibro(Libro biblioteca[], int *cantidadLibros); //Paso por referencia
void listarLibros(Libro biblioteca[], int cantidadLibros);
void prestarLibro(Libro biblioteca[], int cantidadLibros);
void modificarLibro(Libro biblioteca[], int cantidadLibros);
void ordenarBibliotecaPorISBN(Libro biblioteca[], int cantidadLibros);
int buscarLibroBinario(Libro biblioteca[], int cantidadLibros, char isbn[]);//Tambien pedimos como paramtro el isbn correspondiente para buscarlo

int main() {
    Libro biblioteca[100];
    int cantidadLibros = 0;
    int opcionMenu = 0;
    char elemento[20];
    //Inicializo la biblioteca con 3 libros 
    inicializarBiblioteca(biblioteca, &cantidadLibros);
    //Ordeno esos 3 libros
    ordenarBibliotecaPorISBN(biblioteca, cantidadLibros);
    //Empieza el menu
    do {    
        mostrarMenu(&opcionMenu);//Muestro todas las opciones
        switch (opcionMenu) { //La variable a compararse con los cases es opcionMenu
            case 1:
                crearLibro(biblioteca, &cantidadLibros);
                break;
            case 2:
                listarLibros(biblioteca, cantidadLibros);
                break;
            case 3:
                prestarLibro(biblioteca, cantidadLibros);
                break;
            case 4:
                modificarLibro(biblioteca, cantidadLibros);
                break;
            case 5:{ //Uso llaves para poder utilizar variables dentro de un case {}
                printf("Ingrese el ISBN del libro a buscar: \n");
                scanf(" %19[^\n]", elemento); // Lee hasta 19 caracteres + '\0', y sus respectivos espacios, evito sobrepasarse de caracteres
                //Busco el indice del libro
                int indice = buscarLibroBinario(biblioteca, cantidadLibros, elemento);
                if (indice == -1) { //Si no se encuentra el libro
                printf("Libro no encontrado.\n");
                break;
                }
                //Muestro la informacion del libro
                printf("Titulo: \n", biblioteca[indice].titulo);
                printf("ISBN:  \n", biblioteca[indice].isbn);
                printf("Autor: \n", biblioteca[indice].autor);
                printf("Editorial: \n", biblioteca[indice].editorial);
                //Pregunto si el libro esta prestado o disponible
                if (biblioteca[indice].prestado)
                {
                    printf("Estado actual: Prestado!\n");
                }else{
                    printf("Estado actual: Disponible!\n");
                }
                break;
            }
            default:
                break;
        }
    } while (opcionMenu != 6); //Mientras el usuario no seleccione salir

    return 0;
}
//Listo inicializar con 3 libros
void inicializarBiblioteca(Libro biblioteca[], int *cantidadLibros) {
    strcpy(biblioteca[0].titulo, "Don Quijote de la Mancha");
    strcpy(biblioteca[0].isbn, "1234");
    strcpy(biblioteca[0].autor, "Miguel de Cervantes");
    strcpy(biblioteca[0].editorial, "Planeta");
    biblioteca[0].prestado = 0;

    strcpy(biblioteca[1].titulo, "Cien años de soledad");
    strcpy(biblioteca[1].isbn, "0045");
    strcpy(biblioteca[1].autor, "Gabriel García Márquez");
    strcpy(biblioteca[1].editorial, "Planeta");
    biblioteca[1].prestado = 0;

    strcpy(biblioteca[2].titulo, "El principito");
    strcpy(biblioteca[2].isbn, "3456");
    strcpy(biblioteca[2].autor, "Antoine de Saint-Exupéry");
    strcpy(biblioteca[2].editorial, "Salamandra");
    biblioteca[2].prestado = 0;

    *cantidadLibros = 3; // Importante tener un contador de libros para futuros bucles
}
//Listo mostrar menu
void mostrarMenu(int *opcionMenu) {
    printf("===== SISTEMA DE BIBLIOTECA =====\n");
    printf("1. Crear un libro\n2. Listar todos los libros\n3. Prestar un libro\n4. Modificar un libro\n5. Buscar un libro por ISBN\n6. Salir\n");
    printf("Seleccione una opcion:\n");
    scanf("%d", opcionMenu);
    getchar(); // Limpiar el \n que queda en el buffer
}
//Listo crear libro
void crearLibro(Libro biblioteca[], int *cantidadLibros) {
    //Titulo
    printf("Ingrese el titulo del libro: \n");
    scanf(" %99[^\n]", biblioteca[*cantidadLibros].titulo);//" %99[^\n]" esto se utiliza para poder guardar cadenas con espacios y poner un limite de caracteres
    //ISBN
    printf("Ingrese el ISBN: \n");
    scanf(" %19[^\n]", biblioteca[*cantidadLibros].isbn);
    //Autor
    printf("Ingrese el autor: \n");
    scanf(" %49[^\n]", biblioteca[*cantidadLibros].autor);
    //Editorial
    printf("Ingrese el editorial: \n");
    scanf(" %49[^\n]", biblioteca[*cantidadLibros].editorial);
    //Estado actual
    printf("Ingrese si esta prestado: (1 si esta prestado, 0 si no)\n");
    scanf("%d", &biblioteca[*cantidadLibros].prestado);//Se utiliza el '&' para poder guardar un entero en esa direccion de memoria, no se utiliza en las anteriores, ya que al ser cadenas ya viene por defecto con su direccion de memoria.
    getchar(); // Limpiar buffer (No se que es esto pero se necesita, creo que para que no queden restos de los scanf)
    (*cantidadLibros)++; //Aumento la cantidad de libros antes de ordenarlos, ya que al ordenar necesito saber la cantidad exacta de libros

    //Ordeno los libros de vuelta al agregar un nuevo libro
    //Esto es altamente ineficiente, lo ideal seria agregarlo a su posicion correctamente mediante (Insertion Sort)
    ordenarBibliotecaPorISBN(biblioteca, *cantidadLibros);
}
//Listado
void listarLibros(Libro biblioteca[], int cantidadLibros) {
    //FOR simple para recorrer un array 
    for (int i = 0; i < cantidadLibros; i++) {
        printf("Titulo: %s\n", biblioteca[i].titulo);
        printf("ISBN: %s\n", biblioteca[i].isbn);
        printf("Autor: %s\n", biblioteca[i].autor);
        printf("Editorial: %s\n", biblioteca[i].editorial);
        //Pregunto el estado actual del libro
        if (biblioteca[i].prestado) {
            printf("El libro esta prestado.\n");
        } else {
            printf("El libro esta disponible.\n");
        }
        printf("------------------------\n");
    }
}
//Prestar
void prestarLibro(Libro biblioteca[], int cantidadLibros) {
    //Pregunto por el ISBN a buscar
    char elemento[20];
    printf("Ingrese el ISBN del libro a prestar: \n");
    scanf(" %19[^\n]", elemento); 
    //Busco el indice del libro 
    int indice = buscarLibroBinario(biblioteca, cantidadLibros, elemento);
    //Si no se encuentra el libro
    if (indice == -1) {
    printf("Libro no encontrado.\n");
    return; // Salir de la función
    }

    biblioteca[indice].prestado = 1; //Cambiamos a prestado
    printf("Libro prestado con exito.\n");
}
//Modificar valores del libro
void modificarLibro(Libro biblioteca[], int cantidadLibros) {
    char elemento[20];
    printf("Ingrese el ISBN del libro a modificar: \n");
    scanf(" %19[^\n]", elemento); 

    //Busco el indice del libro por ISBN

    int indice = buscarLibroBinario(biblioteca, cantidadLibros, elemento);
    if (indice == -1) {
    printf("Libro no encontrado.\n");//Si no encuentro el libro
    return; //Salgo de la funcion, evito ejecutar el codigo siguiente
    }
    //Titulo
    printf("Titulo actual: %s\n", biblioteca[indice].titulo);
    printf("Ingrese nuevo titulo: \n");
    scanf(" %99[^\n]", biblioteca[indice].titulo);
    //ISBN
    printf("ISBN actual: %s\n", biblioteca[indice].isbn);
    printf("Ingrese nuevo ISBN: \n");
    scanf(" %19[^\n]", biblioteca[indice].isbn);
    //Autor
    printf("Autor actual: %s\n", biblioteca[indice].autor);
    printf("Ingrese nuevo autor: \n");
    scanf(" %49[^\n]", biblioteca[indice].autor);
    //Editorial
    printf("Editorial actual: %s\n", biblioteca[indice].editorial);
    printf("Ingrese nuevo editorial: \n");
    scanf(" %49[^\n]", biblioteca[indice].editorial);
    //Estado actual
    if (biblioteca[indice].prestado)
    {
        printf("Estado actual: Prestado!\n");
    }else{
        
        printf("Estado actual: Disponible!\n");
    }
    printf("Ingrese el nuevo estado actual: \n");
    scanf("%d", &biblioteca[indice].prestado);//Uso amperson ya que es un entero
    
    //Vuelvo a ordenar por si se cambio el ISBN
    ordenarBibliotecaPorISBN(biblioteca, cantidadLibros);
}
//Ordenamiento por Bubble sort segun ISBN
void ordenarBibliotecaPorISBN(Libro biblioteca[], int cantidadLibros){
    //Ordenamiento Bubble Sort
    Libro temp; //Variable temporal tipo STRUCT LIBRO

    for (int i = 0; i < cantidadLibros; i++)
    {
        for (int j = 0; j < cantidadLibros - 1; j++)
        {
            if (strcmp(biblioteca[j].isbn, biblioteca[j + 1].isbn) > 0) //strcmp devuelve 0 sin son iguales, positivo si el primero es mayor que el segundo y negativo viceversa
            {
                temp = biblioteca[j];
                biblioteca[j] = biblioteca[j + 1];
                biblioteca[j + 1] = temp;
            }
        }
    }
    

}
//Busqueda binaria
// Función para buscar un libro por ISBN usando el algoritmo de búsqueda binaria
int buscarLibroBinario(Libro biblioteca[], int cantidadLibros, char elemento[]) {
    int izquierda = 0;         // Límite izquierdo inicial (primer elemento del arreglo)
    int derecha = cantidadLibros - 1;  // Límite derecho inicial (último elemento del arreglo)

    // Mientras haya elementos por buscar en el rango actual
    while (izquierda <= derecha) {
        // Calcula el punto medio del rango actual (evita desbordamiento de enteros)
        int medio = izquierda + (derecha - izquierda) / 2;  // Equivalente a (izquierda + derecha)/2 pero más seguro

        // Compara el ISBN del libro del medio con el ISBN buscado
        int cmp = strcmp(biblioteca[medio].isbn, elemento);// 0 si son iguales , positivo si es mayor el primero y negativo si es mayor el segundo

        if (cmp == 0) {
            // ¡Encontrado! Retorna la posición del libro
            return medio;
        }
        else if (cmp < 0) {
            // El ISBN del medio es MENOR que el buscado -> buscar en la mitad derecha
            izquierda = medio + 1;  // Movemos el límite izquierdo
        }
        else {
            // El ISBN del medio es MAYOR que el buscado -> buscar en la mitad izquierda
            derecha = medio - 1;   // Movemos el límite derecho
        }
    }

    // Si salimos del while significa que el ISBN no existe en el arreglo
    return -1;  // Valor convencional para indicar "no encontrado"
}



