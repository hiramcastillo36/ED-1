/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Domingo, 18 de Septiembre del 2022
 * Descripción: Escribir un programa para convertir grados Celsius a Fahrenheit, Kelvin y Reaumur.
 */

#include <stdio.h>

int conversion_kelvin(int);
int conversion_fahrenheit(int);
int conversion_reaumur(int);

int main() {
    int cantidad;
    scanf("%d", &cantidad);
    printf("%d", conversion_kelvin(cantidad));
    printf(" %d", conversion_fahrenheit(cantidad));
    printf(" %d", conversion_reaumur(cantidad));
    return 0;
}

int conversion_kelvin(int cantidad){
    return  cantidad + 273;
}

int conversion_fahrenheit(int cantidad){
    return (cantidad * ((float)9/5) + 32);
}

int conversion_reaumur(int cantidad){
    return cantidad * ((float)4/5);
}