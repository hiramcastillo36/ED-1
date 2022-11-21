/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Jueves, 01 de Septiembre del 2022
 * Descripción: Dado un número N, encontrar su menor divisor (aquel número más pequeño que lo divide)
 * que sea mayor que 1. El problema consta de varios casos de prueba, determine el menor divisor en cada caso.
 */

#include <stdio.h>
#include <limits.h>

int main(void) {
    short int numeros;
    int numero_actual;
    scanf("%hd", &numeros);
    for(int contador=0; contador<numeros; contador++){
        scanf("%d", &numero_actual);
        for(int divisor=2; divisor<=numero_actual; divisor++){
            if(numero_actual%divisor==0){
                printf("%d\n", divisor);
                break;
            }
        }
    }
    return 0;
}
