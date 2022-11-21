/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Jueves, 01 de Septiembre del 2022
 * Descripción: Dado un número entero positivo N y un número entero K,
 * contar cuantas veces se repite el número K dentro de una secuencia de N números enteros.
 */

#include <stdio.h>

int main(void) {
    short int cantidad_numeros_n, repeticiones=0;
    int busqueda_k, numero_n;

    scanf("%hi", &cantidad_numeros_n);
    scanf("%d", &busqueda_k);
    for(int contador=0; contador<cantidad_numeros_n; contador++){
        scanf("%d", &numero_n);
        if (numero_n == busqueda_k){
            repeticiones++;
        }
    }
    printf("%hi", repeticiones);
    return 0;
}
