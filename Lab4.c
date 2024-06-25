#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura del nodo
typedef struct Nodo {
    char nombre[100];
    int edad;
    struct Nodo* siguiente;
} Nodo;

// Función para insertar un nodo al final de la lista
void insertarAlFinal(Nodo** cabeza, char nombre[], int edad) {
    // Crear el nuevo nodo
    Nodo* nuevoNodo = (Nodo*)calloc(1, sizeof(Nodo));
    strcpy(nuevoNodo->nombre, nombre);
    nuevoNodo->edad = edad;
    nuevoNodo->siguiente = NULL;

    if (*cabeza == NULL) {
        // Si la lista está vacía, el nuevo nodo será la cabeza
        *cabeza = nuevoNodo;
    } else {
        // Recorrer hasta el último nodo
        Nodo* actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }

        // Enlazar el nuevo nodo al final
        actual->siguiente = nuevoNodo;
    }
}

// Función para imprimir la lista
void imprimirLista(Nodo* cabeza) {
    printf("Lista de personas:\n");

    if (cabeza == NULL) {
        printf("La lista está vacía.\n");
    } else {
        Nodo* actual = cabeza;
        while (actual != NULL) {
            printf("Nombre: %s, Edad: %d\n", actual->nombre, actual->edad);
            actual = actual->siguiente;
        }
    }
}

// Función para borrar toda la lista
void borrarLista(Nodo** cabeza) {
    Nodo* actual = *cabeza;
    while (actual != NULL) {
        Nodo* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }

    *cabeza = NULL;
}

int main() {
    Nodo* cabeza = NULL;
    int opcion;
    char nombre[100];
    int edad;

    do {
        printf("\nMenú:\n");
        printf("1. Insertar persona\n");
        printf("2. Imprimir lista\n");
        printf("3. Borrar lista\n");
        printf("4. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el nombre: ");
                scanf("%s", nombre);
                printf("Ingrese la edad: ");
                scanf("%d", &edad);
                insertarAlFinal(&cabeza, nombre, edad);
                printf("Persona insertada correctamente.\n");
                break;
            case 2:
                imprimirLista(cabeza);
                break;
            case 3:
                borrarLista(&cabeza);
                printf("Lista borrada correctamente.\n");
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}


