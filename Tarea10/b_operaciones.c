/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 14 de noviembre del 2022
 * Descripción: Considera una pila de enteros que tiene dos operaciones: mete(a) introduce el entero a en la pila y
 *              saca(a) elimina los a enteros en el tope de la pila (suponiendo que hay suficientes).
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 1001
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
int size_pila(const struct pila *);
void print_pila(const struct pila *);

int main(void){
    int llamadas;
    scanf("%d", &llamadas);
    struct pila p;
    inicializar_pila(&p);
    TDPila valor;
    for(int i=0; i<llamadas; i++) {
        scanf("%d", &valor);
        solve(&p, valor);
    }
    printf("%d\n", p.tope);
    print_pila(&p);
}

void print_pila(const struct pila *p){
    while(!esta_vacia(p)) {
        printf("%d ", desapilar(p));
    }
}

int size_pila(const struct pila *p){
    return p->tope;
}

TDPila top(struct pila *p) {
    return p->arreglo[p->tope];
}

void inicializar_pila(struct pila *p){
    p->tope=0;
}

void apilar(struct pila *p, TDPila dato){
    p->arreglo[p->tope] = dato;
    p->tope++;
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

void solve(struct pila *p, TDPila dato){
    if(dato > size_pila(p)) {
        apilar(p, dato);
    } else if(!esta_vacia(p)){
        while(dato!=0){
            desapilar(p);
            dato--;
        }
    }
}