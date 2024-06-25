/* Proyecto 1 de Estructuras de Datos.
 * Realizado por Valery Carvajal.   */

/*  Archivos de cabecera */
#include <stdio.h>  // Usar scanf y printf
#include <stdlib.h> // Usar calloc y free
#include <string.h> // Ayuda a tener más control sobre los char
#include <time.h> // Se usa en la función srand() como referencia de tiempo


/* Lista de artículos derivados del cáñamo industrial */
char* lista_articulos[6] = {"Maquillaje","Desinfectante","Proteína","Agramiza","Cera", "Pintura"};


/* Se define el struct de artículo */
typedef struct articulo {
    char* nombre_articulo;
    int compra_o_vende;		// Define si el artículo se compra o se vende
    int cantidad_disponible;
    int precio_articulo;
} articulo;


/* Inicializa el struct articulo, crea como una copia del struct */
articulo* nuevo_articulo(char* nombre) {
    articulo* art = calloc(1,sizeof(articulo));
    // Se define el valor de cada variable
    art -> nombre_articulo = nombre;
    art -> compra_o_vende = 0;
    art -> cantidad_disponible = 0;
    art -> precio_articulo = 0;
    return art;
}


/*-------------------------------- Tabla de Dispersión --------------------------------*/
/* Función de Dispersión (Hash) */
int tabla_dispersion(int largo_tabla, char* nombre_articulo){
    int largo_llave = strlen(nombre_articulo);
    int llave = 0;
    for(int i=1; i < largo_llave; i++){
        int valor_char = nombre_articulo[i]-'0';	// Saca la posiciones de cada producto
        llave += valor_char;
    } llave = (llave/largo_llave) % largo_tabla;	// Se saca modulo para que quede en un tamaño acorde a la tabla (hacer el número más pequeño)
    return llave;
    // Recibe los artículos y devuelve las posiciones de cada uno como un int
}


/* Inicializa función de dispersión */
articulo** nuevo_td(int largo_llave) {
    articulo** td = calloc(largo_llave, sizeof(articulo*));	// Le pone el tamaño exacto para el juego según los artículos
    return td;	//td = tabla de dispersión
}


/* Borra la tabla de dispersión */
void borrar_td(articulo** td){
    for(int i=0; i < 6; i++){
        char* art_en_lista = lista_articulos[i];
        int llave = tabla_dispersion(43, art_en_lista); // Nos da la posición del producto
        free(td[llave]);	// Libera el espacio de memoria
        td[llave] = NULL;	// Borra cada posición (cada producto)
    } free(td);	// Por último le hace free a la tabla como tal
    td = NULL;
}


/* Agrega elementos y devuelve la tabla completa (llena) con todos los datos del producto indicado con la llave */
void llenar_td(articulo** td, char* lArticulos[]){

    for(int i=0; i < 6; i++){
        char* art_en_lista = lArticulos[i];
        int llave = tabla_dispersion(43, art_en_lista);	// Al ser primo ayuda a evitar las colisiones y tener mejor dispersión
        articulo* a = nuevo_articulo(art_en_lista);
        td[llave] = a;	// Pone el artículo creado en la posición de la tabla
        
    } char* art_en_lista = lArticulos[5];
    int llave = tabla_dispersion(43, art_en_lista);
    articulo* a = nuevo_articulo(art_en_lista);
    td[llave] = a;
}


/* Modifica el tamaño de la tabla de dispersión (No se usa en este programa) */
__attribute__((unused)) articulo** cambiar_size_tabla(articulo** td, int largo_nuevo){
    articulo** tabla_nueva = nuevo_td(largo_nuevo);
    
    for(int i=0; i < (sizeof(td) / sizeof(articulo)); i++){  // Se recorre la tabla vieja
        if(td[i] != NULL){
            articulo* valor = td[i];
            int llave = tabla_dispersion(largo_nuevo, valor -> nombre_articulo);
            tabla_nueva[llave] = valor;   // Se agregan los valores de la tabla vieja a la nueva
        }
    } // Si ya no tiene espacio lo redimensiona según el largo nuevo
		if(td[sizeof(td) / sizeof(articulo)] != NULL){
        articulo* valor = td[sizeof(td) / sizeof(articulo)];
        int llave = tabla_dispersion(largo_nuevo, valor -> nombre_articulo);
        tabla_nueva[llave] = valor;
    } return tabla_nueva;
}


