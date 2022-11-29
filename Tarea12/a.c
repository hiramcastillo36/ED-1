#include <stdio.h>
#include <stdbool.h>
#define MAX 100000

typedef long long int TDato;
struct conjunto{
    TDato arreglo[MAX];
    int tam;
};
typedef struct conjunto TConjunto;

int buscar(TDato [], int, TDato);
bool agregar(TConjunto *, TDato);
bool eliminar(TConjunto *, TDato);
bool esta_lleno(const TConjunto *);
bool esta_vacio(const TConjunto *);
void inicializar_conjunto(TConjunto *);
void solve(TConjunto *, int);

int main(void) {
    int numero_conjunto, operaciones;
    scanf("%d %d", &numero_conjunto, &operaciones);
    TConjunto conjunto;
    inicializar_conjunto(&conjunto);
    solve(&conjunto, operaciones);
    return 0;
}

void solve(TConjunto *conjunto, int operaciones) {
    char aux;
    TDato dato;
    for(int i=0; i<operaciones; i++){
        scanf("\n%c", &aux);
        if(aux == 'I'){
            scanf(" %lld", &dato);
            agregar(conjunto, dato);
        } else if(aux == 'C') {
            printf("%d\n", conjunto->tam);
        } else {
            scanf("%lld", &dato);
            eliminar(conjunto, dato);
        }
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
    if(ind != -1 || esta_lleno(conjunto) ) {
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