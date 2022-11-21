/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 31 de octubre del 2022
 * Descripción: Escribe un programa que lea N reales positivos y que los ordene de la siguiente manera:
 *              Si la parte decimal de a es menor que la parte decimal de b, entonces a debe ir antes que b.
 *              La parte decimal incluye el punto decimal (es decir, 0.123 < 0.5).
 *              Los números que empaten en la parte decimal deben quedar ordenados de menor a mayor.
 */

#include <stdio.h>

struct number {
    float number;
    float decimal;
};

void read_numbers(int, struct number numbers[]);
void print_numbers(int, struct number number[]);
int mid(int, int, struct number numbers[]);
void quicksort(int, int, struct number numbers[]);
void swap(struct number *, struct number *);

int main(void) {
    int size;
    scanf("%d", &size);
    struct number numbers[size];
    read_numbers(size, numbers);
    quicksort(0, size-1, numbers);
    print_numbers(size, numbers);
}

void print_numbers(int size, struct number numbers[]){
    for(int i=0; i<size; i++){
        printf("%g\n", numbers[i].number);
    }
}
void swap(struct number *number_a, struct number *number_b){
    struct number aux = *number_a;
    *number_a=*number_b;
    *number_b=aux;
}

int mid(int init, int fin, struct number numbers[]){
    int p=init;
    for(int i=init; i<fin; i++) {
        if(numbers[i].decimal < numbers[fin].decimal) {
            swap(&numbers[i], &numbers[p]);
            p++;
        }
        if(numbers[i].decimal==numbers[fin].decimal){
            if(numbers[i].number < numbers[fin].number) {
                swap(&numbers[i], &numbers[p]);
                p++;
            }
        }
    }
    if(p!=fin) {
        swap(&numbers[p], &numbers[fin]);
    }
    return p;
}

void quicksort(int init, int fin, struct number numbers[]){
    if(init< fin) {
        int p = mid(init, fin, numbers);
        quicksort(init, p-1, numbers);
        quicksort(p+1, fin, numbers);
    }
}

void read_numbers(int size, struct number numbers[]){
    for(int i=0; i<size; i++){
        scanf("%f", &numbers[i].number);
        numbers[i].decimal = numbers[i].number - (int)numbers[i].number;
    }
}