/* Imprime la cantidad disponible de un artículo */
void imprimir_disponibilidad_art(articulo** td){
    printf("\n");
    for(int i=0; i < 6; i++){
        char* art_en_lista = lista_articulos[i];
        int llave = tabla_dispersion(43, art_en_lista);	// Da la posición del artículo
        articulo* art = td[llave];
        if(art -> precio_articulo > 0){
            printf(">> La cantidad disponible de %s es %d \n", art -> nombre_articulo, art -> cantidad_disponible);
        }
    }
    printf("\n");
    printf("\n");

}


/* Imprime la tabla de dispersión de manera ordenada y clara */
void imprimir_tabla(articulo** td){
    for(int i=0; i < 6; i++){
        char* art_en_lista = lista_articulos[i];
        int llave = tabla_dispersion(43, art_en_lista);	// Da la posición del artículo
        articulo* a = td[llave];
        if(a -> precio_articulo > 0){
            printf("\n");
            printf("\n");
            printf(">> Nombre del artículo = %s \n", a -> nombre_articulo);
            if(a -> compra_o_vende != 0){
                printf("** ¡La ciudad busca comprar este artículo! **\n");
            } else{
                printf("** ¡La ciudad busca vender este artículo! **\n");
            } printf(">> Cantidad disponible: %d \n", a -> cantidad_disponible);
            printf(">> Precio = %d \n", a -> precio_articulo);
        }
    }     printf("+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+\n");
}


/* Se define el struct de ciudad*/
typedef struct Ciudad {
    // Elementos del struct
    char* nombre_ciudad;
    int interes_ciudad;
    articulo** tabla_articulos;  // Modifica una copia, no el puntero como tal (**)
} Ciudad;


/* Asigna los valores de los artículos de cada ciudad en las tablas. */
void val_articulo_ciudad(articulo** tProductos) {
    srand(rand()*time(NULL)*(rand()%rand()+rand()));  // Función para número random

    for(int i=0; i<=3; i++) {    // Cambia los valores de 3 productos de la tabla, los otros son 0
        char* art_en_lista = lista_articulos[rand() % 6];
        articulo* art = tProductos[tabla_dispersion(43, art_en_lista)];
        art -> precio_articulo = (rand() % 151) + 64;
        art -> compra_o_vende = rand() % 2;
        art -> cantidad_disponible = (rand() %40) + 2;
    }
}


/* Inicialización de struct Ciudad (crea una ciudad nueva) */
Ciudad* inicia_ciudad(char* n) {
    Ciudad* C = calloc(1,sizeof(Ciudad));
    articulo** tDispersion = nuevo_td(43);
    llenar_td(tDispersion, lista_articulos);
    // Asigna valores al azar a las variables de la ciudad
    C -> tabla_articulos = tDispersion;
    C -> interes_ciudad = (rand()%102)+23;
    val_articulo_ciudad(C -> tabla_articulos);
    C -> nombre_ciudad = n;
    return C;
}


/* Se define el struct de lista_ciudades */
typedef struct lista_ciudades {
    Ciudad* C;
    struct lista_ciudades* sig;
} lista_ciudades;

struct lista_ciudades* inicio = NULL; //el inicio apunta a NULL


/* Se define el struct de lista_ciudades con el inicio */
typedef struct listC {
    lista_ciudades* inicio;
}listC;


/* Inicializa lista_Ciudades */
lista_ciudades* inicia_listaCiudades(Ciudad* ciudad_nueva) {
    lista_ciudades* nodoLista = calloc(1,sizeof(lista_ciudades));
    nodoLista -> C = ciudad_nueva;  //Inserta nodos a la lista
    return nodoLista;
}

/* Inicializa listC */
listC* inicia_listC() {
    listC* largo_nuevo = calloc(1,sizeof(listC));
    return largo_nuevo;
}


/* Inserta en la lista */
int insertar_en_lista(listC* l,Ciudad* ciudad_nueva) {
    if(l == NULL) {
        printf("La lista no existe \n");
        return -1;  //si no existe la lista retorna -1
    }

    lista_ciudades* nodoLista = inicia_listaCiudades(ciudad_nueva);

    if(l -> inicio == NULL) {   //si está vacía, agregar nodo
        l -> inicio = nodoLista;
    } else {
        struct lista_ciudades* actual = l -> inicio;
        while (actual -> sig != NULL) {
            actual = actual->sig;
        }
        actual -> sig = nodoLista;
    }
    return 0;
}


