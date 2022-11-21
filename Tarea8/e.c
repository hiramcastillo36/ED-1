/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 25 de octubre del 2022
 * Descripción: El siguiente procedimiento se llama conjetura de ULAM en honor al matemático S.Ulam:
                    Comience con cualquier entero positivo .
                    Si es par, divídalo entre 2
                    Si es impar, multiplíquelo por 3 y agréguele 1.
                    Obtenga enteros sucesivamente repitiendo el proceso
                    Al final, obtendra el número 1, independientemente del entero inicial.
                Tu tarea es dado un entero positivo N, imprime en orden ascendente todos los enteros generados por el
                procedimiento anteriormente planteado.
 */

#include <stdio.h>

void quicksort(int right, int left, int []);
void swap(int *, int *);
void print_array(int size, int [size]);
void read_array(int size, int [size], int [size]);
void ULAM(int, int *, int []);
int mid(int, int, int []);

int main() {
    int max_size, counter=0;
    scanf("%d", &max_size);
    int ulam_numbers[max_size];
    ULAM(max_size, &counter, ulam_numbers);
    quicksort(1, counter, ulam_numbers);
    print_array(counter, ulam_numbers);
    return 0;
}
void print_array(int max_size, int array_a[max_size]){
    for(int i=1; i<=max_size; i++) {
        printf("%d ", array_a[i]);
    }
}

void swap(int *numero_a, int *numero_b) {
    int aux = *numero_a;
    *numero_a=*numero_b;
    *numero_b=aux;
}

void ULAM(int number, int *counter, int ulam_numbers[]){
    *counter = *counter + 1;
    ulam_numbers[*counter]= number;
    if(number==1){
        return;
    }
    if(number%2==0) {
        ULAM(number/2, counter, ulam_numbers);
    }
    if(number%2!=0) {
        ULAM(number*3+1, counter, ulam_numbers);
    }
}

int mid(int right, int left, int ulam_numbers[]){
    int p=right;
    for(int i=right; i<left; i++){
        if(ulam_numbers[i]<ulam_numbers[left]){
            swap(&ulam_numbers[i], &ulam_numbers[p]);
            p++;
        }
    }
    swap(&ulam_numbers[p], &ulam_numbers[left]);
    return p;
}

void quicksort(int right, int left, int ulam_numbers[]){
    if(right<left) {
        int p = mid(right, left, ulam_numbers);
        quicksort(right, p-1, ulam_numbers);
        quicksort(p+1, left, ulam_numbers);
    }
}




