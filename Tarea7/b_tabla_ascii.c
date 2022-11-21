/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 18 de Octubre del 2022
 * Descripción: Deberas imprimir la lista de caracteres ASCII con sus valores en decimal y hexadecimal,
 *              el rango sera especificado por el usuario.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_STRING 105

void print_character_decimal_hex(int, int);

int main() {
    short int limit_inferior, limit_superior;
    scanf("%hi%hi", &limit_inferior, &limit_superior);
    print_character_decimal_hex(limit_inferior, limit_superior);
    return 0;
}

void print_character_decimal_hex(int limit_inferior, int limit_superior) {
    if(limit_inferior!=limit_superior) {
        print_character_decimal_hex(limit_inferior, limit_superior-1);
    }
    printf("%c\t%d\t%x\n", limit_superior, limit_superior, limit_superior);
}





