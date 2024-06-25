/**
 * @file Prim.c
 * @brief
 * @author Anthony Rojas y Valery Carvajal
 */
#include <stdlib.h>
#include <stdio.h>
#include "Prim.h"

/**
 * @brief Un tipo arbol_expansion_minima.
 * Inicializa el árbol de expansión mínima con el tamaño deseado y su respectiva
 * matriz de adyacencia y lista de direcciones.
 * arbol_expansion_minima* Arbol - árbol con el que vamos a trabajar.
 * @param tamaño - tamaño del árbol.
 * @return Retorna el árbol generado.
 */
arbol_expansion_minima* inicializar_arbol_expansion_minima(int Tamaño)
{
    arbol_expansion_minima* Arbol = calloc(1, sizeof(arbol_expansion_minima));
    Arbol -> tamaño = Tamaño;
    Arbol -> matriz_adyacencia = inicializar_matriz(Tamaño);
    Arbol -> lista_nodos_visitados = calloc(Tamaño, sizeof(int));

    return Arbol;
}

/**
 * @brief Un tipo int.
 * Busca la sala con menos caminos.
 * @param Grafo - lo trae del archivo Grafo.h.
 * @return Retorna el nodo con menos aristas.
 */
int buscar_nodo_menos_aristas(grafo* Grafo)
{
    int nodo_menos_aristas = 0;
    int minimas_aristas = 999;

    for(int i = 0; i < Grafo-> tamaño; i++)
    {
        int aristas = contar_aristas_nodo(Grafo, i);

        if(aristas < minimas_aristas)
        {
            minimas_aristas = aristas;
            nodo_menos_aristas = i;
        }
    }

    return nodo_menos_aristas;
}

/**
 * @brief Un tipo int.
 * Cuenta la cantidad de caminos válidos.
 * @param nodo - sala del calabozo.
 * @param Arbol - árbol de expasión mínima.
 * @return Retorna la cantidad de aristas válidas (int contador).
 */
int contar_aristas_validas(int *nodo, arbol_expansion_minima* Arbol)
{
    int contador = 0;
    for(int i = 0; i < Arbol -> tamaño; i++)
    {
        if(Arbol -> lista_nodos_visitados[i] == 0)
        {
            contador += 1;
        }
    }
    return contador;
}

/**
 * @brief Un tipo int.
 * Busca el nodo más cercano.
 * @param nodo - sala del calabozo.
 * @param Arbol - árbol de expasión mínima.
 * @return Retorna el próximo nodo (el más cercano).
 */
int proximo_nodo(int *nodo, arbol_expansion_minima* Arbol)
{
    int arista_menor = 999;
    int nodo_mas_cercano = (Arbol -> tamaño) + 1;

    for(int i = 0; i < Arbol -> tamaño; i++)
    {
        if(nodo[i] && nodo[i] < arista_menor)
        {
            arista_menor = nodo[i];
            nodo_mas_cercano = i;
        }
    }

    return nodo_mas_cercano;
}

/**
 * @brief Un tipo int.
 * Verifica si el próximo nodo es válido.
 * @param nodo - sala del calabozo.
 * @param Arbol - árbol de expasión mínima
 * @return Retorna el nodo válido más cercano.
 */
int proximo_nodo_valido(int* nodo, arbol_expansion_minima* Arbol)
{
    int arista_menor = 999;
    int nodo_mas_cercano = (Arbol -> tamaño) + 1;

    for(int i = 0; i < Arbol -> tamaño; i++)
    {
        if(nodo[i] && nodo[i] < arista_menor && Arbol -> lista_nodos_visitados[i] == 0)
        {
            arista_menor = nodo[i];
            nodo_mas_cercano = i;
        }
    }

    return nodo_mas_cercano;
}

/**
 * @brief Un tipo int.
 * Verifica el final de la rama.
 * @param nodo - sala del calabozo.
 * @param Arbol - árbol de expasión mínima
 * @return Retorna un booleano (0 o 1).
 */
