// Eliminar el carácter de un texto
#include <stdio.h>
#include <string.h>

void eliminarCaracter(char *texto, char caracter) {
    int i, j;

    for (i = j = 0; texto[i] != '\0'; i++) {
        if (texto[i] != caracter) {
            texto[j] = texto[i];
            j++;
        }
    }
    texto[j] = '\0';
}

int main() {
    char texto[100];
    char caracter;

    printf("Ingrese un texto: ");
    fgets(texto, sizeof(texto), stdin);

    printf("Ingrese el carácter a eliminar: ");
    scanf(" %c", &caracter);

    eliminarCaracter(texto, caracter);

    printf("Texto después de eliminar el carácter '%c': %s\n", caracter, texto);

    return 0;
}


// Invertir un texto
#include <stdio.h>
#include <string.h>

void invertirTexto(char *texto) {
    int longitud = strlen(texto);
    int i, j;

    for (i = 0, j = longitud - 1; i < j; i++, j--) {
        char temp = texto[i];
        texto[i] = texto[j];
        texto[j] = temp;
    }
}

int main() {
    char texto[100];

    printf("Ingrese un texto: ");
    fgets(texto, sizeof(texto), stdin);

    // Eliminar el salto de línea al final del texto
    if (texto[strlen(texto) - 1] == '\n') {
        texto[strlen(texto) - 1] = '\0';
    }

    invertirTexto(texto);

    printf("Texto invertido: %s\n", texto);

    return 0;
}


// Copiar un texto literal a un texto en el heap
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *textoLiteral = "Este es un texto literal";
    char *textoHeap;

    textoHeap = (char *)calloc(strlen(textoLiteral) + 1, sizeof(char)); // +1 para el carácter nulo '\0'

    if (textoHeap != NULL) {
        strcpy(textoHeap, textoLiteral);

        printf("Texto literal: %s\n", textoLiteral);
        printf("Texto en el heap: %s\n", textoHeap);

        free(textoHeap);
    } else {
        printf("No se pudo asignar memoria en el heap.\n");
    }

    return 0;
}


