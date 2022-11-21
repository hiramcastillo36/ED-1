/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 14 de noviembre del 2022
 * Descripción: Alicia esta vez estaba preparada pues traía consigo algunas pociones y pastelillos.
 *              Cada poción la hacía crecer una altura particular y cada pastelillo deshacía el efecto de la poción
 *              más reciente que siguiera activa. Si Alicia tomaba dos pociones y luego comía dos pastelillos,
 *              el primer pastelillo deshacía el efecto de la segunda poción y el segundo pastelillo deshacía el
 *              efecto de la primera poción. ¿Cuánto creció Alicia después de beber algunas pociones y comer algunos pastelillos?
 *              Entrada: La altura inicial A de Alicia y la cantidad N de pociones y pastelillos que tomó.
 *              Posteriormente N renglones, cada ellos con una acción de Alicia: una 'C' seguida de un entero H
 *              significa que Alicia bebió una poción que la hace crecer H unidades, mientras que una 'D' significa que
 *              Alicia comió un pastelillo que deshace el efecto de la última poción activa.
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 1000005
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
void solve(struct pila *, char);
int size_pila(const struct pila *);
void print_pila(const struct pila *);
void desapilar_imprimir_pila(struct pila *, int);

int main(void){
    int altura, llamadas;
    scanf("%d %d", &altura, &llamadas);
    struct pila alicia;
    inicializar_pila(&alicia);
    char operacion;
    for(int i=0; i<llamadas; i++) {
        scanf("\n%c", &operacion);
        solve(&alicia, operacion);
    }
    desapilar_imprimir_pila(&alicia, altura);

}

void desapilar_imprimir_pila(struct pila *p, int altura){
    while(!esta_vacia(p)){
        altura+= desapilar(p);
    }
    printf("%d", altura);
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

void solve(struct pila *p, char dato){
    TDPila valor;
    switch (dato) {
        case 'C':
            scanf(" %d", &valor);
            apilar(p, valor);
            break;
        case 'D':
            desapilar(p);
            break;
    }
}