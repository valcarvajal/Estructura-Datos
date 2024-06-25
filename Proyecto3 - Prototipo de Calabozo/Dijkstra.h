//
// Created by valery on 28/11/22.
//

#ifndef INC_2022_IIS_DATOS_PROYECTO_3_UN_PROTO_CALABOZO_DIJKSTRA_H
#define INC_2022_IIS_DATOS_PROYECTO_3_UN_PROTO_CALABOZO_DIJKSTRA_H
#include "Prim.h"


/**
 * @brief Un tipo int**.
 * Función del algoritmo de Dijkstra.
 * @param matriz - matriz con la que se va a trabajar.
 * @param tamaño - tamaño del matriz.
 * @param nodo_partida - nodo del cual se inicia.
 * @param nodo_llegada - nodo al cual se llega.
 * @return Retorna una matriz nueva.
 */
int* Dijkstra(int** matriz, int tamaño, int nodo_partida, int nodo_llegada);

#endif //INC_2022_IIS_DATOS_PROYECTO_3_UN_PROTO_CALABOZO_DIJKSTRA_H