/* Revisa el interés de la ciudad para ver si hay que borrar su tabla */
void revisar_interes_ciudad(Ciudad* ciudad_nueva) {
	
    // Si no hay interés suficiente, se borra la tabla de artículos
    if(ciudad_nueva -> interes_ciudad <= 30 && ciudad_nueva -> tabla_articulos != NULL){
        borrar_td(ciudad_nueva -> tabla_articulos);
        ciudad_nueva -> tabla_articulos = NULL;
    }
	
	// Si hay interés suficiente, se despliega la tabla
    if(ciudad_nueva -> interes_ciudad > 30 && ciudad_nueva -> tabla_articulos == NULL){
        articulo** tDispersion = nuevo_td(43);
        llenar_td(tDispersion, lista_articulos);
        val_articulo_ciudad(tDispersion);
        ciudad_nueva -> tabla_articulos = tDispersion;
    }
}


/* Genera la listC (lista de ciudades)
 * Recibe la cantidad de ciudades con las que quiere jugar */
listC* Generar_listC(int cantidad) {
    char* nombres_ciudades[] = {"Hogwarts","Azkaban","Ollivanders","The Leaky Cauldron","Diagon Alley","Durmstrang","Beauxbatons","Weasleys' Wizard Wheezes","Malfoy Manor","The Three Broomsticks"};
    srand(rand()*time(NULL)*(rand()%rand()+rand())); // Misma función random
	
	// Se trabajó con el ASCII
	if(cantidad < 51 && cantidad != 49){
		printf("Error: El dato ingresado es inválido. Se asignarán 3 ciudades.");
		printf("\n");
		cantidad = 3;
	}
	
	if(cantidad > 57 && cantidad != 49){
		printf("Error: El dato ingresado es inválido. Se asignarán 3 ciudades.");
		printf("\n");
		cantidad = 3;
	}
	
	if(cantidad == 51){
		cantidad = 3;
	}
	
	if(cantidad == 52){
		cantidad = 4;
	}
	
	if(cantidad == 53){
		cantidad = 5;
	}
	
	if(cantidad == 54){
		cantidad = 6;
	}
	
	if(cantidad == 55){
		cantidad = 7;
	}
	
	if(cantidad == 56){
		cantidad = 8;
	}
	
	if(cantidad == 57){
		cantidad = 9;
	}
	
	if(cantidad == 49){
		cantidad = 10;
	}
	

    listC* lista_ciudades = inicia_listC();

    for(int i=0; i < cantidad;) {
        int variable = rand()%10;
        char* nombre_ciudadNueva = nombres_ciudades[variable];
        char* nada = "o";
        if(nombre_ciudadNueva != nada){
            Ciudad* C = inicia_ciudad(nombre_ciudadNueva);
            insertar_en_lista(lista_ciudades, C);
            nombres_ciudades[variable] = "o";
            i++;
        }
    }
    return lista_ciudades;  //retorna las ciudades
}


/* Imprime la ciudad de manera clara y ordenada */
int imprimir_ciudad(Ciudad* ciudad_nueva) {
    printf("+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+\n");
    printf("*** Nombre de la ciudad: %s ***\n", ciudad_nueva -> nombre_ciudad);
    printf(">>> Interés de la ciudad: %d\n", ciudad_nueva -> interes_ciudad);

    // Si el interés es suficiente, se imprime la tabla
    if(ciudad_nueva -> interes_ciudad > 30) {
        articulo** tProductos = ciudad_nueva -> tabla_articulos;
        imprimir_tabla(tProductos);
    } else {
        printf(">>> No hay suficiente interés para comerciar :( \n");
		printf("+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+\n");
    }
    
    printf("\n");
    printf("\n");
    printf("\n");
    return 0;
}


/* Imprime la lista de ciudades */
int imprimir_listC(listC* lista) {
    lista_ciudades* actual = lista -> inicio;
    while(actual -> sig != NULL) {
        imprimir_ciudad(actual -> C);
        actual = actual -> sig;
    }
    imprimir_ciudad(actual -> C);
    return 0;
}


/* Define es struct jugador */
typedef struct jugador {
    int galleons_del_jugador;   // Valor de intercambio
    articulo** disponibilidad_articulos;
} jugador;


