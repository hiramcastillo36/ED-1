/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Jueves, 01 de Septiembre del 2022
 * Descripción: Dados tres números enteros positivos,
 * imprimir el mayor de ellos tal que sea menor a 100, o
 * imprimir 0 en caso de que tal número no exista.
 */

#include <stdio.h>

int main(void) {
    unsigned int numero_a=0;
    unsigned int numero_b=0;
    unsigned int numero_c=0;
    unsigned int numero_mayor=0;
    scanf("%i%i%i", &numero_a, &numero_b, &numero_c);
    numero_mayor = numero_a;
    if(numero_a >= 100) {
        numero_a = 0;
        numero_mayor = numero_b;
    }
    if(numero_b >= 100) {
        numero_b = 0;
        numero_mayor = numero_a;
    }
    if(numero_c >= 100){
        numero_c = 0;
        numero_mayor = numero_a;
    }

    if (numero_b > numero_mayor) {
        numero_mayor = numero_b;
    } else {
        if (numero_c > numero_mayor) {
            numero_mayor = numero_c;
        }
    }

    printf("%i", numero_mayor);
    return 0;
}
