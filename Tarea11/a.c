/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 14 de noviembre del 2022
 * Descripción: Cada que cae un bloque, ocurre lo siguiente: mientras los dos bloques que están hasta arriba de la
 *              torre sean iguales, ambos se combinan en un sólo bloque con valor igual a la suma de los bloques que se combinaron.
 *              Esto ocurre hasta que ya no haya bloques iguales juntos. En ese momento, cae el siguiente bloque.
 *              Escribe un programa que, dada la secuencia de bloques que caerán, diga cómo queda la torre de bloques al final.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10001
#define MAX_STRING 15
typedef char TDPila[MAX_STRING];

struct pila{
    TDPila arreglo[MAX];
    int tope;
};

struct cola{
    TDPila arreglo[MAX];
    int frente;
    int atras;
};

struct cadena {
    char cadena[MAX_STRING];
};

//FUNCIONES PILA

void inicializar_pila(struct pila *);
void apilar(struct pila *, char [MAX_STRING]);
struct cadena desapilar(struct pila *);
bool esta_vacia(const struct pila *);
int size_pila(const struct pila *);
void print_pila(struct pila *);
struct cadena top(const struct pila *);

//FUNCIONES COLA
bool esta_llena_c(const struct cola *);
bool esta_vacia_c(const struct cola *);
void insertar(struct cola *, char [MAX_STRING]);
void eliminar(struct cola *);
struct cadena obtener_primero(const struct cola *);
void inicializar_cola(struct cola *);

//Solucion problema
void solve(struct pila *, struct cola *, int);

int main(void){
    int operaciones;
    scanf("%d", &operaciones);
    struct pila fila_2;
    struct cola fila_1;
    inicializar_cola(&fila_1);
    inicializar_pila(&fila_2);
    solve(&fila_2, &fila_1, operaciones);
}


void solve(struct pila *p, struct cola *c, int operaciones){
    int dato, tipo_fila;
    char operacion_fila, nombre[MAX_STRING];
    for(int i=0; i<operaciones; i++){
        scanf("\n%c %d", &operacion_fila, &tipo_fila);
        if (operacion_fila=='E'){
            scanf(" %s", nombre);
            if(tipo_fila==1){
                insertar(c, nombre);
            } else {
                apilar(p, nombre);
            }
        } else {
            if(tipo_fila==1){
                printf("%s\n", obtener_primero(c).cadena);
                eliminar(c);
            } else {
                printf("%s\n", desapilar(p).cadena);
            }
        }
    }
}

void print_pila(struct pila *p){
    while(!esta_vacia(p)) {
        printf("%d\n", desapilar(p));
    }
}

int size_pila(const struct pila *p){
    return p->tope;
}

void inicializar_pila(struct pila *p){
    p->tope=0;
}

void apilar(struct pila *p, char dato[MAX_STRING]){
    strcpy(p->arreglo[p->tope], dato);
    p->tope++;
}

struct cadena desapilar(struct pila *p){
    if(!esta_vacia(p)){
        struct cadena aux;
        p->tope--;
        strcpy(aux.cadena, p->arreglo[p->tope]);
        return aux;
    }
}

bool esta_vacia(const struct pila *p){
    if(p -> tope == 0) {
        return true;
    } else {
        return false;
    }
}

struct cadena top(const struct pila *p){
    struct cadena aux;
    if(!esta_vacia(p)) {
        strcpy(aux.cadena, p->arreglo[(p->tope)-1]);
    } else {
        strcpy(aux.cadena, "-1");
    }
    return aux;
}

bool esta_vacia_c(const struct cola *c){
    return (c->frente==c->atras);
}

bool esta_llena_c(const struct cola *c){
    return ((c->atras+1)%MAX == c->frente);
}

void insertar(struct cola *c, char dato[MAX_STRING]){
    if(!esta_llena_c(c)){
        strcpy(c->arreglo[c->atras], dato);
        c->atras=(c->atras+1)%MAX;
    }
}
void eliminar(struct cola *c){
    if(!esta_vacia_c(c)){
        c->frente=(c->frente+1)%MAX;
    }
}

struct cadena obtener_primero(const struct cola *c){
    struct cadena aux;
    if(!esta_vacia_c(c)) {
        strcpy(aux.cadena, c->arreglo[c->frente]);
    } else {
        strcpy(aux.cadena, "-1");
    }
    return aux;
}

void inicializar_cola(struct cola *c){
    c->frente=0;
    c->atras=0;
}
