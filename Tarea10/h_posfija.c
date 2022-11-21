/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 14 de noviembre del 2022
 * Descripción: La suma de dos números A + B es escrita como A B +. La expresión B C + D * es equivalente a
 *              (B + C) * D y A B C + D * + es equivalente a A + (B + C) * D (Considere que el símbolo de la multiplicación es *).
 *              Una ventaja de esta notación es que no requiere de paréntesis o reglas de prioridad en los operadores.
 *              Dada una expresión en notación posfija, evalúe el resultado de ella.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100000
typedef long long int TDPila;

struct pila{
    TDPila arreglo[MAX];
    int tope;
};

void inicializar_pila(struct pila *);
void apilar(struct pila *, TDPila);
TDPila desapilar(struct pila *);
bool esta_vacia(const struct pila *);
int size_pila(const struct pila *);
void print_pila(struct pila *);
void solve(struct pila *, int);
TDPila top(const struct pila *);

int main(void){
    int operaciones;
    scanf("%d", &operaciones);
    struct pila numeros;
    inicializar_pila(&numeros);
    solve(&numeros, operaciones);
    printf("%lld", desapilar(&numeros));
}

TDPila top(const struct pila *p){
    if(!esta_vacia(p)) {
        return p->arreglo[(p->tope)-1];
    } else {
        return -1;
    }
}

void solve(struct pila *p, int operaciones){
    TDPila ultimo;
    char dato[MAX];
    for(int i=0; i<operaciones; i++){
        scanf("\n%s", &dato);
        if(strcmp(dato, "+") == 0 ||strcmp(dato, "-") == 0 || strcmp(dato, "*") == 0 || strcmp(dato, "/") == 0  ){
           if(strcmp(dato, "+") == 0){
               ultimo = desapilar(p);
               apilar(p, ultimo+ desapilar(p));
           }
            if(strcmp(dato, "-") == 0){
                ultimo = desapilar(p);
                apilar(p,  desapilar(p)-ultimo);
            }
            if(strcmp(dato, "*") == 0){
                ultimo = desapilar(p);
                apilar(p, ultimo* desapilar(p));
            }
            if(strcmp(dato, "/") == 0){
                ultimo = desapilar(p);
                apilar(p,  desapilar(p)/ultimo);
            }
        } else {
            apilar(p, atoll(dato));
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
