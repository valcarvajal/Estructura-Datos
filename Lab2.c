// Número par o impar
#include <stdio.h>

int main() {
    int numero;

    printf("Ingrese un número: ");
    scanf("%d", &numero);

    if (numero % 2 == 0) {
        printf("El número %d es par.\n", numero);
    } else {
        printf("El número %d es impar.\n", numero);
    }

    return 0;
}

// Fibonacci
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int limite, i;

    printf("Ingrese el número límite de la secuencia de Fibonacci: ");
    scanf("%d", &limite);

    printf("Secuencia de Fibonacci hasta %d:\n", limite);
    for (i = 0; i <= limite; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}


// Factorial
#include <stdio.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int numero;

    printf("Ingrese un número: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("No se puede calcular el factorial de un número negativo.\n");
    } else {
        unsigned long long resultado = factorial(numero);
        printf("El factorial de %d es: %llu\n", numero, resultado);
    }

    return 0;
}


// Len de número con for
#include <stdio.h>

int calcularLongitud(int numero) {
    int longitud = 0;

    if (numero == 0) {
        longitud = 1;
    } else {
        for (; numero != 0; numero /= 10) {
            longitud++;
        }
    }

    return longitud;
}

int main() {
    int numero;

    printf("Ingrese un número: ");
    scanf("%d", &numero);

    int longitud = calcularLongitud(numero);

    printf("La longitud del número %d es: %d\n", numero, longitud);

    return 0;
}


// Len de número con while
#include <stdio.h>

int calcularLongitud(int numero) {
    int longitud = 0;

    if (numero == 0) {
        longitud = 1;
    } else {
        while (numero != 0) {
            numero /= 10;
            longitud++;
        }
    }

    return longitud;
}

int main() {
    int numero;

    printf("Ingrese un número: ");
    scanf("%d", &numero);

    int longitud = calcularLongitud(numero);

    printf("La longitud del número %d es: %d\n", numero, longitud);

    return 0;
}


// Sumatoria de 0 a n con for
#include <stdio.h>

int main() {
    int n, i, sumatoria = 0;

    printf("Ingrese un número entero: ");
    scanf("%d", &n);

    for (i = 0; i <= n; i++) {
        sumatoria += i;
    }

    printf("La sumatoria desde 0 hasta %d es: %d\n", n, sumatoria);

    return 0;
}


// Sumatoria de 0 a n con while
#include <stdio.h>

int main() {
    int n, i = 0, sumatoria = 0;

    printf("Ingrese un número entero: ");
    scanf("%d", &n);

    while (i <= n) {
        sumatoria += i;
        i++;
    }

    printf("La sumatoria desde 0 hasta %d es: %d\n", n, sumatoria);

    return 0;
}


// Invertir un número
#include <stdio.h>

int invertirNumero(int numero) {
    int invertido = 0;

    while (numero != 0) {
        invertido = invertido * 10 + numero % 10;
        numero /= 10;
    }

    return invertido;
}

int main() {
    int numero;

    printf("Ingrese un número entero: ");
    scanf("%d", &numero);

    int numeroInvertido = invertirNumero(numero);

    printf("El número invertido es: %d\n", numeroInvertido);

    return 0;
}


// Número es palíndromo?
#include <stdio.h>

int invertirNumero(int numero) {
    int invertido = 0;

    while (numero != 0) {
        invertido = invertido * 10 + numero % 10;
        numero /= 10;
    }

    return invertido;
}

int esPalindromo(int numero) {
    int numeroInvertido = invertirNumero(numero);
    
    return (numero == numeroInvertido);
}

int main() {
    int numero;

    printf("Ingrese un número entero: ");
    scanf("%d", &numero);

    if (esPalindromo(numero)) {
        printf("El número %d es un palíndromo.\n", numero);
    } else {
        printf("El número %d no es un palíndromo.\n", numero);
    }

    return 0;
}


