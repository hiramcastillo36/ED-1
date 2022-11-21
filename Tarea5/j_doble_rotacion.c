/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 20 de Septiembre del 2022
 * Descripción: Considere la doble rotación de una matriz 2D como otra matriz 2D tal que todas los renglones aparecen
 *               en orden inverso comparados con la primer matriz, y además todos los elementos en cualquiera de
 *               los renglones también aparecen en orden inverso.
 *               Dada una matriz de  obtenga la matriz resultado de su doble rotación.
 * */

#include <stdio.h>
#include <stdbool.h>

void read_matrix(int matrix_n, int matrix_m, int [matrix_n][matrix_m]);
void create_rotation_matrix(int matrix_n, int matrix_m, int [matrix_n][matrix_m], int [matrix_n][matrix_m]);
void print_matrix(int matrix_n, int matrix_m, int [matrix_n][matrix_m]);

int main() {
    int matrix_n, matrix_m, sum=0;
    bool answer=1;
    scanf("%d%d", &matrix_n, &matrix_m);
    int matrix [matrix_n][matrix_m], matrix_rotate[matrix_n][matrix_m];
    read_matrix(matrix_n, matrix_m, matrix);
    create_rotation_matrix(matrix_m, matrix_n, matrix, matrix_rotate);
    print_matrix(matrix_n, matrix_m, matrix_rotate);
    return 0;
}

void read_matrix(int matrix_n, int matrix_m, int matrix[matrix_n][matrix_m]){
    for(int i=0; i<matrix_n; i++) {
        for(int j=0; j<matrix_m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void create_rotation_matrix(int matrix_n, int matrix_m, int matrix[matrix_n][matrix_m], int matrix_transpose[matrix_n][matrix_m]){
    for(int i=0; i<matrix_n; i++) {
        for(int j=0; j<matrix_m; j++) {
            matrix_transpose[matrix_n-1-i][matrix_m-1-j] = matrix [i][j];
        }
    }
}

void print_matrix(int matrix_n, int matrix_m, int matrix[matrix_n][matrix_m]) {
    for(int i=0; i<matrix_n; i++) {
        for(int j=0; j<matrix_m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}