/* Define el valor de intercambio del jugador */
void val_jugador(articulo** ar) {
    srand(rand()*time(NULL)*(rand()%rand()+rand()));

    for(int i=0; i<6; i++) {
        char* art_en_lista = lista_articulos[i];
        articulo* art = ar[tabla_dispersion(43, art_en_lista)];
        
        // Se definen valores random
        art -> precio_articulo=(rand()%46) + 62;
        art -> cantidad_disponible=(rand()%23) + 13;
    }
}


/* Inicializar Jugador */
jugador* inicio_jugador() {
    jugador* jug = calloc(1,sizeof(jugador));
    jug -> galleons_del_jugador = 4200;	// Inicia el juego con 4200 galeones
    
    // Se despliega la lista
    articulo** tDispersion = nuevo_td(43);
    llenar_td(tDispersion, lista_articulos);
    jug -> disponibilidad_articulos = tDispersion;
    val_jugador(jug -> disponibilidad_articulos);
    return jug;
}


/* Imprime los datos del jugador */
void imprimir_jugador(jugador* jug) {
    printf("¡Hola! Estos son tus recursos actuales: \n");
    printf("\n");
    printf("** Tienes %d galeones **\n", jug -> galleons_del_jugador);
	imprimir_disponibilidad_art(jug -> disponibilidad_articulos);
}


/* Comprar artículo(s) */
int comprar(int cant_a_comprar, articulo* a, jugador* jug) {
    int precio_arts = a -> precio_articulo;
    char* art_en_lista = a -> nombre_articulo;
    int total = cant_a_comprar*precio_arts;

    articulo* arti = jug -> disponibilidad_articulos[tabla_dispersion(43, art_en_lista)];
	
    // Revisa si le alcanza el dinero o no para la compra
    if (jug -> galleons_del_jugador < total) {
        printf("Compra fallida: Necesitas más galeones para realizar esa compra \n");
        printf("\n");
        return 0;
    }

    // Revisa si hay producto suficiente
    if (a -> cantidad_disponible < cant_a_comprar) {
        printf("Compra fallida: No hay esa cantidad de artículos disponible \n");
        printf("\n");
        return 0;
    }
	
	// Cambia los valores después de la transacción
    arti -> cantidad_disponible += cant_a_comprar;
    a -> cantidad_disponible -= cant_a_comprar;
    jug -> galleons_del_jugador -= total;

    return 1;
}


/* Vender artículo(s) */
int vender(int cant_a_comprar, articulo* a, jugador* jug){
    char* art_en_lista = a -> nombre_articulo;
    int pr = a -> precio_articulo;
    int total = cant_a_comprar*pr;
    articulo* arti = jug -> disponibilidad_articulos[tabla_dispersion(43, art_en_lista)];

    // Revisar si hay suficiente producto para vender
    if (arti -> cantidad_disponible < cant_a_comprar) {
        printf("Venta fallida: No tienes esa cantidad de artículos disponible, compra más para poder vender! \n");
        printf("\n");
        return 0;
    }

	// Cambia los valores después de la transacción
    arti -> cantidad_disponible -= cant_a_comprar;
    a -> cantidad_disponible += cant_a_comprar;
    jug -> galleons_del_jugador += total;

    return 1;
}


/* Función para negociar con ciudad */
int negociar(Ciudad* ciudad_nueva, jugador* jug){
	
    // Si hay interés suficiente
    if(ciudad_nueva -> interes_ciudad > 30){
        int estado_negocio;
        char* entrada = "a";
        int llave = tabla_dispersion(43, entrada);
        
        while(ciudad_nueva -> tabla_articulos[llave] == NULL || ciudad_nueva -> tabla_articulos[llave] -> precio_articulo == 0){
            printf("¿Con qué artículo deseas comerciar? Ingrese uno válido: ");
            char e[100];
            scanf("%s", e);
            printf("\n");
            llave = tabla_dispersion(43, e);
        }


		// Revisa si quiere comprar
        if(ciudad_nueva -> tabla_articulos[llave] -> compra_o_vende == 0){
            printf("¿Qué cantidad desea comprar? ");
            int cant_a_comprar;
            scanf("%d", &cant_a_comprar);
            printf("\n");
            estado_negocio = comprar(cant_a_comprar, ciudad_nueva -> tabla_articulos[llave], jug);

        }
		
		// O vender
        if(ciudad_nueva -> tabla_articulos[llave] -> compra_o_vende != 0){
            printf("¿Qué cantidad desea vender? ");
            int cant_a_comprar;
            scanf("%d", &cant_a_comprar);
            printf("\n");
            estado_negocio = vender(cant_a_comprar, ciudad_nueva -> tabla_articulos[llave], jug);
        }
        return estado_negocio;
    } else {
		
		// Si no hay interés suficiente, lo sube
        srand(rand()*time(NULL)*(rand()%rand()+rand()));
        ciudad_nueva -> interes_ciudad += rand() % 11 + 15;
        return 1;
    }
}


