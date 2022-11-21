/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 14 de noviembre del 2022
 * Descripción: Dada una secuencia consistente de paréntesis, determina si la expresión está balanceada.
 * Una secuencia de paréntesis está balanceada si cada paréntesis abierto puede ser emparejado únicamente con un paréntesis de cierre. También el intervalo de elementos dentro de él debe estar balanceado.
 * Tu tendrás tres tipos de paréntesis: (,{ y [.
 *  {[()]} - Este SI es un conjunto balanceado.
 *  {[(])} - Este NO es un conjunto balanceado.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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
bool verificar_parentesis(struct pila *, char []);
int size_pila(const struct pila *);
void print_pila(const struct pila *);
void desapilar_imprimir_pila(struct pila *, int);

int main(void){
    int altura, llamadas;
    scanf("%d", &llamadas);
    struct pila parentesis;
    char cadena[MAX];
    for(int i=0; i<llamadas; i++) {
        scanf("%s", cadena);
        inicializar_pila(&parentesis);
        if( verificar_parentesis(&parentesis, cadena) == 1) {
            puts("SI");
        } else {
            puts("NO");
        }
    }
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
    return p->arreglo[(p->tope)-1];
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
    else {
        return -1;
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

bool verificar_parentesis(struct pila *p, char cadena[]){
    for(int i=0; i< strlen(cadena); i++) {
        if(cadena[i] == '{' || cadena[i] == '(' || cadena[i] == '['){
            apilar(p, cadena[i]);
        } else {
            int ultimo = top(p);
            switch (cadena[i]) {
                case '}':
                    if(ultimo+2 == (int)(cadena[i])) {
                        desapilar(p);
                    } else {
                        desapilar(p);
                        return 0;
                    }
                    break;
                case ')':
                    if(ultimo+1 == (int)(cadena[i])) {
                        desapilar(p);
                    } else {
                        desapilar(p);
                        return 0;
                    }
                    break;
                case ']':
                    if(ultimo+2 == (int)(cadena[i])) {
                        desapilar(p);
                    } else {
                        return 0;
                    }
                    break;
            }
        }

    }
    if(size_pila(p) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}