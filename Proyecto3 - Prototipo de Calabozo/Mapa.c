/**
 * @file Mapa.c
 * @brief
 * @author Anthony Rojas y Valery Carvajal
 */
#include <stdlib.h>
#include <stdio.h>
#include "Mapa.h" // se agrega el archivo de cabecera "Prim.c"

/**
 * @brief Un tipo int.
 *
 * @param nodo - cada sala.
 * @param direccion - dirección del nodo.
 * @param tamaño - tamaño del mapa.
 * @return Retorna un struct mapa.
 */
int direccion_disponible(int* nodo, int direccion, int tamaño)
{
    for(int i = 0; i < tamaño; i++)
    {
        if(nodo[i] == direccion)
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Un tipo void.
 * Establece las direcciones en la matriz, de manera que,
 * si la sala 1 se conecta con la 2 por el sur, la 2 se conecta con la 1 por el norte.
 * int **Matriz_adyacencia - matriz de adyacencia del Mapa recibido.
 * @param Mapa - mapa con el que vamos a trabajar.
 */
void establecer_matriz_direcciones(mapa* Mapa)
{
    int **Matriz_adyacencia = Mapa -> Arbol -> matriz_adyacencia;

    for(int i = 0; i < Mapa -> tamaño; i++)
    {
        int direccion = 5;

        for(int j = 0; j < Mapa -> tamaño; j++)
        {
            if(direccion_disponible(Mapa -> matriz_direcciones[i], 1, Mapa -> tamaño) && direccion_disponible(Mapa -> matriz_direcciones[j], 4, Mapa -> tamaño))
            {
                direccion = 1;
            }
            if(direccion_disponible(Mapa -> matriz_direcciones[i], 2, Mapa -> tamaño) && direccion_disponible(Mapa -> matriz_direcciones[j], 3, Mapa -> tamaño))
            {
                direccion = 2;
            }
            if(direccion_disponible(Mapa -> matriz_direcciones[i], 3, Mapa -> tamaño) && direccion_disponible(Mapa -> matriz_direcciones[j], 2, Mapa -> tamaño))
            {
                direccion = 3;
            }
            if(direccion_disponible(Mapa -> matriz_direcciones[i], 4, Mapa -> tamaño) && direccion_disponible(Mapa -> matriz_direcciones[j], 1, Mapa -> tamaño))
            {
                direccion = 4;
            }

            if(Matriz_adyacencia[i][j] != 0 && Mapa -> matriz_direcciones[i][j] == 0)
            {
                Mapa -> matriz_direcciones[i][j] = direccion;
                Mapa -> matriz_direcciones[j][i] = 4 - direccion + 1;
                direccion += 1;
            }
        }
    }
}

mapa* inicializar_mapa(int Tamaño)
{
    mapa* Mapa = calloc(1, sizeof(mapa));

    Mapa->Arbol = prim(generar_grafo(Tamaño, 4, 1));
    Mapa->tamaño = Tamaño;
    Mapa->matriz_direcciones = inicializar_matriz(Tamaño);

    establecer_matriz_direcciones(Mapa);

    return Mapa;
}
/*
void main(int argc, char *argv[])
{
    mapa* Mapa = inicializar_mapa(10);
    arbol_expansion_minima* Arbol = Mapa -> Arbol;
    printf("Finalizado. \n");

    imprimir_matriz(Arbol -> matriz_adyacencia, Mapa -> tamaño);
    printf("--------------------------------------------------- \n");
    imprimir_matriz(Mapa -> matriz_direcciones, Mapa -> tamaño);
    printf("--------------------------------------------------- \n");
    int* ruta = Dijkstra(Arbol -> matriz_adyacencia, Arbol -> tamaño, 3, 8);
}
}*/