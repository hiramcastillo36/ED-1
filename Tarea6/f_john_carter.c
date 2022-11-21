/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Sabado, 08 de Octubre del 2022
 * Descripción: El caballo de John era capaz de recorrer una unidad de distancia en P segundos, mientras que le tomaba
 * S segundos recorrerla si el terreno estaba inclinado (de subida) y B segundos si estaba declinado (de bajada).
 * Calcula el tiempo total en segundos que le tomó al caballo de John Carter recorrer todo el terreno.
 * Donde el caracter - representa una unidad de terreno plano, / una unidad de terreno inclinado y \ una unidad de terreno declinado
 */

#include <stdio.h>
#include <string.h>
#define MAX_STRING 4095

void solve(char [], int, int, int, int *);
void update_final_time(int, int *);

int main() {
    char string[MAX_STRING];
    int final_time=0, distance_time, distance_rising_time, distance_lowering_time;
    scanf("%d %d %d", &distance_time, &distance_rising_time, &distance_lowering_time);
    scanf("\n%[^\n]s", string);
    solve(string, distance_time, distance_rising_time, distance_lowering_time, &final_time);
    printf("%d", final_time);
    return 0;
}

void solve(char string[], int distance_time, int distance_rising_time, int distance_lowering_time, int *final_time){
    int size= strlen(string);
    for(int i=0; i<size; i++) {
        if(string[i] == '-') {
            update_final_time(distance_time, final_time);
        } else if(string[i] == '/') {
            update_final_time(distance_rising_time, final_time);
        } else {
            update_final_time(distance_lowering_time, final_time);
        }
    }
}

void update_final_time(int time, int *final_time) {
    *final_time= *final_time + time;
}



