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
#include <string.h>
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
bool esta_vacia(const struct pila *);
void eliminar_caracter(struct pila *);
void eliminar_linea(struct pila *);
int size_pila(const struct pila *);
void print_pila(struct pila *);
void solve(struct pila *, int);
struct pila invertir_pila(struct pila *);
TDPila top(const struct pila *);

int main(void){
    int operaciones;
    scanf("%d", &operaciones);
    struct pila numeros;
    inicializar_pila(&numeros);
    solve(&numeros, operaciones);
    printf("%d\n", size_pila(&numeros));
    print_pila(&numeros);
}

TDPila top(const struct pila *p){
    if(!esta_vacia(p)) {
        return p->arreglo[(p->tope)-1];
    } else {
        return -1;
    }
}

void solve(struct pila *p, int operaciones){
    TDPila dato, ultimo;
    for(int i=0; i<operaciones; i++){
        scanf("%d", &dato);
        apilar(p,dato);
        while(top(p) == dato){
            ultimo = desapilar(p);
            if(ultimo == top(p)) {
                desapilar(p);
                apilar(p, dato+ultimo);
                dato+=ultimo;
            } else {
                apilar(p, ultimo);
                break;
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

bool esta_vacia(const struct pila *p){
    if(p -> tope == 0) {
        return true;
    } else {
        return false;
    }
}
