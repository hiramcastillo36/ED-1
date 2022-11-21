/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 20 de Septiembre del 2022
 * Descripción: Dado un arreglo de N enteros que comienzan valiendo 0,
 * escribe un programa que lea M índices y para cada índice incremente la variable correspondiente del arreglo.
 */

#include <stdio.h>
#define MAX_ARRAY 105

void read_indexes(int, int []);
void increment_index(int [], int);
void print_indexes_array(int [], int);

int main() {
    int size_array, max_indexes;
    scanf("%d%d", &size_array, &max_indexes);
    int array_of_indexes[100] = {};
    read_indexes(max_indexes, array_of_indexes);
    increment_index(array_of_indexes, size_array);
    print_indexes_array(array_of_indexes, size_array);
    return 0;
}

void read_indexes(int max_indexes, int array_of_indexes[]){
    int index;
    for(int iterate=0; iterate<max_indexes; iterate++){
        scanf("%d", &index);
        increment_index(array_of_indexes, index);
    }
}

void increment_index(int array_of_indexes[], int index) {
    array_of_indexes[index] += 1;
}

void print_indexes_array(int array_of_indexes[], int size_array){
    for(int iterate=0; iterate<size_array; iterate++){
        printf("%d ", array_of_indexes[iterate]);
    }
}


