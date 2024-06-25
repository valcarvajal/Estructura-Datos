/**
 * @file Mapa.h
 * @brief
 * @author Anthony Rojas y Valery Carvajal
 */
#include "Dijkstra.h" // se agrega el archivo de cabecera "Prim.c"
#ifndef INC_2022_IIS_DATOS_PROYECTO_3_UN_PROTO_CALABOZO_MAPA_H
#define INC_2022_IIS_DATOS_PROYECTO_3_UN_PROTO_CALABOZO_MAPA_H

/**
 * @brief Se define el struct mapa.
 * arbol_expansion_minima *Arbol - lo trae del archivo Prim.h.
 * int **matriz_direcciones - contiene la dirección de las conexiones entre cada sala.
 * int tamaño - tamaño del grafo.
 * @return Retorna el struct mapa.
 */
typedef struct mapa
{
    arbol_expansion_minima *Arbol;
    int **matriz_direcciones;
    int tamaño;
} mapa;

/**
 * @brief Un tipo mapa.
 * Inicializa un mapa con el tamaño deseado y su respectivo árbol y matriz de direcciones.
 * mapa *Mapa - Mapa con el que vamos a trabajar.
 * @param Tamaño - tamaño del grafo.
 * @return Retorna un struct mapa.
 */
mapa* inicializar_mapa(int Tamaño);

#endif //INC_2022_IIS_DATOS_PROYECTO_3_UN_PROTO_CALABOZO_MAPA_H
