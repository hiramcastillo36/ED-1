/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Domingo, 18 de Septiembre del 2022
 * Descripción: Dados los valores de , escribe un programa que evalúe la siguiente fórmula.
 *  7 + (2x+y-z)^2x+y-z / 2x+y-z
 */

#include <stdio.h>
#include <math.h>

float solucion_formula(float, float, float);

int main() {
    float valor_x, valor_y, valor_z;
    scanf("%f%f%f", &valor_x, &valor_y, &valor_z);
    printf("%f", solucion_formula(valor_x, valor_y, valor_z));
    return 0;
}

float solucion_formula(float valor_x, float valor_y, float valor_z){
    float numerador, denominador, operacion_comun;
    operacion_comun= 2.0*valor_x+valor_y-valor_z;
    numerador = 7.0 + pow(operacion_comun, operacion_comun);
    denominador = operacion_comun;
    return  numerador/denominador;
}