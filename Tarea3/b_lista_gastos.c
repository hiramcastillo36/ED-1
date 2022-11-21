/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Jueves, 01 de Septiembre del 2022
 * Descripción: Dada una lista de gastos, determinar el total gastado y
 * la cantidad de compras que se realizaron.
 */

#include <stdio.h>

int main(void) {
    unsigned long long int gastos;
    unsigned long long int contador=0;
    unsigned long long int suma_gastos=0;
    do{
        scanf("%llu", &gastos);
        suma_gastos += gastos;
    }while(gastos != 0 && ++contador);
    printf("%llu %llu", suma_gastos, contador);
    return 0;
}
