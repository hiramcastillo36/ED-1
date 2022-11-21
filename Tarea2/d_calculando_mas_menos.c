/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Jueves, 01 de Septiembre del 2022
 * Descripción: Escribe un programa que calcule los valores distintos que puede tomar la expresión
 * o si el resultado está indefinido.
 */

#include <stdio.h>

int main(void) {
    double numero_a=0;
    double numero_b=0;
    double numero_c=0;
    double solucion_positiva=0;
    double solucion_negativa=0;
    scanf("%lf%lf%lf", &numero_a, &numero_b, &numero_c);
    if (numero_b != 0 ) {
        solucion_positiva = ((double)numero_a/numero_b) + numero_c;
        solucion_negativa = ((double)numero_a/numero_b) - numero_c;
    }
    if (numero_b == 0 ){
        printf("indefinido");
    } else {
        if (solucion_positiva == solucion_negativa) {
            printf("%lf", solucion_positiva);
        } else {
            printf("%lf %lf", solucion_positiva, solucion_negativa);
        }
    }

    return 0;
}
