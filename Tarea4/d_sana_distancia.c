/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Domingo, 18 de Septiembre del 2022
 * Descripción:  Dos personas A y B mantienen la sana distancia si están al menos a 150 cm entre sí,
 * de lo contrario tienen una insana distancia. Suponiendo que tienes las coordenadas (xa, ya)  y (xb, yb)
 * en centímetros de A y B, determina si mantienen una sana o insana distancia.
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

long long int distancia(int, int, int, int);
bool sana_insana_distancia(long long int, int);

int main() {
    int persona1_x, persona1_y, persona2_x, persona2_y;
    scanf("%d%d%d%d", &persona1_x, &persona1_y, &persona2_x, &persona2_y);
    bool solucion = sana_insana_distancia(distancia(persona1_x, persona1_y, persona2_x, persona2_y), 150);
    if(solucion == true) {
        printf("sana");
    } else {
        printf("insana");
    }
    return 0;
}

long long int distancia(int persona1_x, int persona1_y, int persona2_x, int persona2_y){
    long long int diferencia_potencia_x = pow(persona2_x-persona1_x, 2);
    long long int diferencia_potencia_y = pow(persona2_y-persona1_y, 2);
    long long int distancia = sqrt(diferencia_potencia_x+diferencia_potencia_y);
    return distancia;
}

bool sana_insana_distancia(long long int distancia_puntos, int verificar_distancia) {
    if(distancia_puntos >= verificar_distancia) {
        return true;
    } else {
        return false;
    }
}