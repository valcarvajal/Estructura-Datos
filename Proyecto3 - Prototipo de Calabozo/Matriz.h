/**
 * @file Matriz.h
 * @brief
 * @author Anthony Rojas y Valery Carvajal
 */
#ifndef INC_2022_IIS_DATOS_PROYECTO_3_UN_PROTO_CALABOZO_MATRIZ_H
#define INC_2022_IIS_DATOS_PROYECTO_3_UN_PROTO_CALABOZO_MATRIZ_H

/**
 * @brief Un tipo int.
 * Genera un número aleatorio dentro de un rango específico.
 * @param mínimo - número mínimo del rango.
 * @param máximo - número máximo del rango.
 * @return Retorna un número aleatorio (int numero_aleatorio).
 */
int generar_numero_aleatorio(int minimo, int maximo);

/**
 * @brief Un tipo int.
 * Inicializa una matriz con el tamaño deseado y su respectivo árbol y matriz de direcciones.
 * int **matriz - matriz con la que vamos a trabajar.
 * @param tamaño - tamaño de la matriz.
 * @return Retorna la matriz generada.
 */
int **inicializar_matriz(int tamaño);

/**
 * @brief Un tipo void.
 * Imprime la matriz de una manera clara.
 * @param matriz - matriz con la que vamos a trabajar.
 * @param tamaño - tamaño de la matriz.
 */
void imprimir_matriz(int **matriz, int Tamaño);
#endif //INC_2022_IIS_DATOS_PROYECTO_3_UN_PROTO_CALABOZO_MATRIZ_H
