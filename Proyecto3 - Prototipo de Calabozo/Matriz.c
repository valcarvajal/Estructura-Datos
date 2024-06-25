/**
 * @file Matriz.c
 * @brief
 * @author Anthony Rojas y Valery Carvajal
 */
#include <stdio.h>  // se agrega el archivo de cabecera "standard input output header" para poder usar el printf y el scanf
#include <stdlib.h> // se agrega el archivo de cabecera "stdlib.h" para poder utilizar el calloc y el free
#include <string.h> // se agrega el archivo de cabecera "string.h" para poder tener un mayor manejo de las cadenas de caracterechar
#include <time.h>   // se agrega el archivo de cabecera "time.h" para poder utilizar el tiempo como referencia en la funcion rand()

int generar_numero_aleatorio(int minimo, int maximo)
{
    srand(rand() * time(NULL) * (rand() % rand() + rand()));
    int numero_aleatorio = (rand() % (maximo - minimo + 1)) + minimo;
    return numero_aleatorio;
}

int **inicializar_matriz(int tamaño)
{
    int **matriz;
    matriz = (int **)calloc(tamaño, sizeof(int*));
    for (int i = 0; i < tamaño; i++)
    {
        matriz[i] = (int *)calloc(tamaño, sizeof(int));
    }

    return matriz;
}

/*
void imprimir_matriz(int **matriz, int Tamaño)
{
    
    printf("-------------------------------------------------------------------\n");
    printf("      ");  
    for (int k = 0; k < Tamaño; k++)
    {
        printf("#%3d  ", k);  
    }
    printf("\n");
    printf("       ———————————————————————————————————————————————————————————\n");
    for (int i = 0; i < Tamaño; i++)
    {
        printf("#%3d  |", i);
        for (int j = 0; j < Tamaño; j++)
        {
            printf("%3d  |", matriz[i][j]);
        }
        printf("\n");
        printf("       ———————————————————————————————————————————————————————————\n");
    }
    printf("-------------------------------------------------------------------\n");
}*/

void imprimir_matriz(int **matriz, int Tamaño)
{
    printf("\n");
    printf("-------");
    for (int g = 0; g < Tamaño; g++) printf("------");

    printf("\n");
    printf("      ");
    for (int k = 0; k < Tamaño; k++) printf("#%3d  ", k);

    printf("\n");
    printf("      —");
    for (int j = 0; j < Tamaño; j++) printf("——————");

    printf("\n");
    for (int i = 0; i < Tamaño; i++)
    {
        printf("#%3d  |", i);
        for (int j = 0; j < Tamaño; j++) printf("%3d  |", matriz[i][j]);
        printf("\n");
        printf("      —");

        for (int j = 0; j < Tamaño; j++) printf("——————");
        printf("\n");
    }

    printf("-------");
    for (int g = 0; g < Tamaño; g++) printf("------");
    printf("\n");
}