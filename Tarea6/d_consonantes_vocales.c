/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Sabado, 08 de Octubre del 2022
 * Descripción: Escribe un programa que lea una palabra  formada exclusivamente por letras mayúsculas (sin acentos, ni Ñ)
 * y que escriba el número  de consonantes y el número  de vocales que contiene.
 */

#include <stdio.h>
#include <string.h>
#define MAX_STRING 4095

void print_solve(char [], int *, int *);

int main() {
    char string[MAX_STRING];
    int consonants = 0, vowels=0;
    scanf("%s", string);
    print_solve(string, &consonants, &vowels);
    printf("%d %d", consonants, vowels);
    return 0;
}

void print_solve(char string[], int *consonants, int *vowels){
    int size = strlen(string);
    for(int i=0; i<size; i++) {
        if(string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U'){
            *vowels=*vowels+1;
        } else {
            *consonants = *consonants+1;
        }
    }
}