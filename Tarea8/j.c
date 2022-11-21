/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 25 de octubre del 2022
 * Descripción: Dada una lista de N llaves, entonces cada llave sólo abriría la chapa del mismo tamaño. Como en verdad eran muchas puertas y muchas llaves,
 *              Alicia pensó que le tomaría mucho tiempo intentar abrir todas las puertas con las llaves correctas.
 *              Ayuda a Alicia a determinar qué llaves abren qué puertas.
 *              Problema: Encontrar las llaves que pueden abrir las puertas.
 */

#include <stdio.h>
#include <stdbool.h>

void print_array(int, int []);
void read_array(int, int []);
int binary_search(int, int, int []);
int binary_search_rec(int, int,int,  int []);
void quicksort(int right, int left, int []);
void swap(int *, int *);
int mid(int, int, int []);
void solve(int, int, int [], int []);

int main() {
    int max_array_a, max_array_b;
    scanf("%d", &max_array_a);
    int array_a[max_array_a];
    read_array(max_array_a, array_a);
    scanf("%d", &max_array_b);
    int array_b[max_array_b];
    read_array(max_array_b, array_b);
    solve(max_array_a, max_array_b, array_a, array_b);
    print_array(max_array_b, array_b);
    return 0;
}

void solve(int size_a, int size_b, int array_a[], int array_b[]) {
    for(int i=0; i<size_b; i++) {
        int answer = binary_search(size_a-1, array_b[i], array_a);
        array_b[i] =  answer;
    }
}

int binary_search(int size, int searching, int array[]) {
    return binary_search_rec(0, size, searching, array);
}

int binary_search_rec(int right, int left, int searching, int array[]) {
    if(right<=left) {
        int mitad= (right+left)/2;
        if(array[mitad] == searching){
            return mitad+1;
        }
        if(array[mitad] < searching) {
            return binary_search_rec(mitad+1, left, searching, array);
        }
        return binary_search_rec(right, mitad-1, searching, array);
    }
    return 0;
}

void read_array(int max_size, int array_a[]){
    for(int i=0; i<max_size; i++) {
        scanf("%d", &array_a[i]);
    }
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

int mid(int right, int left, int numbers[]){
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

void quicksort(int right, int left, int numbers[]){
    if(right<left) {
        int p = mid(right, left, numbers);
        quicksort(right, p-1, numbers);
        quicksort(p+1, left, numbers);
    }
}
