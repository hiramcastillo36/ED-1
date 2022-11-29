/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 22 de noviembre del 2022
 * Descripción: Para hacer la tarea más fácil, has decidido crear un programa que te ayude en esta tarea.
 * En la primera línea recibirás un entero , el número de operaciones a realizar. En las siguientes
 * líneas recibirás un entero representando la operación a realizar:
 * Si el entero es un 1, significa que un nuevo cliente se forma en la fila, por lo que deberás leer un entero t representando el número de tacos que desea ordenar.
 * Si el entero es un 2, significa que el cliente que se encuentra al frente de la fila será atendido.
 * Si el entero es un 3, significa que quieres saber el número de clientes que se encuentran formados actualmente en la fila.
 * Si el entero es un 4, significa que quieres saber el número de tacos que has vendido hasta ahora.
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 10000
typedef int TDato;

struct cola {
    TDato arreglo[MAX];
    int frente;
    int atras;
};

bool esta_llena(const struct cola*);
bool esta_vacia(const struct cola*);
void insertar(struct cola *, int);
void eliminar(struct cola *);
void inicializar_cola(struct cola *);
TDato obtener_primero(const struct cola *);
void solve( struct cola *, int, int *);

int main(void){
    int operaciones, tacos_vendidos=0;
    scanf("%d", &operaciones);
    struct cola fila;
    inicializar_cola(&fila);
    solve(&fila, operaciones, &tacos_vendidos);
    return 0;
}

bool esta_llena(const struct cola *c){
    return  (c->atras+1)%MAX == c->frente;
}
bool esta_vacia(const struct cola *c){
    return (c->frente==c->atras);
}
void insertar(struct cola *c, int dato){
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

TDato size_cola(const struct cola *c){
    if(c->atras < c->frente ){
        return (c->atras - c->frente) + MAX;
    } else if(c->atras >= c->frente){
        return (c->atras - c->frente);
    }
}

void solve(struct cola *c, int operaciones, int *venta_total){
    TDato operacion, tacos;
    for(int i=0; i<operaciones; i++){
        scanf("%d", &operacion);
        switch (operacion) {
            case 1:
                scanf(" %d", &tacos);
                insertar(c, tacos);
                break;
            case 2:if(!esta_vacia(c)) {
                    *venta_total = *venta_total + obtener_primero(c);
                    eliminar(c);
                }
                break;
            case 3:
                printf("%d\n", size_cola(c));
                break;
            case 4:
                printf("%d\n", *venta_total);
                break;
        }
    }
}