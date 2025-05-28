#include <stdio.h>
#include <string.h>


typedef struct {
char nombre[50];
char telefono[15];
char email[50];
int categoria; // 1=Familia, 2=Trabajo, 3=Amigos
} Contacto;

void cargarContacto(Contacto *c){
    printf("Ingrese el nombre: \n");
    scanf("%s", c->nombre);
    printf("Ingrese el telefono: \n");
    scanf("%s", c->telefono);
    printf("Ingrese el email: \n");
    scanf("%s", c->email);
    do
    {
        printf("Ingrese la categoria: (1 Familia / 2 Trabajo / 3 Amigos) \n");
        scanf("%d", c->categoria);
    } while (c->categoria != 1 || c->categoria != 2 || c->categoria != 3);
}

void mostrarContacto(Contacto c){
    printf("------------------\n");
    printf("Nombre: %s\n", c.nombre);
    printf("Telefono: %s\n", c.telefono);
    printf("Email: %s\n", c.email);
    switch (c.categoria)
    {
    case 1:
        printf("Familia\n");
        break;
    case 2:
        printf("Trabajo\n");
        break;
    case 3:
        printf("Amigos\n");
        break;
    }
}


void buscarPorCategoria(Contacto agenda[], int largo, int cat){

    for (int i = 0; i < largo; i++)
    {
        if (agenda[i].categoria == cat)
        {
            mostrarContacto(agenda[i]);
        }
        
    }
    
}

void ordenarPorNombre(Contacto agenda[], int largo){
    
    for (int i = 0; i < largo; i++)
    {
        for (int j = 0; j < largo - 1; j++)
        {
            if (strcmp(agenda[j].nombre, agenda[j + 1].nombre) > 0)
            {
                Contacto temp = agenda[j + 1];
                agenda[j + 1] = agenda[j];
                agenda[j] = temp;
            }
            
        }
        
    }
    



}

int contarPorCategoria(Contacto agenda[], int largo, int cat){
    int contador = 0;
    for (int i = 0; i < largo; i++)
    {
        if (agenda[i].categoria == cat)
        {
            contador++;
        }
    }
    return contador;
}


int main(){
    int largo = 5;
    Contacto agenda[10];
    strcpy(agenda[0].nombre, "Juan");
    strcpy(agenda[0].telefono, "123456789");
    strcpy(agenda[0].email, "juan@mail.com");
    agenda[0].categoria = 1;

    strcpy(agenda[1].nombre, "Maria");
    strcpy(agenda[1].telefono, "987654321");
    strcpy(agenda[1].email, "maria@mail.com");
    agenda[1].categoria = 2;

    strcpy(agenda[2].nombre, "Pedro");
    strcpy(agenda[2].telefono, "555123456");
    strcpy(agenda[2].email, "pedro@mail.com");
    agenda[2].categoria = 3;

    strcpy(agenda[3].nombre, "Ana");
    strcpy(agenda[3].telefono, "444555666");
    strcpy(agenda[3].email, "ana@mail.com");
    agenda[3].categoria = 1;

    strcpy(agenda[4].nombre, "Luis");
    strcpy(agenda[4].telefono, "222333444");
    strcpy(agenda[4].email, "luis@mail.com");
    agenda[4].categoria = 2;
    int opcion;
    do
    {
        printf("--------------------------\nIngrese la opcion \n");
        printf("1. Mostrar todos los contactos \n");
        printf("2. Buscar por categoría \n");
        printf("3. Ordenar y mostrar por nombre \n");
        printf("4. Contar contactos por categoría \n");
        printf("5. Salir \n");
        scanf("%d", &opcion);

        int categoria;
        switch (opcion)
        {
        case 1:
            for (int i = 0; i < largo; i++)
            {
                mostrarContacto(agenda[i]);
            }
            break;
        case 2:
            printf("Ingrese la categoria a buscar: \n");
            scanf("%d", &categoria);
            buscarPorCategoria(agenda, largo, categoria);
            break;
        case 3:
            ordenarPorNombre(agenda, largo);
            for (int i = 0; i < largo; i++)
            {
                printf("Nombre: %s\n", agenda[i].nombre);
            }
            break;
        case 4:
            printf("Ingrese la categoria a buscar: \n");
            scanf("%d", &categoria);
            printf("Cantidad de contactos de esa categoria: %d\n",contarPorCategoria(agenda, largo, categoria));
            break;
        default:
            printf("Ingrese un numero de las opciones \n");
            break;
        }
    } while (opcion != 5);
    return 0;
}