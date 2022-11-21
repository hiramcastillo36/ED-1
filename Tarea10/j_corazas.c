/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 14 de noviembre del 2022
 * Descripción: Shamash le reveló que Humbaba podía revestirse hasta con C corazas protectoras y que si en algún
 *              momento no tenía ninguna puesta entonces sería vulnerable. Mientras tanto, Humbaba decidía qué
 *              corazas ponerse. Escriba un programa que siga las instrucciones de Humbaba e informe a cada paso el resultado.
 *              Dos enteros C y D que representan el número máximo de corazas que Humbaba puede ponerse y la cantidad
 *              de instrucciones, seguidos de D líneas que corresponden a las instrucciones dadas por Humbaba.
 *              Cada línea puede contener la palabra "QUITA" la cual indica que Humbaba debe quitarse una coraza, o
 *              bien la palabra "PONTE", que irá seguida del nombre de una coraza que Humbaba deberá ponerse si es que puede.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10000
#define MAX_STRING 15
typedef char TDPila[MAX_STRING];

struct pila{
    TDPila arreglo[MAX];
    int tope;
};

struct cadena {
    char cadena[MAX_STRING];
};

void inicializar_pila(struct pila *);
void apilar(struct pila *, char [MAX_STRING]);
struct cadena desapilar(struct pila *);
bool esta_vacia(const struct pila *);
int size_pila(const struct pila *);
void print_pila(struct pila *);
void solve(struct pila *, int, int);
struct cadena top(const struct pila *);

int main(void){
    int operaciones, tope;
    scanf("%d %d", &tope, &operaciones);
    struct pila nombres;
    inicializar_pila(&nombres);
    solve(&nombres, operaciones, tope);
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

void solve(struct pila *p, int operaciones, int tope){
    TDPila ultimo;
    char nombre_actual[MAX_STRING];
    char operacion[MAX_STRING];
    for(int i=0; i<operaciones; i++){
        scanf("\n%s", operacion);
        if(strcmp(operacion, "PONTE") == 0){
            scanf(" %s", nombre_actual);
            if(size_pila(p) < tope) {
                printf("%s\n", nombre_actual);
                apilar(p, nombre_actual);
            } else {
                puts("IMPOSIBLE");
            }

        }else {
            if(!esta_vacia(p)){
                printf("%s\n",desapilar(p).cadena);
            }else {
                puts("IMPOSIBLE");
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
