/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 20 de Septiembre del 2022
 * Descripción: Un cuadrado semimágico es una matriz de NxN números que tiene la propiedad de que la suma de los
 * elementos de cada fila, cada columna y ambas diagonales vale lo mismo. Crees ser capaz de escribir un programa
 * que te diga si una matriz cuadrada es o no un cuadrado semimágico
 * */

#include <stdio.h>
#include <stdbool.h>

void read_matrix_and_sum(int size_matrix, int [][size_matrix], int *);
void check_col(int size_matrix, int [][size_matrix], bool *, int, int);
void check_row(int size_matrix, int [][size_matrix], bool *, int, int);
void check_matrix(int size_matriz, int [][size_matriz], bool *, int);
void check_right_to_left(int size_matriz, int [][size_matriz], bool *, int);
void check_left_to_right(int size_matriz, int [][size_matriz], bool *, int);

int main() {
    int size_matrix, sum=0;
    bool answer=1;
    scanf("%d", &size_matrix);
    int matrix [size_matrix][size_matrix];
    read_matrix_and_sum(size_matrix, matrix, &sum);
    check_matrix(size_matrix, matrix, &answer, sum);
    printf("%d", answer);
    return 0;
}

void read_matrix_and_sum(int size_matrix, int matrix[][size_matrix], int *sum){
    for(int i=0; i<size_matrix; i++) {
        *sum=0;
        for(int j=0; j<size_matrix; j++) {
            scanf("%d", &matrix[i][j]);
            *sum = *sum + matrix[i][j];
        }
    }
}

void check_row(int size_matrix, int matrix[][size_matrix], bool *answer, int sum, int i){
    int sum_row=0;
    for(int j=0; j<size_matrix; j++) {
        sum_row=sum_row+matrix[i][j];
    }
    if(sum_row!= sum) {
        *answer=0;
    }
}

void check_col(int size_matrix, int matrix[][size_matrix], bool *answer, int sum, int j){
    int sum_row=0;
    for(int i=0; i<size_matrix; i++) {
        sum_row=sum_row+matrix[i][j];
    }
    if(sum_row!= sum) {
        *answer=0;
    }
}

void check_matrix(int size_matrix, int matrix[][size_matrix], bool *answer, int sum){
    for(int j=0; j<size_matrix; j++) {
        check_row(size_matrix, matrix, answer, sum, j);
        check_col(size_matrix, matrix, answer, sum, j);
    }
    check_left_to_right(size_matrix, matrix, answer, sum);
    check_right_to_left(size_matrix, matrix, answer, sum);
}

void check_left_to_right(int size_matrix, int matrix[][size_matrix], bool *answer, int sum){
    int sum_diag=0;
    for(int i=0; i<size_matrix; i++) {
        sum_diag = sum_diag + matrix[i][i];
    }
    if(sum_diag!= sum) {
        *answer=0;
    }
}

void check_right_to_left(int size_matrix, int matrix[][size_matrix], bool *answer, int sum){
    int sum_diag=0;
    int j=size_matrix-1;
    for(int i=0; i<size_matrix; i++) {
        sum_diag += matrix[i][j-i];
    }
    if(sum_diag!= sum) {
        *answer=0;
    }
}