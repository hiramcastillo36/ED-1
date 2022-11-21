/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 25 de octubre del 2022
 * Descripción: Dada un listado de nombres de personas, imprimirlos en orden alfabético.
 */

#include <stdio.h>
#include <string.h>
void sort(int size, char [][55]);
void swap(char *, char *);

int main() {
    int max_size;
    scanf("%d", &max_size);
    char strings[max_size][55];
    for(int i=0; i<max_size; i++) {
        scanf("\n%[^\n]s", strings[i]);
    }
    sort(max_size, strings);
    for(int i=0; i<max_size; i++) {
        printf("%s\n", strings[i]);
    }
    return 0;
}

void swap(char string_a[], char string_b[]) {
    char aux[55];
    strcpy(aux, string_a);
    strcpy(string_a, string_b);
    strcpy(string_b, aux);
}

void sort(int size, char strings[][55]){
    int menor;
    for(int i=0; i<size-1; i++){
        menor = i;
        for(int j=i+1; j<size; j++) {
            if(strcmp(strings[j], strings[menor])<0){
                menor = j;
            }
        }
        if (menor != i){
            swap(strings[menor], strings[i]);
        }
    }
}



