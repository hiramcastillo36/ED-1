/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 14 de noviembre del 2022
 * Descripción: Dado el orden en el que se metieron los autos, decirle a los del valet parking cuántos autos deben sacar para sacar el auto que les solicitaron.
 * Leerás un número N que representa la cantidad de autos que están estacionados en el callejón.
 * Cada una de las siguientes líneas contiene la placa de los autos en el orden en el que llegaron.
 * La siguiente línea es la placa del auto que fue solicitado.
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 10001
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
void buscar_placas(struct pila *, int *, TDPila);
int size_pila(const struct pila *);
void print_pila(const struct pila *);
void imprimir_posicion(const struct pila *, int);

int main(void){
    int llamadas, contador=0;
    scanf("%d", &llamadas);
    struct pila placas;
    inicializar_pila(&placas);
    TDPila valor;
    for(int i=0; i<llamadas; i++) {
        scanf("%d", &valor);
        apilar(&placas, valor);
    }
    int buscando;
    scanf("%d", &buscando);
    buscar_placas(&placas, &contador, buscando);
    imprimir_posicion(&placas, contador);
}

void imprimir_posicion(const struct pila *p, int contador){
    if(contador!=0 && size_pila(p) != 0)
        printf("%d", contador+1);
    else {
        printf("No existe el auto");
    }
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

void buscar_placas(struct pila *p, int *contador, TDPila buscando){
    while(!esta_vacia(p) && !(desapilar(p) == buscando)) {
        *contador = *contador +1;
    }
}