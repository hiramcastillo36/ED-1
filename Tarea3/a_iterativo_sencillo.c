/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Jueves, 01 de Septiembre del 2022
 * Descripción: Dado un entero inicial N, repetirás el siguiente proceso
 * mientras N sea menor que 100:
 * si N es par le sumarás 3 y en caso contrario lo multiplicarás por 2.
 */

#include <stdio.h>

int main(void) {
    long long int numero_n;
    scanf("%lld", &numero_n);
    while(numero_n < 100){
        if(numero_n%2) {
            numero_n*=2;
        }else {
            numero_n+=3;
        }
    }
    printf("%lld", numero_n);
    return 0;
}
