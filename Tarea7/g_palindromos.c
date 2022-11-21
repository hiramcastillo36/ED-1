/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 18 de octubre del 2022
 * Descripción: Escribe un programa que lea una palabra y decida si es palíndromo o no.
 */

#include <stdio.h>
#define MAX_STRING 1010

int len_string(char []);
int len_string_rec(char [], int pos);
int check_palindrome(int, int, char[]);

int main() {
    char string_a[MAX_STRING];
    scanf("\n%[^\n]s", string_a);
    int length_string=len_string(string_a);
    if(check_palindrome(0, length_string-1, string_a) ) {
        printf("Si");
    }else {
        printf("No");
    }
    return 0;
}

int check_palindrome(int right, int left, char string[]) {
    if(string[right] == string[left] && right < left) {
        return check_palindrome(right+1, left-1, string);
    } else if(string[right] != string[left]){
        return 0;
    }
    return 1;

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



