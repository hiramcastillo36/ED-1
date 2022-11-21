/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 25 de octubre del 2022
 * Descripción: Dado un conjunto de 1<=N<=1000 coordenadas x, y en un plano cartesiano,
 *              imprime los puntos ordenados de forma creciente con respecto a X.
 */

#include <stdio.h>

void sort(int size, int [size], int [size]);
void swap(int *, int *);
void print_array(int size, int [size], int [size]);
void read_array(int size, int [size], int [size]);

int main() {
    int max_size;
    scanf("%d", &max_size);
    int array_x[max_size], array_y[max_size];
    read_array(max_size, array_x, array_y);
    sort(max_size, array_x, array_y);
    print_array(max_size, array_x, array_y);
    return 0;
}
void print_array(int max_size, int array_a[max_size], int array_b[max_size]){
    for(int i=0; i<max_size; i++) {
        printf("%d %d\n", array_a[i], array_b[i]);
    }
}
void read_array(int max_size, int array_a[max_size], int array_b[max_size]){
    for(int i=0; i<max_size; i++) {
        scanf("%d%d", &array_a[i], &array_b[i]);
    }
}

void swap(int *numero_a, int *numero_b) {
    int aux = *numero_a;
    *numero_a=*numero_b;
    *numero_b=aux;
}

void sort(int size, int array_x[size], int array_y[size]){
    int menor;
    for(int i=0; i<size-1; i++){
        menor = i;
        for(int j=i+1; j<size; j++) {
            if(array_x[j]<array_x[menor]){
                menor = j;
            }
        }
        swap(&array_x[menor], &array_x[i]);
        swap(&array_y[menor], &array_y[i]);
    }
}





