/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 20 de Septiembre del 2022
 * Descripción: Dados dos arreglos de N componentes cada uno, calcular en dos nuevos arreglos: minimo y maximo
 *              en cada arreglo agregar la comparacion de cual es el valor minimo o maximos de los dos arreglos dados.
 */

#include <stdio.h>
#include <limits.h>

void read_array(int [], int);
void print_array(int [], int);
void compare_score_and_add_min_max_array(int, int, int, int, int [], int[]);
void scores(int [], int [], int [], int [], int);

int main() {
    int size_array;
    scanf("%d", &size_array);
    int array_a[size_array], array_b[size_array], max_score[size_array], min_score[size_array];
    read_array(array_a, size_array);
    read_array(array_b, size_array);
    scores(array_a, array_b, max_score, min_score, size_array);
    print_array(min_score, size_array);
    printf("\n");
    print_array(max_score, size_array);
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

void compare_score_and_add_min_max_array(int value_array_a, int value_array_b, int size_array, int index, int max_score[], int min_score[]) {
    if (value_array_a > value_array_b) {
        max_score[index] = value_array_a;
        min_score[index] = value_array_b;
    } else {
        max_score[index] = value_array_b;
        min_score[index] = value_array_a;
    }
}

void scores(int array_a[], int array_b[], int max_score[], int min_score[], int size_array) {
    for(int iterate=0; iterate<size_array; iterate++) {
        compare_score_and_add_min_max_array(array_a[iterate], array_b[iterate], size_array, iterate, max_score, min_score);
    }
}

