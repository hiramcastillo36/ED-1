#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX 100000

typedef bool TDato;

struct grafo {
    TDato vertices[MAX][MAX];
};

void inicializar_grafo(struct grafo *);
void agregar_relacion(struct grafo *, int, int);
int buscar_relaciones(const struct grafo *, int);

int main(){
    int nodos, aux_nodo_b, aux_nodo_a, buscar;
    scanf("%d", &nodos);
    struct grafo gf;
    inicializar_grafo(&gf);
    for(int i=0; i<nodos; i++){
        scanf("%d %d",&aux_nodo_a, &aux_nodo_b);
        agregar_relacion(&gf, aux_nodo_a, aux_nodo_b);
    }
    scanf("%d", &buscar);
    buscar_relaciones(&gf, buscar);
}

void inicializar_grafo(struct grafo *gf){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++) {
            gf->vertices[i][j] = 0;
        }
    }
}

void agregar_relacion(struct grafo *gf, int vertice_a, int vertice_b){
    gf->vertices[vertice_a][vertice_b] = 1;
}

int buscar_relaciones(const struct grafo *gf, int buscar){
    for(int i=0; i<MAX; i++){
        if(gf->vertices[i][buscar] == 1) {
            printf("%d ", i);
        }
        if(gf->vertices[buscar][i] == 1){
            printf("%d ", i);
        }
    }
}