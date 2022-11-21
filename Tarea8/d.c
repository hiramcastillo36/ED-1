/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 25 de octubre del 2022
 * Descripción: Elaborar un programa que lea las ventas de un conjunto de vendedores y devuelva los vendendores con
 *              mayor número de ventas. La salida deberá tener a los k mejores vendedores con sus ventas respectivas.
 *              La primera línea recibirá n y k que son el número total de vendedores y el número de mejores
 *              vendedores a buscar, respectivamente.
 */

#include <stdio.h>
#include <string.h>
#define MAX_STRING 4095

void sort(int size,  char [][MAX_STRING],int [size]);
void swap(int *, int *);
void swap_string(char *, char *);
void print_array(int size,  char [][MAX_STRING], int [size],int);
void read_array(int size, char [][MAX_STRING], int [size]);

int main() {
    int max_size, limit;
    scanf("%d %d", &max_size, &limit);
    int checkouts[max_size];
    char names[max_size][MAX_STRING];
    read_array(max_size, names, checkouts);
    sort(max_size, names, checkouts);
    print_array(max_size, names, checkouts,  limit);
    return 0;
}
void print_array(int max_size,  char array_a[][MAX_STRING], int array_b[max_size], int limit){
    for(int i=0; i<limit; i++) {
        printf("%s %d\n", array_a[i], array_b[i]);
    }
}
void read_array(int max_size,  char array_a[][MAX_STRING], int array_b[max_size]){
    for(int i=0; i<max_size; i++) {
        scanf("\n%s %d", &array_a[i], &array_b[i]);
    }
}

void swap(int *numero_a, int *numero_b) {
    int aux = *numero_a;
    *numero_a=*numero_b;
    *numero_b=aux;
}
void swap_string(char string_a[], char string_b[]) {
    char aux[MAX_STRING];
    strcpy(aux, string_a);
    strcpy(string_a, string_b);
    strcpy(string_b, aux);
}

void sort(int size,  char array_y[][MAX_STRING], int array_x[size]){
    int menor;
    for(int i=0; i<size-1; i++){
        menor = i;
        for(int j=i+1; j<size; j++) {
            if(array_x[j]>array_x[menor]){
                menor = j;
            }
        }

        if (menor != i){
            swap_string(array_y[menor], array_y[i]);
            swap(&array_x[menor], &array_x[i]);
        }
    }
}





