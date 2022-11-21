/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 31 de octubre del 2022
 * Descripción: Escribe un programa que lea una secuencia de N enteros distintos A=AO,A1,AN-1 y que determine el
 *              valor de la mediana de A así como su índice.
 */

#include <stdio.h>

struct number {
    int number;
    int index;
};

void read_struct(int, struct number []);
void print_struct(int, struct number []);
void quicksort(int, int, struct number []);
int mid(int, int, struct number []);
void swap(struct number *, struct number *);
void solve(int, struct number []);

int main(void) {
    int max_size;
    scanf("%d", &max_size);
    struct number list_numbers[max_size];
    read_struct(max_size, list_numbers);
    quicksort(0, max_size-1, list_numbers);
    solve(max_size, list_numbers);
}

void solve(int max_size, struct number list_numbers[]){
    int mid=max_size/2;
    printf("%d %d", list_numbers[mid].number, list_numbers[mid].index);
}

void read_struct(int size, struct number list_numbers[]) {
    for(int i=0; i<size; i++){
        scanf("%d", &list_numbers[i].number);
        list_numbers[i].index = i;
    }
}

void swap(struct number *number_a, struct number *number_b){
    struct number aux = *number_a;
    *number_a=*number_b;
    *number_b=aux;
}

int mid(int init, int fin, struct number list_numbers []){
    int p=init;
    for(int i=init; i<fin; i++){
        if(list_numbers[i].number < list_numbers[fin].number) {
            swap(&list_numbers[i], &list_numbers[p]);
            p++;
        }
    }
    swap(&list_numbers[p], &list_numbers[fin]);
    return p;
}

void quicksort(int init, int fin, struct number list_numbers[]) {
    if(init<fin) {
        int p=mid(init, fin, list_numbers);
        quicksort(init, p-1, list_numbers);
        quicksort(p+1, fin, list_numbers);
    }
}