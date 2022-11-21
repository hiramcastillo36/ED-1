/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 20 de Septiembre del 2022
 * Descripción: Dada una matriz cuadrada de NxN , se puede definir la operación de giro a la derecha de  como sigue:
 * el primer renglón de la matriz  se convierte en la última columna de la matriz girada, el segundo renglón de la
 * matriz  se convierte en la penúltima columna de la matriz girada, y así sucesivamente hasta que el
 * último renglón de la matriz  se convierte en la primera columna de la matriz girada.
 * */

#include <stdio.h>
#include <stdbool.h>

void read_matrix(int size_matrix, int [][size_matrix]);
void create_matrix_transpose(int size_matriz, int [][size_matriz], int [][size_matriz]);
void print_matrix(int size_matrix, int [][size_matrix]);

int main() {
    int size_matrix, sum=0;
    bool answer=1;
    scanf("%d", &size_matrix);
    int matrix [size_matrix][size_matrix], matrix_transpose[size_matrix][size_matrix];
    read_matrix(size_matrix, matrix);
    create_matrix_transpose(size_matrix, matrix, matrix_transpose);
    print_matrix(size_matrix, matrix_transpose);
    return 0;
}

void read_matrix(int size_matrix, int matrix[][size_matrix]){
    for(int i=0; i<size_matrix; i++) {
        for(int j=0; j<size_matrix; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void create_matrix_transpose(int size_matrix, int matrix[][size_matrix], int matrix_transpose[][size_matrix]){
    for(int i=size_matrix-1; i>=0; i--) {
        for(int j=0; j<size_matrix; j++) {
            matrix_transpose[j][i] = matrix [size_matrix-i-1][j];
        }
    }
}

void print_matrix(int size_matrix, int matrix[][size_matrix]) {
    for(int i=0; i<size_matrix; i++) {
        for(int j=0; j<size_matrix; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}