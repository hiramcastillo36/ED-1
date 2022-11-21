/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Jueves, 01 de Septiembre del 2022
 * Descripción: Verificar si un número N es igual a la suma de las
 * potencias de sus cifras elevadas a la cantidad de cifras del número, sí se cumple
 * deberas imprimir "Es Narcisista" y si no, imprimir "No es Narcisista"
 */

#include <stdio.h>
#include <math.h>

int main(void) {
    int numero, solucion;
    int cifras=1;
    int aux;
    int resultado = 0;
    scanf("%d", &numero);
    aux=numero;
    solucion = numero;
    while(numero/10 && ++cifras){
        numero/=10;
    }
    do{
        resultado = resultado + pow(aux%10, cifras);
    }while(aux/10 && (aux/=10));

    if(resultado == solucion) {
        printf("Es Narcisista");
    } else {
        printf("No es Narcisista");
    }
    return 0;
}