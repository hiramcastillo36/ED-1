/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Jueves, 01 de Septiembre del 2022
 * Descripción: Escribe un programa que decida si es posible elegir tres de
 * ellos para formar un triángulo equilátero.
 */

#include <stdio.h>

int main(void) {
    short int lado_a=0;
    short int lado_b=0;
    short int lado_c=0;
    short int lado_d=0;
    short int solucion=0;
    scanf("%hi%hi%hi%hi", &lado_a, &lado_b, &lado_c, &lado_d);
    if(lado_a == lado_b || lado_a == lado_c || lado_a == lado_d) {
        if (lado_a == lado_b && lado_a == lado_c) {
            solucion = 1;
        } else {
            if (lado_a == lado_b && lado_a == lado_d) {
                solucion = 1;
            } else {
                if (lado_a == lado_c && lado_a == lado_d) {
                    solucion = 1;
                }
            }
        }
    } else {
        if (lado_b == lado_c && lado_b == lado_d) {
            solucion = 1;
        }
    }

    printf("%hi", solucion);
    return 0;
}
