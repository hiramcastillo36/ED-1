/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 18 de octubre del 2022
 * Descripción: Se define un n-polígono-interesante. Tu tarea es encontrar el área de un polígono dada una n.
 *              Un 1-polígono-interesante es sólo un cuadrado con lado de longitud 1. Un -polígono-interesante es
 *              obtenido tomando un -polígono-interesante y adjuntando -polígonos-interesantes en sus bordes, es decir,
 *              agregando en cada lado un cuadrado de lado .
 */

#include <stdio.h>

int area(int, int);

int main() {
    int max_size, total_area;
    scanf("%d", &max_size);
    total_area = area(1, max_size);
    printf("%d", total_area);
    return 0;
}

int area(int n, int size) {
    if( n == size) {
        return size;
    }
    return area(n+1, size) + (2*size) - 1;
}



