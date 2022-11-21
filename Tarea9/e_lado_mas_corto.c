/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 31 de octubre del 2022
 * Descripción: Escribe un programa que, dadas las coordenadas de los vértices de un cuadrilátero, calcule
 *              la longitud de su lado más corto.
*/
#include <stdio.h>
#include <float.h>
#include <math.h>

struct coordinate {
    double x;
    double y;
};

void read_coordinates(struct coordinate []);
double min_length(struct coordinate []);

int main(void) {
    struct coordinate coordinates[4];
    read_coordinates(coordinates);
    printf("%lf", min_length(coordinates));
}

double min_length(struct coordinate coordinates[]){
    double min = DBL_MAX;
    for(int i=0; i<=2; i++) {
        double distance = sqrt(pow(coordinates[i+1].y-coordinates[i].y, 2) +pow(coordinates[i+1].x-coordinates[i].x, 2) );
        if(distance < min) {
            min= distance;
        }
    }
    double distance_3_1 = sqrt(pow(coordinates[3].y-coordinates[0].y, 2) +pow(coordinates[3].x-coordinates[0].x, 2) );
    if(distance_3_1 < min) {
        min = distance_3_1;
    }
    return min;
}

void read_coordinates(struct coordinate coordinates[]){
    for(int i=0; i<4; i++){
        scanf("%lf %lf", &coordinates[i].x, &coordinates[i].y);
    }
}
