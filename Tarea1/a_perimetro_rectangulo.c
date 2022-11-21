/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Domingo, 28 de Agosto del 2022
 * Descripción: Calcular el perímetro de un rectángulo a partir de la longitud de dos lados adyacentes.
 */

#include <stdio.h>

int main() {
    unsigned short int lado_adyancente_a=0;
    unsigned short int lado_adyancente_b=0;
    short int perimetro=0;
    scanf("%hd %hd", &lado_adyancente_a, &lado_adyancente_b);
    perimetro = (lado_adyancente_a*2) + (lado_adyancente_b*2);
    printf("%d", perimetro);
    return 0;
}
