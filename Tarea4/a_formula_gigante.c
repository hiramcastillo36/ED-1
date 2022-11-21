/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Domingo, 18 de Septiembre del 2022
 * Descripción: Escribe un programa que calcule el valor de la fórmula dados x, y, z.
 */

#include <stdio.h>
#include <math.h>

float resultado_formula(float, float, float);

int main() {
    float valor_x, valor_y, valor_z;
    scanf("%f%f%f", &valor_x, &valor_y, &valor_z);
    printf("%f", resultado_formula(valor_x, valor_y, valor_z));
    return 0;
}

float resultado_formula(float valor_x, float valor_y, float valor_z){
    float numerador;
    float denominador;
    numerador = (((2.0*valor_x+valor_y) / valor_z)*(pow(valor_y, 3.0)-valor_z));
    denominador = ((valor_x+2.0*valor_y+3.0*valor_z) / (valor_z-2.0*valor_y-3.0*valor_x));
    denominador = denominador + pow(valor_x, 2.0) + pow(valor_z, 2.0);
    return numerador/denominador;
}