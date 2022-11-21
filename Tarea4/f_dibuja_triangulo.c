/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Domingo, 18 de Septiembre del 2022
 * Descripción: escribe un programa que dibuje un triángulo de arrobas. La punta del triángulo
 *              (a incluirse en la primera fila del dibujo) debe estar formada por una arroba
 *              y cada fila posterior debe contener dos arrobas adicionales (una a la izquierda y otra a la derecha).
 *              La base del triángulo (a incluirse en la última fila del dibujo) debe estar formada por  arrobas.
 *              El triángulo debe aparecer centrado.
 */

#include <stdio.h>

void dibujar(int);

int main() {
    int tipo_figura;
    scanf("%d", &tipo_figura);
    dibujar(tipo_figura);
    return 0;
}

void dibujar(int size){
    for(int row=0; row<size/2+1; row++){
        for(int col=row; col<=size/2-1; col++){
            printf(" ");
        }
        for(int col=size/2-row; col<=size/2+row; col++){
            printf("@");
        }
        printf("\n");
    }
}