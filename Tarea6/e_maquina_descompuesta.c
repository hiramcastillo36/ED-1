/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Sabado, 08 de Octubre del 2022
 * Descripción: Dada una cadena deberes considerar una regla simplificada de los casos de mayúscula inicial:
 *              la primera letra de cada enunciado (que terminaremos con punto) debe ser mayúscula,
 *              todas las demás letras deben ser minúsculas.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_STRING 4095

void solve(char []);
void letter_to_uppercase(char , char [], int);
void letter_to_lowercase(char , char [], int);

int main() {
    char string[MAX_STRING];
    scanf("%[^\n]s", string);
    solve(string);
    printf("%s", string);
    return 0;
}

void solve(char string[]){
    int size = strlen(string);
    bool flag=0;
    for(int i=0; i<size; i++) {
        if(flag==0) {
            if (string[i] >= 'a' && string[i] <= 'z' && string[i] != ' ') {
                letter_to_uppercase(string[i], string, i);
                flag=1;
            }
            if (string[i] >= 'A' && string[i] <= 'Z' ) flag=1;
        } else {
            if(flag==1){
                if (string[i] >= 'A' && string[i] <= 'Z' && string[i] != ' ') {
                    letter_to_lowercase(string[i], string, i);
                }
            }
        }
        if(string[i] == '.') {
            flag=0;
        }
    }
}

void letter_to_uppercase(char letter, char formatter_string[], int pos){
    formatter_string[pos] = letter-32;

}

void letter_to_lowercase(char letter, char formatter_string[], int pos){
    formatter_string[pos] = letter+32;
}