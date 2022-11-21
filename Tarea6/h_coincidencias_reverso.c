/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Sabado, 08 de Octubre del 2022
 * Descripción: Sea S una cadena y R su reverso, nos interesa contar cuántas coincidencias hay entre S y R.
 */

#include <stdio.h>
#include <string.h>
#define MAX_STRING 4095

void solve(char [], int *);
void reverse_string(char []);
void upper_string(char []);
void compare_indexes(char [], char [], int *);

int main() {
    char string[MAX_STRING];
    int coincidences=0;
    scanf("%[^\n]s\n", string);
    solve(string, &coincidences);
    printf("%d", coincidences);
    return 0;
}

void solve(char string[], int *coincidences){
    int size= strlen(string);
    char copy_string[size];
    upper_string(string);
    strcpy(copy_string, string);
    reverse_string(copy_string);
    compare_indexes(string, copy_string, coincidences);

}

void reverse_string(char tem_reverse[]) {
    int size_reverse=strlen(tem_reverse);
    char aux[size_reverse];
    strcpy(aux, tem_reverse);
    for(int i=size_reverse-1; i >= 0; i--) {
        tem_reverse[size_reverse-i-1] = aux[i];
    }
}

void upper_string(char string[]) {
    for(int i=0; i< strlen(string); i++) {
        if(string[i] >= 'A' && string[i]<= 'Z'){
            string[i]+=32;
        }
    }
}

void compare_indexes(char string[], char copy_reverse[], int *coincidences) {
    for(int i=0; i< strlen(string); i++) {
        if(string[i] == copy_reverse[i]){
            *coincidences = *coincidences + 1;
        }
    }
}



