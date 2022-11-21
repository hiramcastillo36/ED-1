/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 20 de Septiembre del 2022
 * Descripción: Determine si una matriz es simetrica.
 */

#include <stdio.h>
#include <stdbool.h>

void read_matrix(int size_matrix, int [][size_matrix]);
void check_matrix(int size_matrix, int [][size_matrix]);

int main() {
    int max_inputs, size_matrix;
    scanf("%d", &max_inputs);
    for(int iterate=0; iterate<max_inputs; iterate++) {
        scanf("%d", &size_matrix);
        int matrix [size_matrix][size_matrix];
        read_matrix(size_matrix, matrix);
        check_matrix(size_matrix, matrix);
        printf("\n");
    }
    return 0;
}

void read_matrix(int size_matrix, int matrix[][size_matrix]){
    for(int i=0; i<size_matrix; i++) {
        for(int j=0; j<size_matrix; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void check_matrix(int size_matrix, int matrix[][size_matrix]){
    bool state=1;
    for(int i=0; i<size_matrix; i++){
        for(int j=i; j<size_matrix; j++) {
            if(matrix[i][j] != matrix [j][i]) {
                state=0;
            }
        }
    }
    if(state==1) {
        printf("Simétrica");
    } else {
        printf("No Simétrica");
    }
}
