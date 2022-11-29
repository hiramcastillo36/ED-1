/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 22 de noviembre del 2022
 * Descripción: Hay dos colas: la de los alumnos y la de los trabajadores. Cuando es el turno de atender a la siguiente
 * persona, la política de la cafetería es darle preferencia a la gente formada en la cola de los trabajadores;
 * los alumnos son atendidos sólo si no hay trabajadores formados. Con esta información, escribe un programa que
 * procese una secuencia de  eventos
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 25000
#define MAX_STRING 15
typedef char TDato[MAX_STRING];

struct cola{
    TDato arreglo[MAX];
    int frente;
    int atras;
};

struct cadena {
    char cadena[MAX_STRING];
};

//FUNCIONES COLA
bool esta_llena_c(const struct cola *);
bool esta_vacia_c(const struct cola *);
void insertar(struct cola *, char [MAX_STRING]);
void eliminar(struct cola *);
struct cadena obtener_primero(const struct cola *);
void inicializar_cola(struct cola *);
int size_cola(const struct cola *);

//Solucion problema
void solve(struct cola *, struct cola *, int);

int main(void){
    int operaciones;
    scanf("%d", &operaciones);
    struct cola estudiantes;
    struct cola profesores;
    inicializar_cola(&estudiantes);
    inicializar_cola(&profesores);
    solve(&estudiantes, &profesores, operaciones);
}


void solve(struct cola *estudiantes, struct cola *profesores, int operaciones){

    TDato operacion;
    TDato tipo_fila;
    TDato nombre;
    int bandera;
    for(int i=0; i<operaciones; i++){
        scanf("\n%s", operacion);
        if (strcmp("LLEGA", operacion) == 0){

            scanf(" %s %s", tipo_fila, nombre);
            if(strcmp("ALUMNO", tipo_fila)==0){
                insertar(estudiantes, nombre);
            } else {
                insertar(profesores, nombre);
            }
        } else {
            if(esta_vacia_c(profesores)){
                printf("%s\n", obtener_primero(estudiantes).cadena);
                eliminar(estudiantes);
            } else {
                printf("%s\n", obtener_primero(profesores).cadena);
                eliminar(profesores);
            }
        }
    }
}

bool esta_vacia_c(const struct cola *c){
    return (c->frente==c->atras);
}

bool esta_llena_c(const struct cola *c){
    return ((c->atras+1)%MAX == c->frente);
}

void insertar(struct cola *c, char dato[MAX_STRING]){
    if(!esta_llena_c(c)){
        strcpy(c->arreglo[c->atras], dato);
        c->atras=(c->atras+1)%MAX;
    }
}
void eliminar(struct cola *c){
    if(!esta_vacia_c(c)){
        c->frente=(c->frente+1)%MAX;
    }
}

struct cadena obtener_primero(const struct cola *c){
    struct cadena aux;
    if(!esta_vacia_c(c)) {
        strcpy(aux.cadena, c->arreglo[c->frente]);
    } else {
        strcpy(aux.cadena, "-1");
    }
    return aux;
}

void inicializar_cola(struct cola *c){
    c->frente=0;
    c->atras=0;
}

int size_cola(const struct cola *c){
    if(c->atras < c->frente ){
        return (c->atras - c->frente) + MAX;
    } else if(c->atras >= c->frente){
        return (c->atras - c->frente);
    }
}
