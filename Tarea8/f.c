/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 25 de octubre del 2022
 * Descripción: Escribe un programa que lea una secuencia de N enteros distintos A=a0, a1, a2, an-1 y que determine
 *              el valor de la mediana de A así como su índice.
 */

#include <stdio.h>

void quicksort(int right, int left, int [], int[]);
void swap(int *, int *);
void print_array(int size, int [size]);
void read_array(int size, int [size], int []);
int mid(int, int, int [], int []);
void print_mid(int, int [], int []);

int main() {
    int max_size;
    scanf("%d", &max_size);
    int array[max_size], indexes[max_size];
    read_array(max_size, array, indexes);
    quicksort(0, max_size-1, array, indexes);
    print_mid(max_size, array, indexes);
    return 0;
}

void print_mid(int size, int numbers[], int indexes[]){
    printf("%d %d", numbers[size/2], indexes[size/2]);
}

void print_array(int max_size, int array_a[max_size]){
    for(int i=0; i<max_size; i++) {
        printf("%d ", array_a[i]);
    }
}

void swap(int *numero_a, int *numero_b) {
    int aux = *numero_a;
    *numero_a=*numero_b;
    *numero_b=aux;
}

int mid(int right, int left, int numbers[], int indexes[]){
    int p=right;
    for(int i=right; i<left; i++){
        if(numbers[i]<numbers[left]){
            swap(&numbers[i], &numbers[p]);
            swap(&indexes[i], &indexes[p]);
            p++;
        }
    }
    swap(&numbers[p], &numbers[left]);
    swap(&indexes[p], &indexes[left]);
    return p;
}

void quicksort(int right, int left, int numbers[], int indexes[]){
    if(right<left) {
        int p = mid(right, left, numbers, indexes);
        quicksort(right, p-1, numbers, indexes);
        quicksort(p+1, left, numbers, indexes);
    }
}

void read_array(int size, int array[size], int indexes[]){
    for (int i=0; i<size; i++) {
        scanf("%d", &array[i]);
        indexes[i] = i;
    }
}


