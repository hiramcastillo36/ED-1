/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Domingo, 28 de Agosto del 2022
 * Descripción: Dado un número entero entre 1000 y 9999 intercambia los
 * dos dígitos de en medio en su representación decimal.
 */

#include <stdio.h>

int main() {
    unsigned short int entero_a=0;
    unsigned short int decenas=0;
    unsigned short int centenas=0;
    unsigned short int unidades=0;
    unsigned short int nuevo_entero=0;
    scanf("%hd", &entero_a);
    unidades = entero_a%10;
    decenas = (entero_a%100) - unidades;
    centenas = (entero_a%1000) - decenas - unidades;
    nuevo_entero = entero_a - (entero_a%1000) + (decenas * 10 ) + (centenas/10) + unidades;
    printf("%hd", nuevo_entero);
    return 0;
}