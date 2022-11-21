/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Sabado, 08 de Octubre del 2022
 * Descripción: Se te dará un número N, que será el numero de líneas que vas a leer.
 * Posteriormente, deberas imprimir el numero de caracteres por cada cadena.
 */

#include <stdio.h>
#include <string.h>

void print_solve(char []);

int main() {
    int inputs;
    char string[100];
    scanf("%d", &inputs);
    for(int i=0; i<inputs; i++){
        scanf("\n%[^\n]s", string);
        print_solve(string);
    }
    return 0;
}

void print_solve(char string[]){
    int size = strlen(string);
    printf("\"%s\" tiene %d caracteres\n", string, size);
}