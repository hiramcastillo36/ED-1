/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Sabado, 08 de Octubre del 2022
 * Descripción: Imprimirás la palabra caracter por caracter. Cada caracter debe estar un una nueva línea.
 */

#include <stdio.h>
#include <string.h>

void print_string(char []);

int main() {
    char string[100];
    scanf("%s", string);
    print_string(string);
    return 0;
}

void print_string(char string[]){
    for(int i=0; i< strlen(string); i++){
        printf("%c\n", string[i]);
    }
}