int verificar_fin_rama(int* nodo, arbol_expansion_minima* Arbol)
{
    int arista_menor = 999;
    int nodo_mas_cercano = 0;

    if(contar_aristas_validas(nodo, Arbol) == 0)
    {
        return 1;
    }

    if(Arbol -> lista_nodos_visitados[proximo_nodo(nodo, Arbol)] != 0)
    {
        return 1;
    }

    return 0;
}

/**
 * @brief Un tipo int.
 * Busca una nueva rama.
 * @param Arbol - árbol de expasión mínima
 * @param Grafo - lo trae del archivo Grafo.h.
 * @return Retorna el nodo de partida.
 */
int buscar_nueva_rama(arbol_expansion_minima* Arbol, grafo* Grafo)
{
    int nodo_partida = (Arbol -> tamaño) + 1;
    int minimo = 999;

    for(int i = 0; i < Arbol -> tamaño; i++)
    {
        if(contar_aristas_validas(Grafo -> matriz_adyacencia[i], Arbol) > 0 && Arbol -> lista_nodos_visitados[i] == 1)
        {
            if(Grafo -> matriz_adyacencia[i][proximo_nodo_valido(Grafo -> matriz_adyacencia[i], Arbol)])
            {
                if(Grafo -> matriz_adyacencia[i][proximo_nodo_valido(Grafo -> matriz_adyacencia[i], Arbol)] < minimo)
                {
                    minimo = Grafo -> matriz_adyacencia[i][proximo_nodo_valido(Grafo -> matriz_adyacencia[i], Arbol)];
                    printf(" -> nuevo minimo fijado a: %d \n", minimo);
                    nodo_partida = i;
                }
            }

        }
    }

    return nodo_partida;
}

arbol_expansion_minima* prim(grafo* Grafo)
{
    arbol_expansion_minima* Arbol = inicializar_arbol_expansion_minima(Grafo -> tamaño);
    int nodo_partida = buscar_nodo_menos_aristas(Grafo);
    int nodo_llegada = proximo_nodo_valido(Grafo -> matriz_adyacencia[nodo_partida], Arbol);
    int contador_nodos = 1;
    Arbol -> lista_nodos_visitados[nodo_partida] = 1;


    while(contador_nodos < Arbol -> tamaño)
    {

        if(verificar_fin_rama(Grafo -> matriz_adyacencia[nodo_partida], Arbol))
        {
            printf("Fin de rama. \n");
            nodo_partida = buscar_nueva_rama(Arbol,Grafo);
            nodo_llegada = proximo_nodo_valido(Grafo -> matriz_adyacencia[nodo_partida], Arbol);
        }

        Arbol -> matriz_adyacencia[nodo_partida][nodo_llegada] = Grafo -> matriz_adyacencia[nodo_partida][nodo_llegada];
        Arbol -> matriz_adyacencia[nodo_llegada][nodo_partida] = Grafo -> matriz_adyacencia[nodo_llegada][nodo_partida];
        Arbol -> lista_nodos_visitados[nodo_llegada] = 1;

        nodo_partida = nodo_llegada;
        nodo_llegada = proximo_nodo_valido(Grafo -> matriz_adyacencia[nodo_partida], Arbol);
        contador_nodos += 1;

        printf("Ciclo # %d \n", contador_nodos);
    }

    return Arbol;
}

/*void main(int argc, char *argv[])
{
    grafo* Grafo = generar_grafo(10,4,1);
    arbol_expansion_minima* Arbol_expansion_minima = prim(Grafo);

    imprimir_matriz(Grafo -> matriz_adyacencia, Grafo -> tamaño);
    printf(">>> Arbol de expansión mínima: \n");
    imprimir_matriz(Arbol_expansion_minima -> matriz_adyacencia, Arbol_expansion_minima -> tamaño);
}*/