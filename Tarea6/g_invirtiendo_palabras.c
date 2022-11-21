/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Sabado, 08 de Octubre del 2022
 * Descripción: Dada una línea con palabras separadas por comas, escribe la misma línea pero con las palabras invertidas.
 */

#include <stdio.h>
#include <string.h>
#define MAX_STRING 4095

void solve(char [], char []);
void reverse_string(char []);

int main() {
    char string[MAX_STRING], final_reverse[MAX_STRING];
    scanf("%[^\n]s\n", string);
    solve(string, final_reverse);
    printf("%s", final_reverse);
    return 0;
}

void solve(char string[], char final_reverse[]){
    int size= strlen(string);
    char tem_reverse[size];
    for(int i=0, j=0; i<=size; i++, j++) {
        if(string[i] != ',' && string[i] != '\0'){
            tem_reverse[j] = string[i];
        } else {
            tem_reverse[j] = '\0';
            reverse_string(tem_reverse);
            strncat(tem_reverse, &string[i], 1 );
            strcat(final_reverse, tem_reverse);
            j=-1;
        }
    }
}

void reverse_string(char tem_reverse[]) {
    int size_reverse=strlen(tem_reverse);
    char aux[size_reverse];
    strcpy(aux, tem_reverse);
    for(int i=size_reverse-1; i >= 0; i--) {
        tem_reverse[size_reverse-i-1] = aux[i];
    }
}



