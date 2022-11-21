/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Jueves, 01 de Septiembre del 2022
 * Descripción: Dado un número N, calcular su tabla de multiplicar.
 */

#include <stdio.h>

int main(void) {
    short int total_tablas, factor;
    scanf("%hd", &total_tablas);
    for(int contador=1; contador<=total_tablas; contador++){
        scanf("%hd", &factor);
        for(int factor_a=1; factor_a <= 10; factor_a++){
            printf("%hdx%hd=%lld\n",factor, factor_a, factor_a * factor);
        }
        printf("\n");
    }
    return 0;
}
