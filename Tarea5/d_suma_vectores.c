/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 20 de Septiembre del 2022
 * Descripción: Dados dos vectores de N componentes cada uno, calcula el vector resultante de su suma
 *          (la suma de vectores se realiza componente a componente).
 */

#include <stdio.h>

void read_array(int [], int);
void sum_arrays(int [], int [], int [], int);
void print_array(int [], int);

int main() {
    int size_array;
    scanf("%d", &size_array);
    int array_a[size_array], array_b[size_array], sum_array[105]={};
    read_array(array_a, size_array);
    read_array(array_b, size_array);
    sum_arrays(array_a, array_b, sum_array, size_array);
    print_array(sum_array, size_array);
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

void sum_arrays(int array_a[], int array_b[], int sum_array[], int size_array) {
    for(int iterate=0; iterate<size_array; iterate++){
        sum_array[iterate] = array_a[iterate] + array_b[iterate];
    }
}


