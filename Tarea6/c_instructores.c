/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Sabado, 08 de Octubre del 2022
 * Descripción: Dada una lista de cadenas, imprimir la cantidad de instructores que se tienen en la cadena.
 */

#include <stdio.h>
#include <string.h>
#define MAX_STRING 4095

void print_solve(char [], int *);

int main() {
    char string[MAX_STRING];
    int counter = 1;
    scanf("%[^\n]s", string);
    print_solve(string, &counter);
    printf("%d", counter);
    return 0;
}

void print_solve(char string[], int *counter){
    int size = strlen(string);
    for(int i=0; i<size-1; i++) {
        if(string[i] == ' ' && string[i+1] != ' '){
            *counter=*counter+1;
        }
    }
}