/* Pasar a la siguiente ronda */
void sig_ronda(listC* lista){
    srand(rand()*time(NULL)*(rand()%rand()+rand()));
    int disminucion_interes = rand() % 5 +1;	// Disminuye el interés de la ciudad
    lista_ciudades* actual = lista -> inicio;
	int op = actual -> C -> interes_ciudad;

    while (actual -> sig != NULL) {     // Toda la lista hasta el final
        op = op - disminucion_interes;

        if(op < 0) {
            op = 0;  // 0 es el mínimo de interés
        }

        revisar_interes_ciudad(actual -> C);
        actual = actual -> sig;   // Se pasa al siguiente para revisar todos

    }
    // El interés disminuye por cada ronda
    op = op - disminucion_interes;

    if(op < 0){
        op = 0;  // Se vuelve a verificar que no sea menor a 0
    }

    revisar_interes_ciudad(actual -> C);
    actual = actual -> sig;
}


/* Se toma las ciudades con las cuales se va a jugar */
Ciudad* elegir_ciudad(listC* ciudades){
    lista_ciudades* actual = ciudades -> inicio;
    Ciudad* ciudad_nueva;
    int largo_llave = 0;

    while (actual -> sig != NULL) {  // Toda la lista hasta el final
        largo_llave += 1;
        actual = actual -> sig;
    }

    largo_llave += 1;
    int i = 1;
    printf("¿Con qué ciudad deseas comerciar? Ingrese un número válido: ");

    int cant;
    scanf("%d", &cant);
    printf("\n");

    while(cant > largo_llave || cant <= 0) {
        printf("Error: Número inválido.");
        printf("\n");
        printf("\n");
        printf("¿Con qué ciudad deseas comerciar? Ingrese un número válido: ");
        scanf("%d", &cant);
        printf("\n");
    }
	
	// Cambia los valores
    actual = ciudades -> inicio;
    ciudad_nueva = actual -> C;

    while(i != cant){
        actual = actual -> sig;
        ciudad_nueva = actual -> C;
        i++;
    }

    return ciudad_nueva;
}


/* Define si ganó o perdió */
char* winOrLose(int galleons){
	if(galleons <= 10){	// Pierde si tiene menos de 10 galeones
        return "¡Rayos! Perdiste \n";
    }
    return "¡Enhorabuena! Has ganado el juego :) \n";
}


/* Controlador del juego */
void controller(listC* ciudades, jugador* jug){
    int num_ronda = 1;
    while(num_ronda <= 30){
        printf("\n");
        printf("####################################### Ronda %d ########################################\n", num_ronda);
        printf("\n");
        printf("\n");
        imprimir_jugador(jug);
        imprimir_listC(ciudades);
        Ciudad* ciudad_nueva = elegir_ciudad(ciudades);
        int resultado = negociar(ciudad_nueva,jug);

        while(resultado!=1){
            resultado = negociar(ciudad_nueva,jug);
        }

        num_ronda++;
        sig_ronda(ciudades);
    }
    printf("############################ Fin del juego ############################\n");
    imprimir_listC(ciudades);
    imprimir_jugador(jug);
    int resultadoFinal = jug -> galleons_del_jugador;
    char* r = winOrLose(resultadoFinal);
    printf("%s", r);
}

int main(){
    char cant_ciudades;
    printf("############################ Bienvenido al mundo mágico de Harry Potter ¡Buena suerte! ############################ \n");
    printf("\n");
    printf("Objetivo: Evita perder todos tus galeones pero más importante.. ¡Diviértete Hechicer@!\n");
    printf("\n");
    printf("\n");
    printf(">> ¿Cuántas ciudades deseas que haya en el juego? Por favor ingresa un número entre 3 y 10: ");
    scanf("%s", &cant_ciudades);
    int cant_ciudades_int = cant_ciudades-'\0';
    printf("\n");
    printf("\n");
    listC* ciudades = Generar_listC(cant_ciudades_int);
    jugador* jug = inicio_jugador();
    controller(ciudades,jug);

    return 0;
}


