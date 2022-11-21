/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 14 de noviembre del 2022
 * Descripción: Las mujeres marcianas, formadas en una fila, son las encargadas de recoger a los bebés y evitar
 * que escapen. Sin embargo y para permitir que los bebés tengan la oportunidad de caminar un poco, el primer bebé que
 * sale es recogido por la última mujer de la fila, la cual posteriormente sale de la fila con el bebé en brazos.
 * Un entero N seguido de N renglones, cada uno con un caracter E y una cadena S: si E = 'B' entonces acaba de salir
 * un bebé de nombre S; si E = 'F' entonces una mujer de nombre S acaba de formarse en la fila.
 * Puedes suponer que 1 ≤ N ≤ 100000, que los nombres son distintos y de a lo mucho 10 letras, todas mayúsculas.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100000
typedef char TDPila[15];

struct pila{
    TDPila arreglo[MAX];
    int tope;
};

struct cadena {
    char cadena[15];
};

void inicializar_pila(struct pila *);
void apilar(struct pila *, char [15]);
struct cadena desapilar(struct pila *);
bool esta_vacia(const struct pila *);
int size_pila(const struct pila *);
void print_pila(struct pila *);
void solve(struct pila *, int);
struct cadena top(const struct pila *);

int main(void){
    int operaciones;
    scanf("%d", &operaciones);
    struct pila nombres;
    inicializar_pila(&nombres);
    solve(&nombres, operaciones);
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

void solve(struct pila *p, int operaciones){
    TDPila ultimo;
    char nombre_actual[MAX];
    char operacion;
    for(int i=0; i<operaciones; i++){
        scanf("\n%c %s", &operacion, nombre_actual);
        if(operacion == 'F'){
            apilar(p, nombre_actual);
        }else {
            printf("%s %s\n",nombre_actual, desapilar(p).cadena);
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

void apilar(struct pila *p, char dato[15]){
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