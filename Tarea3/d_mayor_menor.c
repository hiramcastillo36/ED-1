/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Jueves, 01 de Septiembre del 2022
 * Descripción: Dado un número entero positivo N,
 * determinar cual es el número mayor y cual es el número menor de una secuencia de N números
 */

#include <stdio.h>
#include <limits.h>

int main(void) {
    short int numeros;
    int numero_minimo=INT_MAX;
    int numero_maximo=INT_MIN;
    int numero_actual;
    scanf("%hd", &numeros);
    for(int contador=0; contador<numeros; contador++){
        scanf("%d", &numero_actual);
        if( numero_actual > numero_maximo ){
            numero_maximo = numero_actual;
        }
        if (numero_actual < numero_minimo) {
            numero_minimo = numero_actual;
        }
    }
    printf("%d %d", numero_maximo, numero_minimo);
    return 0;
}
