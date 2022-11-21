/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Jueves, 01 de Septiembre del 2022
 * Descripción: Determinar si la temperatura es fria, tibia o caliente,
 * si la temperatura es >= 0 y < 15, la salida es "fria! RIP escamitas :(",
 * si es temperatura es >= 15 y <21, la salida es "fria!",
 * si la temperatura es >= 21 y <= 29, la salida es "tibia",
 * si la temperatura es > 29 y <= 34, la salida es "calienta",
 * si la temperatura es > 34, la salida es "caliente! RIP escamitas :("
 */

#include <stdio.h>

int main(void) {
    short int temperatura=0;
    scanf("%hd", &temperatura);
    if(temperatura >= 0 && temperatura < 15) {
        printf("fria!\nRIP escamitas :(");
    } else {
        if (temperatura >= 15 && temperatura < 21) {
            printf("fria!");
        } else {
            if (temperatura >= 21 && temperatura <= 29) {
                printf("tibia");
            } else {
                if (temperatura <= 34) {
                    printf("caliente!");
                } else {
                    if (temperatura > 34) {
                        printf("caliente!\nRIP escamitas :(");
                    }
                }
            }
        }
    }

    return 0;
}
