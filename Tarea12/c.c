#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10001

typedef int TDato;
typedef struct conjunto TConjunto;
typedef struct cola TCola;

struct conjunto{
    TDato arreglo[MAX];
    int tam;
};

struct cola {
    TDato arreglo[MAX];
    int frente;
    int atras;
};

bool esta_llena_cola(const TCola *);
bool esta_vacia_cola(const TCola *);
void insertar_cola(TCola *, TDato);
void eliminar_cola(TCola *);
void inicializar_cola(TCola *);
TDato obtener_primero(const TCola *);

int buscar(TDato [], int, TDato);
bool agregar(TConjunto *, TDato);
bool eliminar(TConjunto *, TDato);
bool esta_lleno(const TConjunto *);
bool esta_vacio(const TConjunto *);
void inicializar_conjunto(TConjunto *);
void leer_conjunto(TConjunto *, int);
int es_subconjunto(const TConjunto *, const TConjunto *);

void solve(TConjunto *, TCola *, int);

int main(void) {
    int operaciones;
    scanf("%d", &operaciones);
    TConjunto conjunto_a;
    TCola cola;
    inicializar_conjunto(&conjunto_a);
    inicializar_cola(&cola);
    solve(&conjunto_a, &cola, operaciones);
    return 0;
}

void solve(TConjunto *conjunto, TCola *cola, int operaciones) {
    char aux[15];
    int num;
    for(int i=0; i<operaciones; i++){
        scanf("\n%s", aux);
        if(strcmp("FORMA", aux)==0) {
            scanf(" %d", &num);
            insertar_cola(cola, num);
        } else {
            TDato primero_cola=obtener_primero(cola);
            if(agregar(conjunto, primero_cola)){
                printf("SI TAMAL %d\n", primero_cola);
            } else {
                printf("NO TAMAL %d\n", primero_cola);
            }
            eliminar_cola(cola);
        }
    }

}

void leer_conjunto(TConjunto *conjunto, int operaciones){
    TDato aux;
    for(int i=0; i<operaciones; i++){
        scanf("%d", &aux);
        agregar(conjunto, aux);
    }
}

int buscar(TDato datos_conjunto[], int size, TDato dato){
    for(int i=0; i<size; i++){
        if(datos_conjunto[i]==dato){
            return i;
        }
    }
    return -1;
}

bool agregar(TConjunto *conjunto, TDato dato){
    int ind = buscar(conjunto->arreglo, conjunto->tam, dato);
    if(ind != -1 || esta_lleno(conjunto)) {
        return false;
    }
    conjunto->arreglo[conjunto->tam++] = dato;
    return true;
}

bool eliminar(TConjunto *conjunto, TDato dato){
    int ind = buscar(conjunto->arreglo, conjunto->tam, dato);
    if(ind == -1 || esta_vacio(conjunto)) {
        return false;
    }
    conjunto->arreglo[ind] = conjunto->arreglo[conjunto->tam-1];
    conjunto->tam -= 1;
    return true;
}

bool esta_lleno(const TConjunto *conjunto){
    return conjunto->tam == MAX;
}

bool esta_vacio(const TConjunto *conjunto){
    return (conjunto->tam == 0);
}

void inicializar_conjunto(TConjunto *conjunto){
    conjunto->tam=0;
}

//cola

bool esta_llena_cola(const TCola *c){
    return  (c->atras+1)%MAX == c->frente;
}
bool esta_vacia_cola(const TCola *c){
    return (c->frente==c->atras);
}

void insertar_cola(TCola *c, int dato){
    if(!esta_llena_cola(c)){
        c->arreglo[c->atras]=dato;
        c->atras=((c->atras+1)%MAX);
    }
}

void eliminar_cola(TCola *c){
    if(!esta_vacia_cola(c)){
        c->frente=(c->frente+1)%MAX;
    }
}
void inicializar_cola(TCola *c){
    c->atras=0;
    c->frente=0;
}

TDato obtener_primero(const TCola *c){
    if(!esta_vacia_cola(c)){
        return c->arreglo[c->frente];
    }
}
