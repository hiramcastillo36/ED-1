/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 22 de noviembre del 2022
 * Descripción: Cierta computadora tiene un procesador que puede atender un proceso a la vez por K unidades de tiempo.
 * Si el proceso necesita más de K unidades para terminar, el procesador lo atiende exactamente K unidades y deja
 * pendientes las unidades excedentes. Cuando un proceso es atendido y no finaliza, se forma al final de la lista de
 * procesos pendientes.
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 10000

struct proceso{
    int id;
    int tiempo;
};

typedef struct proceso TDato;

struct cola {
    TDato arreglo[MAX];
    int frente;
    int atras;
};

bool esta_llena(const struct cola*);
bool esta_vacia(const struct cola*);
void insertar(struct cola *, TDato);
void eliminar(struct cola *);
void inicializar_cola(struct cola *);
TDato obtener_primero(const struct cola *);
void solve(struct cola *, struct cola *, int, int);
void scanf_cola(struct cola *, int);
void print_cola(const struct cola *);
int size_cola(const struct cola *);

int main(void){
    int operaciones, tiempo_k;
    scanf("%d %d", &operaciones, &tiempo_k);
    struct cola procesos, resultados;
    inicializar_cola(&procesos);
    inicializar_cola(&resultados);
    scanf_cola(&procesos, operaciones);
    solve(&procesos, &resultados, tiempo_k, operaciones);
    print_cola(&resultados);
    return 0;
}

void print_cola(const struct cola *c){
    while(!esta_vacia(c)){
        printf("%d\n", obtener_primero(c).id);
        eliminar(c);
    }
}

void scanf_cola(struct cola *c, int operaciones){
    TDato aux;
    for(int i=0; i<operaciones; i++){
        scanf("%d %d", &aux.id, &aux.tiempo);
        insertar(c, aux);
    }
}

bool esta_llena(const struct cola *c){
    return  (c->atras+1)%MAX == c->frente;
}
bool esta_vacia(const struct cola *c){
    return (c->frente==c->atras);
}
void insertar(struct cola *c, TDato dato){
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

TDato obtener_primero(const struct cola *c){
    if(!esta_vacia(c)){
        return c->arreglo[c->frente];
    }
}

int size_cola(const struct cola *c){
    if(c->atras < c->frente ){
        return (c->atras - c->frente) + MAX;
    } else if(c->atras >= c->frente){
        return (c->atras - c->frente);
    }
}

void solve(struct cola *c, struct cola *resultados, int tiempo_k, int operaciones){
    TDato aux;
    while(size_cola(resultados) < operaciones){
        if(obtener_primero(c).tiempo <= tiempo_k){
            insertar(resultados, obtener_primero(c));
            eliminar(c);
        } else {
            aux.tiempo = obtener_primero(c).tiempo - tiempo_k;
            aux.id = obtener_primero(c).id;
            insertar(c, aux);
            eliminar(c);
        }
    }
}