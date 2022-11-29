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
void solve(TConjunto *, TConjunto *);
void leer_conjunto(TConjunto *, int);
int es_subconjunto(const TConjunto *, const TConjunto *);

int main(void) {
    int size_conjunto_a, size_conjunto_b;
    scanf("%d %d", &size_conjunto_a, &size_conjunto_b);
    TConjunto conjunto_a, conjunto_b;
    inicializar_conjunto(&conjunto_a);
    inicializar_conjunto(&conjunto_b);
    leer_conjunto(&conjunto_a, size_conjunto_a);
    leer_conjunto(&conjunto_b, size_conjunto_b);
    solve(&conjunto_a, &conjunto_b);
    return 0;
}

void leer_conjunto(TConjunto *conjunto, int operaciones){
    TDato aux;
    for(int i=0; i<operaciones; i++){
        scanf("%lld", &aux);
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

// se buscara el conjunto_b en conjunto_a

int es_subconjunto(const TConjunto *conjunto_a, const TConjunto *conjunto_b) { // -1 no es encontro 0 subjunto pero  iguales 1 subjunto pero no iguales
    int contador=0, resultado;
    for(int i=0; i<conjunto_b->tam; i++){
        resultado = buscar(conjunto_a->arreglo, conjunto_a->tam,conjunto_b->arreglo[i]);
        if(resultado != -1) {
            contador ++;
        }
    }
    if(contador < conjunto_b->tam) {
        return -1;
    } else if(contador == conjunto_b->tam && conjunto_a->tam == conjunto_b->tam) {
        return 0;
    } else {
        return 1;
    }
}

void solve(TConjunto *conjunto_a, TConjunto *conjunto_b) {
    int resultado;
    if(conjunto_a->tam > conjunto_b->tam) { // buscar el conjunto menor en el mayor
        resultado = es_subconjunto(conjunto_a, conjunto_b);
        if(resultado == 0) {
            puts("A = B");
        } else if(resultado == 1){
            puts("A > B");
        } else {
            puts("A != B");
        }
    } else {
        resultado = es_subconjunto(conjunto_b, conjunto_a);
        if(resultado == 0) {
            puts("A = B");
        } else if(resultado == 1){
            puts("A < B");
        } else {
            puts("A != B");
        }
    }
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