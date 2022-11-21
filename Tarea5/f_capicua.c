/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 20 de Septiembre del 2022
 * Descripción: Determinar si un conjunto se trata de un conjunto capicúa. Un conjunto capicúa se lee igual de izquierda
 * a derecha que de derecha a izquierda, por ejemplo: 1 3 4 3 1, es un conjunto capicúa, mientras que 1 3 4 5 1 no lo es.
 */

#include <stdio.h>
#include <stdbool.h>

void read_array(int [], int);
void print_array(int [], int);
void check_array(int [], bool *, int);
void print_solve(bool);

int main() {
    int size_array;
    bool answer=1;
    scanf("%d", &size_array);
    int array_a[size_array];
    read_array(array_a, size_array);
    check_array(array_a, &answer, size_array);
    print_solve(answer);
    return 0;
}

void read_array(int array[], int size_array){
    for(int iterate=0; iterate<size_array; iterate++){
        scanf("%d", &array[iterate]);
    }
}

void print_array(int array[], int size_array){
    for(int iterate=0; iterate<size_array; iterate++){
        printf("%d ", array[iterate]);
    }
}

void check_array(int array_a[], bool *answer, int size_array) {
    for(int iterate=0; iterate<size_array; iterate++) {
        if(array_a[iterate] != array_a[size_array-1-iterate]) {
            *answer=0;
        }
    }
}

void print_solve(bool answer) {
    if(answer) {
        printf("SI");
    } else {
        printf("NO");
    }
}