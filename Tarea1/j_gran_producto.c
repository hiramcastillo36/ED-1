/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Domingo, 28 de Agosto del 2022
 * Descripción: Escribir un programa para multiplicar dos números enteros.
 */

#include <stdio.h>

int main() {
    int entero_a=0;
    int entero_b=0;
    long long int producto=0;
    scanf("%d", &entero_a);
    scanf("%d", &entero_b);
    producto = (long long int)entero_a * entero_b;
    printf("%lli", producto);
    return 0;
}