/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 18 de octubre del 2022
 * Descripción: Escribe un programa que implemente el siguiente algoritmo recursivo f,
 *              el cual opera sobre una secuencia S de enteros y realiza los siguientes pasos:
 *                   Invierte el orden de los elementos de S.
 *                   Si S tiene más de dos elementos, entonces:
 *                   Ejecuta f sobre la mitad izquierda de S.
 *                   Ejecuta f sobre la mitad derecha de S.
 */

#include <stdio.h>

void reverse(int, int []);
void reverse_rec(int, int, int[]);
void reverse_array_rec(int, int, int []);
void swap(int *, int *);
void scanf_array(int size, int [size]);
void print_array(int size, int []);

int main() {
    int size;
    scanf("%d", &size);
    int array[size];
    scanf_array(size-1, array);
    reverse(size, array);
    print_array(size-1, array);
    return 0;
}

void reverse(int size, int array[]){
    reverse_rec(0, size-1, array);
}

void reverse_rec(int right, int left,  int array[]){
    reverse_array_rec(right, left, array);
    if(left - right > 2 ) {
        int mid = (right + left) /2 ;
        reverse_rec(right, mid, array);
        reverse_rec(mid + 1, left, array);
    }
}

void scanf_array(int size, int array[size]) {
    if(size != 0) {
        scanf_array(size-1, array);
    }
    scanf("%d", &array[size]);
}

void print_array(int size, int array[]) {
    if(size != 0) {
        print_array(size-1, array);
    }
    printf("%d ", array[size]);
}

void swap(int *number_a, int *number_b) {
    int aux = *number_a;
    *number_a=*number_b;
    *number_b=aux;
}

void reverse_array_rec(int right, int left, int array[]){
    swap(&array[right], &array[left]);
    if(right+1 < left) {
        reverse_array_rec(right+1, left-1, array);
    }
}