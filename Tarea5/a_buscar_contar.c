/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 20 de Septiembre del 2022
 * Descripción: Dada una secuencia de N enteros y un entero B, calcula cuántas veces aparece B en la secuencia
 */

#include <stdio.h>

void read_array(int [], int);
void search_in_array(int [], int, int, int *);

int main() {
    int size_array, search_number, counter=0;
    scanf("%d", &size_array);
    int numbers[size_array];
    read_array(numbers, size_array);
    scanf("%d", &search_number);
    search_in_array(numbers, search_number, size_array, &counter);
    printf("%d", counter);
    return 0;
}

void read_array(int numbers[], int size_array){
    for(int iterate=0; iterate<size_array; iterate++){
        scanf("%d", &numbers[iterate]);
    }
}

void search_in_array(int numbers[], int search_number, int size_array, int *counter) {
    for(int iterate=0; iterate<size_array; iterate++){
        if(numbers[iterate] == search_number) {
            *counter = *counter + 1;
        }
    }
}


