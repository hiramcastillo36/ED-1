/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Domingo, 28 de Agosto del 2022
 * Descripción: Escribir un programa para convertir grados Celsius a Fahrenheit.
 */

#include <stdio.h>

int main() {
    float celsius=0;
    float fahrenheit=0;
    scanf("%f", &celsius);
    fahrenheit = (celsius * 1.8) + 32;
    printf("%.8f", fahrenheit);
    return 0;
}