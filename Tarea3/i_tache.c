/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Jueves, 01 de Septiembre del 2022
 * Descripción: Dado un entero N, escribe un programa que
 * dibuje un tache de arrobas de dimensiones NxN.
 */

#include <stdio.h>

int main(void) {
    short int dimensiones;
    scanf("%hd", &dimensiones);
    for(int col=0; col<dimensiones; col++){
        if(col < (dimensiones/2+1)) {
            for (int espacios = 0; espacios < col; espacios++) {
                printf(" ");
            }
            for (int row = col; row <= dimensiones - col - 1; row++) {
                if (row == col || row == dimensiones - col - 1) {
                    printf("@");
                } else {
                    printf(" ");
                }
            }
        }
        else {
            for(int espacios=0; espacios<dimensiones-col-1; espacios++){
                printf(" ");
            }
            for(int row=dimensiones-col-1; row<col+1; row++){
                if (row == col || row == dimensiones - col - 1) {
                    printf("@");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
