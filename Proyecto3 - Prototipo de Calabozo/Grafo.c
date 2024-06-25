/**
 * @file Grafo.c
 * @brief
 * @author Anthony Rojas y Valery Carvajal
 */
#include <stdlib.h>
#include <stdio.h>
#include "Grafo.h" // se agrega el archivo de cabecera "Grafo.c"

/**
 * @brief Un tipo grafo.
 * Inicializa un grafo con el tamaño deseado y una matriz de ceros.
 * @param tamaño - tamaño del grafo.
 * @return Retorna un struct grafo.
 */
    grafo *inicializar_grafo(int Tamaño)
{
    grafo *Grafo = calloc(1, sizeof(grafo));

    Grafo -> tamaño = Tamaño;
    Grafo -> matriz_adyacencia = inicializar_matriz(Tamaño);

    for (int i = 0; i < Tamaño; i++)
    {
        for (int j = 0; j < Tamaño; j++)
        {
            Grafo -> matriz_adyacencia[i][j] = 0;
        }
    }
    return Grafo;
}

int contar_aristas_nodo(grafo *Grafo, int fila)
{
    int contador = 0;

    for (int i = 0; i < Grafo -> tamaño; i++)
    {
        if (Grafo -> matriz_adyacencia[fila][i] != 0)
        {
            contador += 1;
        }
    }
    return contador;
}

/**
 * @brief Un tipo int.
 * Verifica que hayan salas que sean salidas.
 * @param Grafo - grafo con el que vamos a trabajar.
 * @param minimo_aristas_nodo - cantidad mínima de caminos que puede tener una sala.
 * @return Retorna un booleano (0 o 1).
 */
int verificar_aristas_minimas(grafo *Grafo, int minimo_aristas_nodo)
{
    for (int i = 0; i < Grafo -> tamaño; i++)
    {
        int cantidad_aritas_nodo = contar_aristas_nodo(Grafo,i);

        if(cantidad_aritas_nodo == 0)
        {
            return 0;
        }
    }
    return 1;
}

grafo *generar_grafo(int Tamaño, int maximo_aristas_nodo, int minimo_aristas_nodo)
{
    grafo *Grafo = inicializar_grafo(Tamaño);
    int nodo_partida = generar_numero_aleatorio(0, Tamaño-1);
    int nodo_llegada;
    int costo;
    int contador_ciclos = 0;

    while(!verificar_aristas_minimas(Grafo, minimo_aristas_nodo))
    {
        nodo_llegada = generar_numero_aleatorio(0, Tamaño-1);
        if(nodo_llegada != nodo_partida && Grafo -> matriz_adyacencia[nodo_partida][nodo_llegada] == 0)
        {
            if(contar_aristas_nodo(Grafo, nodo_partida) < maximo_aristas_nodo && contar_aristas_nodo(Grafo, nodo_llegada) < maximo_aristas_nodo)
            {
                costo = generar_numero_aleatorio(1,15);
                Grafo -> matriz_adyacencia[nodo_partida][nodo_llegada] = costo;
                Grafo -> matriz_adyacencia[nodo_llegada][nodo_partida] = costo;
                nodo_partida = nodo_llegada;
            }
        }
        contador_ciclos += 1;
        if(contador_ciclos > 5000)
        {
            return generar_grafo(Tamaño, maximo_aristas_nodo, minimo_aristas_nodo);
        }
    }
    return Grafo;
}

/*
int main(int argc, char *argv[])
{
    grafo *Grafo = generar_grafo(15, 4, 1);

    int **matriz = Grafo -> matriz_adyacencia;
    imprimir_matriz(matriz, Grafo -> tamaño);
}
*/
