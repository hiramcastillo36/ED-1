/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 18 de Octubre del 2022
 * Descripción: Debe contar todas las letras de la oración que están en ASCII. Se ignorarán otros caracteres
 *              que no sean alfabéticos.
 */

#include <stdio.h>
#define MAX_STRING 105

int len_string(char []);
int len_string_rec(char [], int pos);

int main() {
    char string_a[MAX_STRING];
    scanf("\n%[^\n]s", string_a);
    int length_string=len_string(string_a);;
    printf("%d", length_string);
    return 0;
}

int len_string(char string[]) {
    return len_string_rec(string, 0);
}

int len_string_rec(char string[], int pos) {
    if(string[pos] == '\0') {
        return 0;
    }
    if (string[pos]>='a' && string[pos]<='z' || string[pos]>='A' && string[pos]<='Z') {
        return 1+len_string_rec(string, pos + 1);
    }
    return len_string_rec(string, pos + 1);
}



