/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Domingo, 28 de Agosto del 2022
 * Descripción: Escribir un programa para obtener el último dígito de un número entero.
 */

#include <stdio.h>

int main() {
    int entero_a=0;
    int ultimo_digito=0;
    scanf("%d", &entero_a);
    ultimo_digito=entero_a%10;
    printf("%d", ultimo_digito);

    return 0;
}