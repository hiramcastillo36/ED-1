#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 20

typedef bool TDato;

struct grafo {
    TDato matriz[MAX][MAX];

};

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


