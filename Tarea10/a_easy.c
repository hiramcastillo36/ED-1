/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 14 de noviembre del 2022
 * Descripción: Tienes una pila vacía de números enteros y se te proporcionarán algunas instrucciones.
 *              Estas instrucciones son las operaciones básicas de una pila (Pop, Push, Top).
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 100001
typedef int TDPila;

struct pila{
    TDPila arreglo[MAX];
    int tope;
};

void inicializar_pila(struct pila *);
void apilar(struct pila *, TDPila);
TDPila desapilar(struct pila *);
bool esta_llena(const struct pila *);
bool esta_vacia(const struct pila *);
TDPila top(struct pila *);
void solve(struct pila *, int);

int main(void){
    int llamadas;
    scanf("%d", &llamadas);
    struct pila p;
    inicializar_pila(&p);
    TDPila aux;
    for(int i=0; i<llamadas; i++) {
        scanf("\n%d", &aux);
        solve(&p, aux);
    }
}

TDPila top(struct pila *p) {
    return p->arreglo[p->tope];
}

void inicializar_pila(struct pila *p){
    p->tope=0;
}

void apilar(struct pila *p, TDPila dato){
    p->tope++;
    p->arreglo[p->tope] = dato;

}

TDPila desapilar(struct pila *p){
    if(!esta_vacia(p)){
        p->tope--;
        return p->arreglo[p->tope];
    }
}

bool esta_llena(const struct pila *p){
    if(p -> tope == MAX) {
        return true;
    } else {
        return false;
    }
}

bool esta_vacia(const struct pila *p){
    if(p -> tope == 0) {
        return true;
    } else {
        return false;
    }
}

void solve(struct pila *p, int operacion){
    TDPila dato;
    if(operacion==1) {
        scanf(" %d", &dato);
        apilar(p, dato);
    }
    if(operacion==2){
        desapilar(p);
    }
    if(operacion==3){
        if(esta_vacia(p)) {
            printf("\nEmpty!");
        } else {
            printf("\n%d", top(p));
        }
    }
}