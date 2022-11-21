/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 25 de octubre del 2022
 * Descripción: Escribe un programa que lea N reales positivos y que los ordene de la siguiente manera:
                    Si la parte decimal de a es menor que la parte decimal de b, entonces a debe ir antes que b.
                    La parte decimal incluye el punto decimal (es decir, 0.123<0.5).
                    Los números que empaten en la parte decimal deben quedar ordenados de menor a mayor.
 */
#include <stdio.h>
void quicksort(int right, int left, double [], double []);
void swap(double *, double *);
void print_array(int, double []);
void read_array(int, double [], double []);
int mid(int, int, double [], double []);
void print_mid(int, int [], int []);

int main() {
    int max_size;
    scanf("%d", &max_size);
    double array[max_size], decimals[max_size];
    read_array(max_size, array, decimals);

    quicksort(0, max_size-1, array, decimals);
    quicksort(0, max_size-1, decimals, array);
    print_array(max_size, array);
    return 0;
}

void print_mid(int size, int numbers[], int indexes[]){
    printf("%d %d", numbers[size/2], indexes[size/2]);
}

void print_array(int max_size, double array_a[max_size]){
    for(int i=0; i<max_size; i++) {
        printf("%g\n", array_a[i]);
    }
}

void swap(double *numero_a, double *numero_b) {
    double aux = *numero_a;
    *numero_a=*numero_b;
    *numero_b=aux;
}

int mid(int right, int left, double numbers[], double indexes[]){
    int p=right;
    for(int i=right; i<left; i++){
        if(numbers[i]<numbers[left]){
            swap(&numbers[i], &numbers[p]);
            swap(&indexes[i], &indexes[p]);
            p++;
        }
        if(numbers[i]==numbers[left]){
            if(indexes[i]<indexes[left]) {
                swap(&numbers[i], &numbers[p]);
                swap(&indexes[i], &indexes[p]);
                p++;
            }

        }
    }
    if(p!=left) {
        swap(&numbers[p], &numbers[left]);
        swap(&indexes[p], &indexes[left]);
    }
    return p;
}

void quicksort(int right, int left, double numbers[], double decimals[]){
    if(right<left) {
        int p = mid(right, left, numbers, decimals);
        quicksort(right, p-1, numbers, decimals);
        quicksort(p+1, left, numbers, decimals);
    }
}

void read_array(int size, double array[size], double decimals[]){
    for (int i=0; i<size; i++) {
        scanf("%lf", &array[i]);
        decimals[i] = array[i] - (int)array[i];
    }
}