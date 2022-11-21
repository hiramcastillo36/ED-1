/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 18 de Octubre del 2022
 * Descripción: Escribe un programa que lea un arreglo de N enteros y un entero P. Si P=0, tu programa deberá imprimir
 *              los valores del arreglo que sean pares; si P=1, tu programa deberá imprimir los valores
 *              del arreglo que sean impares. El orden de aparición debe respetarse.
 */

#include <stdio.h>
#define MAX_STRING 105

void scanf_array(short int size, int [size]);
void odds_or_evens(short int size, int [size], int, int, int);

int main() {
    short int size_array;
    int state = 0 ;
    scanf("%hi", &size_array);
    int array[size_array];
    scanf_array(size_array-1, array);
    scanf("%d", &state);
    odds_or_evens(size_array - 1, array, state, -1, 0);
    return 0;
}

void scanf_array(short int size, int array[size]) {
    if(size != 0) {
        scanf_array(size-1, array);
    }
    scanf("%d", &array[size]);
}

void odds_or_evens(short int size, int array[size], int state, int pos, int n){
    int aux_pos=-1;
    if (pos != -1)
        printf("%d ", array[pos]);
    if(n <= size) {
        if((state == 1 && array[n] % 2 != 0) || (state == 0 && array[n] % 2 == 0)) {
            aux_pos=n;
        }
        odds_or_evens(size , array, state, aux_pos, n+1);
    }

}




