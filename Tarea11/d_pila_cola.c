/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 22 de noviembre del 2022
 * Descripción: Como siempre has sido muy creativo, acabas de inventar la pila-cola, la cual es una estructura de datos
 * que comienza comportándose como una pila, pero que puede cambiar su comportamiento al de una cola. Deseas escribir un
 * programa que procese una secuencia de  eventos sobre una pila-cola:
 * Los eventos que procesarás pueden ser de tres tipos:
 * AGREGA : Agrega el entero  a la pila-cola.
 * QUITA: Saca un elemento de la pila-cola e imprime su valor.
 * CAMBIA: Cambia el comportamiento de la pila-cola (si se comportaba como pila ahora será una cola, y viceversa).
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 75000
typedef int TDato;

struct cola {
    TDato arreglo[MAX];
    int frente;
    int atras; // funciona igual que el tope
};

bool esta_llena(const struct cola*);
bool esta_vacia(const struct cola*);
void insertar(struct cola *, int);
void eliminar(struct cola *);
void inicializar_cola(struct cola *);
TDato obtener_primero(const struct cola *);
void solve( struct cola *, int);
TDato desapilar(struct cola *);

int main(void){
    int operaciones;
    scanf("%d", &operaciones);
    struct cola pila_cola;
    inicializar_cola(&pila_cola);
    solve(&pila_cola, operaciones);
    return 0;
}

bool esta_llena(const struct cola *c){
    return  (c->atras+1)%MAX == c->frente;
}

bool esta_vacia(const struct cola *c){
    return (c->frente==c->atras);
}

void insertar(struct cola *c, int dato){
    if(!esta_llena(c)){
        c->arreglo[c->atras]=dato;
        c->atras=((c->atras+1)%MAX);
    }
}

void apilar(struct cola *c, int dato){
    if(!esta_llena(c)){
        c->arreglo[c->atras]=dato;
        c->atras=((c->atras+1)%MAX);
    }
}

void eliminar(struct cola *c){
    if(!esta_vacia(c)){
        c->frente=(c->frente+1)%MAX;
    }
}

void inicializar_cola(struct cola *c){
    c->atras=0;
    c->frente=0;
}

int desapilar(struct cola *c) {
    if (!esta_vacia(c)) {
        c->atras--;
        return c->arreglo[c->atras];
    }
}
TDato obtener_primero(const struct cola *c){
    if(!esta_vacia(c)){
        return c->arreglo[c->frente];
    }
}

TDato size_cola(const struct cola *c){
    if(c->atras < c->frente ){
        return (c->atras - c->frente) + MAX;
    } else if(c->atras >= c->frente){
        return (c->atras - c->frente);
    }
}

void solve(struct cola *c, int operaciones){
    TDato  datos;
    char operacion[15];
    int bandera=0; // 0= pila / 1 = cola
    for(int i=0; i<operaciones; i++){
        scanf("\n%s", operacion);
        if(strcmp("AGREGA", operacion)==0){
            scanf(" %d", &datos);
            insertar(c, datos);
        } else if(strcmp("QUITA", operacion) == 0){
            if(bandera==0) {
                printf("%d\n", desapilar(c));
            } else {
                printf("%d\n", obtener_primero(c));
                eliminar(c);
            }
        } else {
            if (bandera == 0) {
                bandera = 1;
            } else {
                bandera = 0;
            }
        }
    }
}