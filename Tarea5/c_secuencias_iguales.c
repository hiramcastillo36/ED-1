/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 20 de Septiembre del 2022
 * Descripción: Dada una secuencia de N enteros y un entero B, calcula cuántas veces aparece B en la secuencia
 */

#include <stdio.h>
#include <stdbool.h>

void read_array(int [], int);
void compare_arrays(int [], int [], int, bool *);

int main() {
    int size_array, search_number, counter=0;
    bool result=1;
    scanf("%d", &size_array);
    int array_a[size_array], array_b[size_array];
    read_array(array_a, size_array);
    read_array(array_b, size_array);
    compare_arrays(array_a, array_b, size_array, &result);
    printf("%d", result);
    return 0;
}

void read_array(int array[], int size_array){
    for(int iterate=0; iterate<size_array; iterate++){
        scanf("%d", &array[iterate]);
    }
}

void compare_arrays(int array_a[], int array_b[], int size_array, bool *result) {
    for(int iterate=0; iterate<size_array; iterate++){
        if(array_a[iterate] != array_b[iterate]) {
            *result=0;
            break;
        }
    }
}


