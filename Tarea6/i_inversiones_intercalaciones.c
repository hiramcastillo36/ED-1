/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Sabado, 8 de Octubre del 2022
 * Descripción: Consiste de dos cadenas A, B, que pueden contener espacios, una en cada renglón y con un máximo
 *              de 100 caracteres cada una. La salida consiste de la inversión de A, la inversión de B,
 *              la intercalación de A y B, la intercalación de B y A, la intercalación de A con la inversión de A,
 *              y la intercalación de B con la inversión de B, cada una en un renglón.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_STRING 4095

void solve(char [], char [], char []);
void reverse_string(char []);
bool check_palindrome(char [], char []);
void intercalate_strings(char [], char [], char []);

int main() {
    char string_a[MAX_STRING], final_reverse[MAX_STRING], string_b[MAX_STRING];
    scanf("\n%[^\n]s", string_a);
    scanf("\n%[^\n]s", string_b);
    solve(string_a, string_b, final_reverse);
    printf("%s", final_reverse);
    return 0;
}

void solve(char string_a[], char string_b[], char final_reverse[]){
    char reverse_a[MAX_STRING], reverse_b[MAX_STRING],
            intercalate_string_a_string_b[MAX_STRING],
            intercalate_reverse_string_a_string_b[MAX_STRING],
            intercalate_string_a_reverse_a[MAX_STRING],
            intercalate_string_b_reverse_b[MAX_STRING];
    strcpy(reverse_a, string_a);
    strcpy(reverse_b, string_b);
    reverse_string(reverse_a);
    reverse_string(reverse_b);
    printf("%s\n%s\n", reverse_a, reverse_b);
    intercalate_strings(string_a, string_b, intercalate_string_a_string_b);
    intercalate_strings(string_b, string_a, intercalate_reverse_string_a_string_b);
    printf("%s\n%s", intercalate_string_a_string_b, intercalate_reverse_string_a_string_b);
    intercalate_strings(string_a, reverse_a, intercalate_string_a_reverse_a);
    intercalate_strings(string_b, reverse_b, intercalate_string_b_reverse_b);
    printf("\n%s\n%s", intercalate_string_a_reverse_a, intercalate_string_b_reverse_b);
}

void reverse_string(char tem_reverse[]) {
    int size_reverse=strlen(tem_reverse);
    char aux[size_reverse];
    strcpy(aux, tem_reverse);
    for(int i=size_reverse-1; i >= 0; i--) {
        tem_reverse[size_reverse-i-1] = aux[i];
    }
}

bool check_palindrome(char string_a[], char string_b[]) {
    for(int i=0; i< strlen(string_a); i++) {
        if(string_a[i] != string_b[strlen(string_b)-i-1]) {
            return 0;
        }
    }
    return 1;
}

void intercalate_strings(char string_a[], char string_b[], char final_string[]){
    char end = '\0';
    int size_a= strlen(string_a);
    int size_b= strlen(string_b);
    for(int i=0; i<= size_a || i<= size_b; i++){
        if(string_a[i] != '\0' && i<=size_a) {
            strncat(final_string, &string_a[i], 1);
        }
        if(string_b[i] != '\0' && i<=size_b) {
            strncat(final_string, &string_b[i], 1);
        }
    }
}



