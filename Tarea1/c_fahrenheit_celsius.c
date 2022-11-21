/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Domingo, 28 de Agosto del 2022
 * Descripción: Escribir un programa para convertir grados Fahrenheit a Celsius.
 */

#include <stdio.h>

int main() {
    float celsius=0;
    float fahrenheit=0;
    double constante = (double)5/9;

    scanf("%f", &fahrenheit);
    celsius = ((fahrenheit - 32.0) * constante);
    printf("%.8f", celsius);

    return 0;
}