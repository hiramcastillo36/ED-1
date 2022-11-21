/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Jueves, 01 de Septiembre del 2022
 * Descripción: Dado un número entero imprimir el nombre del mes correspondiente,
 * enero para el número 1,
 * febrero para el número 2, etc.
 */

#include <stdio.h>

int main(void) {
    int month=0;
    scanf("%d", &month);
    switch (month) {
        case 1:
            puts("enero");
            break;
        case 2:
            printf("febrero");
            break;
        case 3:
            printf("marzo");
            break;
        case 4:
            printf("abril");
            break;
        case 5:
            printf("mayo");
            break;
        case 6:
            printf("junio");
            break;
        case 7:
            printf("julio");
            break;
        case 8:
            printf("agosto");
            break;
        case 9:
            printf("septiembre");
            break;
        case 10:
            printf("octubre");
            break;
        case 11:
            printf("noviembre");
            break;
        case 12:
            printf("diciembre");
            break;
        default:
            printf("indefinido");

    }
    return 0;
}
