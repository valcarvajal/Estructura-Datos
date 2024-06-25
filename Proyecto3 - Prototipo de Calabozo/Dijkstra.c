/**
 * @file Dijkstra.c
 * @brief
 * @author Anthony Rojas y Valery Carvajal
 */
#include <stdlib.h>
#include <stdio.h>
#include "Dijkstra.h"

/**
 * @brief Un tipo int.
 * Busca la posición con menor valor.
 * @param lista - lista de valores temporales que se utilizan en el algoritmo.
 * @param tamaño - tamaño de la matriz.
 * @param visitados - nodos visitados
 * @return Retorna la posición con menor valor.
 */
int posicion_menor_valor(int* lista, int tamaño, int* visitados)
{
    int i = 0; while(lista[i] == 0 || visitados[i]){ i++; }

    int menor = lista[i];
    int posicion = i;

    for(int j = 0; j < tamaño; j++)
    {
        if(lista[j] != 0 && lista[j] < menor && visitados[j] == 0)
        {
            menor = lista[j];
            posicion = j;
        }
    }

    return posicion;
}

/**
 * @brief Un tipo int*.
 * Extrae una ruta.
 * @param lista - lista de valores temporales que se utilizan en el algoritmo.
 * @param nodo_inicial - nodo inicial.
 * @param nodo_final - nodo final.
 * @return Retorna la ruta.
 */
int* extraer_ruta(int* lista, int nodo_inicial, int nodo_final)
{
    int nodo_anterior = nodo_final;
    int i = 0;
    while(nodo_anterior != nodo_inicial)
    {
        nodo_anterior = lista[nodo_anterior];
        i++;
    }

    int* ruta = calloc(i, sizeof(int));
    nodo_anterior = nodo_final;
    i = 0;
    while(nodo_anterior != nodo_inicial)
    {
        ruta[i] = nodo_anterior;
        nodo_anterior = lista[nodo_anterior];
        i++;
    }
    ruta[i] = nodo_anterior;

    return ruta;
}

/**
 * @brief Un tipo void.
 * Imprime la ruta.
 * @param ruta - ruta con la que vamos a trabajar.
 * @param nodo_final - nodo final.
 */
void imprimir_ruta(int* ruta, int nodo_final)
{
    int i = 0;

    printf("\n");
    printf("Ruta desde %d hasta %d : \n", nodo_final, ruta[0]);
    printf(" | ");
    while(ruta[i] != nodo_final)
    {
        printf("%d <- ", ruta[i]);
        i++;
    }
    printf("%d |", ruta[i]);
    printf("\n\n");
}

int* Dijkstra(int** matriz, int tamaño, int nodo_partida, int nodo_llegada)
{
    int* temporal = calloc(tamaño, sizeof(int));
    int* final = calloc(tamaño, sizeof(int));
    int* predecesor = calloc(tamaño, sizeof(int));
    int sumador = 0;
    int nodo_inicial = nodo_partida;

    while(nodo_partida != nodo_llegada)
    {
        for(int i = 0; i < tamaño; i++)
        {
            int valor = matriz[nodo_partida][i];
            sumador = final[nodo_partida] + valor;
            //printf("sumador = %d \n", sumador);
            if(valor && final[i] == 0)
            {
                if(temporal[i] > 0)
                {
                    if(sumador < temporal[i])
                    {
                        temporal[i] = sumador;
                        predecesor[i] = nodo_partida;
                    }
                }
                else
                {
                    temporal[i] = sumador;
                    predecesor[i] = nodo_partida;
                }
            }
        }

        if(final[nodo_partida] == 0){final[nodo_partida] = 1;}

        nodo_partida = posicion_menor_valor(temporal, tamaño, final);
        final[nodo_partida] = temporal[nodo_partida];
    }

    int* ruta = extraer_ruta(predecesor, nodo_inicial, nodo_llegada);

    imprimir_ruta(ruta, nodo_inicial);

    for(int g = tamaño; g > 0; g--)
    {
        temporal[g] = 0;
        final[g] = 0;
        predecesor[g] = 0;
    }

    temporal = NULL;
    final = NULL;
    predecesor = NULL;

    free(temporal);
    free(final);
    free(predecesor);

    return ruta;
}

/*void main(int argc, char *argv[])
{
    grafo *Grafo = generar_grafo(10, 10, 1);
    arbol_expansion_minima *Arbol = prim(Grafo);
    int Tamaño = Grafo-> tamaño;
    //printf("Tamaño del grafo = %d \n", Tamaño);
    imprimir_matriz(Arbol -> matriz_adyacencia, Tamaño);
    int* ruta = Dijkstra(Arbol-> matriz_adyacencia, Tamaño, 5, 8);

}*/

