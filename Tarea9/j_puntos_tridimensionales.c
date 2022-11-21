/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 31 de octubre del 2022
 * Descripción: Un punto P en el espacio tridimensional tiene coordenadas enteras (px,py,pz). Definiremos una función
 *              f que toma dos puntos A,B como parámetros y que regresa un punto usando el siguiente algoritmo:
 *              Si Ax<Bx, entonces:
 *                  Regresa A.
 *              Sino pero si Ay>By, entonces:
 *                  Regresa B.
 *              Sino entonces:
 *                  Regresa un punto con coordenadas (Ax+By, Ay, Bz).
 *              Dados tres puntos P,Q,R, escribe un programa que calcule e imprima los puntos S=F(F(P,Q),R) Y T=F(P,F(Q,R)).
*/
#include <stdio.h>

struct point {
    int x;
    int y;
    int z;
};

void read_points(struct point []);
struct point create_point(struct point, struct point);
void print_struct(struct point);

int main(void){
    struct point points[4];
    read_points(points);
    struct point point_p, point_t;
    point_p = create_point(create_point(points[0], points[1]), points[2]);
    point_t = create_point( points[0], create_point(points[1], points[2]));
    print_struct(point_p);
    puts("");
    print_struct(point_t);
}

void print_struct(struct point point_a){
    printf("%d %d %d", point_a.x, point_a.y, point_a.z);
}

void read_points(struct point points[]) {
    for(int i=0; i<3; i++){
        scanf("%d %d %d", &points[i].x, &points[i].y, &points[i].z);
    }
}

struct point create_point(struct point point_a, struct
        point point_b){
    if(point_a.x < point_b.x){
        return point_a;
    }
    else if(point_a.y > point_b.y){
        return point_b;
    } else {
        struct point new_point;
        new_point.x=point_a.x + point_b.x;
        new_point.y=point_a.y;
        new_point.z=point_b.z;
        return new_point;
    }
}