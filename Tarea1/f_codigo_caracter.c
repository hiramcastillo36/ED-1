/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Domingo, 28 de Agosto del 2022
 * Descripción: Dado un entero , imprimir el carácter correspondiente de acuerdo con el código ASCII.
 */

#include <stdio.h>

int main() {
    unsigned short int posicion_ascii=0;
    scanf("%hu", &posicion_ascii);
    printf("%c", posicion_ascii);

    return 0;
}