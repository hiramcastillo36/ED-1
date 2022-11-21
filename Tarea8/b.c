/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 25 de octubre del 2022
 * Descripción: Con este problema vamos a repasar el manejo básico de arreglos. Crea un programa que permita leer un
 *              conjunto de N números enteros y después imprima una lista ordenada (de menor a mayor) de los números
 *              positivos y luego una lista ordenada (de mayor a menor) de los números negativos.
 */

#include <stdio.h>

void sort(int size, int [size]);
void swap(int *, int *);
void print_positive_integer(int, int []);
void print_negative_integer(int, int []);

int main() {
    int max_size;
    scanf("%d", &max_size);
    int array[max_size];
    for(int i=0; i<max_size; i++) {
        scanf("%d", &array[i]);
    }
    sort(max_size, array);
    print_positive_integer(max_size, array);
    print_negative_integer(max_size, array);
    return 0;
}

void swap(int *numero_a, int *numero_b) {
    int aux = *numero_a;
    *numero_a=*numero_b;
    *numero_b=aux;
}

void sort(int size, int array[size]){
    int menor;
    for(int i=0; i<size-1; i++){
        menor = i;
        for(int j=i+1; j<size; j++) {
            if(array[j]<array[menor]){
                menor = j;
            }
        }
        swap(&array[menor], &array[i]);
    }
}

void print_positive_integer(int size, int array[]){
    puts("POSITIVOS");
    for(int i=0; i<size; i++){
        if(array[i]>0){
            printf("%d\n", array[i]);
        }
    }
}
void print_negative_integer(int size, int array[]){
    puts("NEGATIVOS");
    for(int i=size-1; i>=0; i--){
        if(array[i]<0){
            printf("%d\n", array[i]);
        }
    }
}



