/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 31 de octubre del 2022
 * Descripción: Dado un conjunto de 1<=N<=1000 coordenadas x, y en un plano cartesiano, imprime los puntos ordenados
 *              de forma creciente con respecto a X.
*/

#include <stdio.h>

struct coordinate {
    int x;
    int y;
};

void read_struct(int, struct coordinate []);
void print_struct(int, struct coordinate []);
void quicksort(int, int, struct coordinate []);
int mid(int, int, struct coordinate []);

int main(void){
    int max_size;
    scanf("%d", &max_size);
    struct coordinate coordinates [max_size];
    read_struct(max_size, coordinates);
    quicksort(0, max_size-1, coordinates);
    print_struct(max_size, coordinates);
}

void read_struct(int size, struct coordinate coordinates_a[]){
    for(int i=0; i<size; i++) {
        scanf("%d %d", &(coordinates_a[i]).x, &coordinates_a[i].y);
    }
}

void print_struct(int size, struct coordinate coordinates_a[]){
    for(int i=0; i<size; i++) {
        printf("%d %d\n", coordinates_a[i].x, (coordinates_a)[i].y);
    }
}

void swap(struct coordinate *coordinate_a, struct coordinate *coordinate_b) {
    struct coordinate coordinate_aux= *coordinate_a;
    *coordinate_a=*coordinate_b;
    *coordinate_b=coordinate_aux;
}

int mid(int init, int fin, struct coordinate coordinates[]) {
    int p = init;
    for(int i=init; i<fin; i++) {
        if(coordinates[i].x < coordinates[fin].x) {
            swap(&coordinates[i], &coordinates[p]);
            p++;
        }
    }
    swap(&coordinates[p], &coordinates[fin]);
    return p;
}

void quicksort(int init, int fin, struct coordinate coordinates[]){
    if(init< fin) {
        int p = mid(init, fin, coordinates);
        quicksort(init, p-1, coordinates);
        quicksort(p+1, fin, coordinates);
    }
}