/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 18 de octubre del 2022
 * Descripción: Se te dará un número n, que será el número que tendrás que convertir a binario.
 *              Un número entero positivo, llamémoslo n, se puede convertir a su forma binaria de la siguiente manera:
 *                  Se realiza la división entera de n sobre 2
 *                  Se anota el residuo de la división anterior
 *                  Se repite lo anterior con n = n/2 desde el paso 1 hasta llegar a n=0.
 *                  Se escribe el número desde el último residuo obtenido hasta el primer residuo obtenido.
 */

#include <stdio.h>

int binary(int, int);

int main() {
    int max_size, total_area;
    scanf("%d", &max_size);
    binary(max_size/2, max_size%2);
    return 0;
}

int binary(int n, int bit) {
    if(n!=0) {
        binary(n/2, n%2);
    }
    printf("%d", bit);
}



