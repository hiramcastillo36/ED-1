/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Jueves, 01 de Septiembre del 2022
 * Descripción: Dados dos números enteros a y b y un operador +, -, *, / o % entre ellos,
 * realizar la operación suma, resta, multiplicación, división o módulo correspondiente.
 */

#include <stdio.h>

int main(void) {
    int numero_a = 0;
    int numero_b = 0;

    float resultado_division=0;
    long long int resultado_entero=0;
    char caracter_ascii;
    scanf("%d ", &numero_a);
    scanf("%c ", &caracter_ascii);
    scanf("%d", &numero_b);

    switch (caracter_ascii) {
        case '+':
            resultado_entero = (long long int)numero_a + numero_b;
            break;
        case '-':
            resultado_entero = (long long int)numero_a - numero_b;
            break;
        case '/':
                if (numero_b == 0) {
                        printf("indefinido");
                        return 0;
                    } else {
                    printf("%d",  numero_a / numero_b);
                    return 0;
                }
        case '*':
            resultado_entero = (long long int)numero_a * numero_b;
            break;
        case '%':
            if(numero_b == 0) {
                printf("indefinido");
                return 0;
            } else {
                printf("%d", numero_a % numero_b);
                return 0;
            }

    }

    printf("%lld", resultado_entero);
    return 0;
}