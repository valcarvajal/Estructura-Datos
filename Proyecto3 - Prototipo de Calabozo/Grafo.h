/**
 * @file Grafo.h
 * @brief
 * @author Anthony Rojas y Valery Carvajal
 */
#include "Matriz.h" // se agrega el archivo de cabecera "Matriz.c"

#ifndef INC_2022_IIS_DATOS_PROYECTO_3_UN_PROTO_CALABOZO_GRAFO_H
#define INC_2022_IIS_DATOS_PROYECTO_3_UN_PROTO_CALABOZO_GRAFO_H

/**
 * @brief Se define el struct grafo.
 * int **matriz_adyacencia - contiene las salas con las que conecta cada sala del calabozo.
 * int tamaño - tamaño del grafo.
 * @return Retorna el struct grafo.
 */
typedef struct grafo
{
    int **matriz_adyacencia;
    int tamaño;
} grafo;

/**
 * @brief Un tipo int.
 * Cuenta la cantidad de caminos que tiene la sala, deben ser entre 1 y 4.
 * @param Grafo - grafo con el que vamos a trabajar.
 * @param fila - cada fila es una sola distinta.
 * @return Retorna la cantidad de caminos (int contador).
 */
int contar_aristas_nodo(grafo *Grafo, int fila);

/**
 * @brief Un tipo grafo.
 * Genera el grafo completo.
 * grafo* Grafo - Inicializa el grafo con el tamaño recibido.
 * @param Tamaño - tamaño del grafo.
 * @param maximo_aristas_nodo - cantidad máxima de caminos que puede tener una sala.
 * @param minimo_aristas_nodo - cantidad mínima de caminos que puede tener una sala.
 * @return Retorna el grafo.
 */
grafo *generar_grafo(int Tamaño, int maximo_aristas_nodo, int minimo_aristas_nodo);

#endif //INC_2022_IIS_DATOS_PROYECTO_3_UN_PROTO_CALABOZO_GRAFO_H
