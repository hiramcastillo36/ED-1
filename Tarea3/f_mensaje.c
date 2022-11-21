/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Jueves, 01 de Septiembre del 2022
 * Descripción: Imprimir M mensajes de amor, con N cantidad de corazones.
 */

#include <stdio.h>

int main(void) {
    short int total_mensajes;
    short int total_corazones;
    scanf("%hd", &total_mensajes);
    for(int contador=0; contador<total_mensajes; contador++){
        scanf("%hd", &total_corazones);
        for(int corazones=0; corazones<total_corazones; corazones++){
            printf("<3");
        }
        printf("\n");
    }
    return 0;
}
