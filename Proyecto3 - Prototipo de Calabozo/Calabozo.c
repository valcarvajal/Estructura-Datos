#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Calabozo.h"

/**
 * @brief Un tipo void.
 * Imprime opciones a elegir del usuario.
 */
void Imprimir_opciones_principales()
{
    printf("Opciones a ejecutar:\n");
    printf("\t 1 - Generar un grafo de tamaño n.\n");
    printf("\t 2 - Generar el árbol de expansión minima de un grafo de tamaño n.\n");
    printf("\t 3 - Generar un Mapa de calabozo.\n");
    printf("\t 4 - Buscar la ruta más corta con Dijkstra.\n");
    printf("\t 5 - Salir del programa.\n");
}

void interfaz()
{
    Imprimir_opciones_principales();

    char* entrada = calloc(100, sizeof(char));

    while(strcmp(entrada, "5"))
    {
        printf("\n");
        printf("Seleccione una opción: ");
        scanf("%s", entrada);

        if(!strcmp(entrada, "1"))
        {
            printf("Ingrese un tamaño para el grafo: ");
            int valor;
            scanf("%d", &valor);
            grafo* Grafo = generar_grafo(valor, valor, 1);
            imprimir_matriz(Grafo->matriz_adyacencia, valor);
        }
        if(!strcmp(entrada, "2"))
        {
            printf("Ingrese un tamaño para el grafo al que se aplicará prim: ");
            int valor;
            scanf("%d", &valor);
            grafo* Grafo = generar_grafo(valor, valor, 1);
            arbol_expansion_minima* Arbol = prim(Grafo);
            printf("Grafo: \n");
            imprimir_matriz(Grafo->matriz_adyacencia, valor);
            printf("Árbol de expansión minima: \n");
            imprimir_matriz(Arbol->matriz_adyacencia, valor);
        }
        if(!strcmp(entrada, "3"))
        {
            printf("Ingrese un tamaño para el Mapa que desea generar: ");
            int valor;
            scanf("%d", &valor);
            mapa* Mapa = inicializar_mapa(valor);
            printf("Árbol de expansión minima: \n");
            imprimir_matriz(Mapa->Arbol->matriz_adyacencia, valor);
            printf("Matriz direcciones: \n");
            imprimir_matriz(Mapa->matriz_direcciones, valor);
        }
        if(!strcmp(entrada, "4"))
        {
            int valor;
            int nodo_inicial;
            int nodo_final;

            printf("Ingrese un tamaño para el Grafo al que aplicara Dijkstra: ");
            scanf("%d", &valor);

            printf("Ingrese un nodo para iniciar la busqueda: ");
            scanf("%d", &nodo_inicial);

            printf("Ingrese un nodo para terminar la busqueda: ");
            scanf("%d", &nodo_final);

            grafo* Grafo = generar_grafo(valor, valor, 1);
            printf("Grafo: \n");
            imprimir_matriz(Grafo->matriz_adyacencia, valor);
            Dijkstra(Grafo->matriz_adyacencia, valor, nodo_inicial, nodo_final);
        }
    }
}

int main(int argc, char* argv[])
{
    interfaz();
}