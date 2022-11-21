/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Jueves, 01 de Septiembre del 2022
 * Descripción: Dado un carácter c determinar si se trata de una
 * letra mayúscula, letra minúscula, un dígito o un símbolo.
 */

#include <stdio.h>

int main(void) {
    char caracter_ascii;
    scanf("%c", &caracter_ascii);
    if (caracter_ascii >= 'A' && caracter_ascii <= 'Z') {
        printf("mayúscula");
    } else {
        if (caracter_ascii >= 'a' && caracter_ascii <= 'z') {
            printf("minúscula");
        } else {
            if (caracter_ascii >= '0' && caracter_ascii <= '9') {
                printf("dígito");
            } else {
                printf("símbolo");
            }
        }
    }
    return 0;
}
