/**
 * @file Prim.h
 * @brief
 * @author Anthony Rojas y Valery Carvajal
 */
#include "Grafo.h"

#ifndef INC_2022_IIS_DATOS_PROYECTO_3_UN_PROTO_CALABOZO_PRIM_H
#define INC_2022_IIS_DATOS_PROYECTO_3_UN_PROTO_CALABOZO_PRIM_H

/**
 * @brief Se define el struct arbol_expansion_minima.
 * int **matriz_adyacencia - contiene las salas con las que conecta cada sala del calabozo.
 * int *lista_nodos_visitados - lista de punteros a int que contiene los nodos visitados.
 * int tamaño - tamaño del árbol.
 * @return Retorna el struct arbol_expansion_minima.
 */
typedef struct arbol_expansion_minima
{
    int **matriz_adyacencia;
    int* lista_nodos_visitados;
    int tamaño;
} arbol_expansion_minima;

/**
 * @brief Un tipo arbol_expansion_minima.
 * Función prim.
 * @param Grafo - lo trae del archivo Grafo.h.
 * @return Retorna el árbol de expansión mínima.
 */
arbol_expansion_minima* prim(grafo* Grafo);

#endif //INC_2022_IIS_DATOS_PROYECTO_3_UN_PROTO_CALABOZO_PRIM_H
