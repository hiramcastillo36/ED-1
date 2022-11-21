/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 25 de octubre del 2022
 * Descripción: Escribe un programa que lea una secuencia de N enteros y los ordene de la siguiente manera:
                    Deberán aparecer primero los enteros que tengan menos cifras.
                    En caso de empate en cantidad de cifras, deberán aparecer primero los enteros de mayor valor.
 */

#include <stdio.h>

void quicksort_ascending(int right, int left, int []);
void quicksort_descending(int right, int left, int []);
void swap(int *, int *);
void print_array(int, int []);
void read_array(int, int []);
void sort_numbers(int , int []);
int mid_ascending(int, int, int []);
int mid_descending(int, int, int []);
int cifras(int);

int main() {
    int max_size;
    scanf("%d", &max_size);
    int numbers[max_size];
    read_array(max_size, numbers);
    quicksort_ascending(0, max_size-1, numbers);
    sort_numbers(max_size-1, numbers);
    print_array(max_size, numbers);
    return 0;
}

int cifras(int n) {
    int cifra=0;
    do {
        cifra++;
        n=n/10;
    }while(n!=0);
    return cifra;
}

void sort_numbers(int max_size, int numbers[]) {
    int flag=0, right=0;
    while(right<max_size) {
        while (cifras(numbers[flag]) == cifras(numbers[right + 1]) && right<max_size) {
            right++;
        }
        quicksort_descending(flag, right , numbers);
        flag = right+1;
    }
}
void read_array(int max_size, int array_a[max_size]){
    for(int i=0; i<max_size; i++) {
        scanf("%d", &array_a[i]);
    }
}

void print_array(int max_size, int array_a[max_size]){
    for(int i=0; i<max_size-1; i++) {
        printf("%d ", array_a[i]);
    }
    if(max_size>0)printf("%d", array_a[max_size-1]);
}

void swap(int *numero_a, int *numero_b) {
    int aux = *numero_a;
    *numero_a=*numero_b;
    *numero_b=aux;
}

int mid_ascending(int right, int left, int numbers[]){
    int p=right;
    for(int i=right; i<left; i++){
        if(numbers[i]<numbers[left]){
            swap(&numbers[i], &numbers[p]);
            p++;
        }
    }
    swap(&numbers[p], &numbers[left]);
    return p;
}

int mid_descending(int right, int left, int numbers[]){
    int p=right;
    for(int i=right; i<left; i++){
        if(numbers[i]>numbers[left]){
            swap(&numbers[i], &numbers[p]);
            p++;
        }
    }
    swap(&numbers[p], &numbers[left]);
    return p;
}

void quicksort_ascending(int right, int left, int numbers[]){
    if(right<left) {
        int p = mid_ascending(right, left, numbers);
        quicksort_ascending(right, p-1, numbers);
        quicksort_ascending(p+1, left, numbers);
    }
}

void quicksort_descending(int right, int left, int numbers[]){
    if(right<left) {
        int p = mid_descending(right, left, numbers);
        quicksort_descending(right, p-1, numbers);
        quicksort_descending(p+1, left, numbers);
    }
}



