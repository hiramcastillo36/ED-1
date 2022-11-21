/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Domingo, 18 de Septiembre del 2022
 * Descripción: Encontrar el área de una figura geométrica, en caso de ser una figura válida,
 *              las figuras pueden ser: trapecio, triangulo, cuadrado, rectangulo y circulo.
 */

#include <stdio.h>
#include <math.h>

float area_trapecio(float, float, float);
float area_triangulo(float, float);
float area_cuadrado(float);
float area_rectangulo(float, float);
float area_circulo(float);

int main() {
    int tipo_figura;
    scanf("%d", &tipo_figura);
    switch (tipo_figura) {
        case 0: {
            float base_mayor, base_menor, altura;
            scanf("%f %f %f", &base_mayor, &base_menor, &altura);
            puts("Trapecio");
            printf("%.3f", area_trapecio(base_mayor, base_menor, altura));
            break;
        }
        case 1:{
            float base, altura;
            scanf("%f %f", &base, &altura);
            puts("Triangulo");
            printf("%.3f", area_triangulo(base, altura));
            break;
        }
        case 2: {
            float lado;
            scanf("%f", &lado);
            puts("Cuadrado");
            printf("%.3f", area_cuadrado(lado));
            break;
        }
        case 3: {
            float base, altura;
            scanf("%f %f", &base, &altura);
            puts("Rectangulo");
            printf("%.3f", area_rectangulo(base, altura));
            break;
        }
        case 4: {
            float radio;
            scanf("%f", &radio);
            puts("Circulo");
            printf("%.3f", area_circulo(radio));
            break;
        }
        default:
            printf("Figura no valida");
            break;
    }
    return 0;
}

float area_trapecio(float base_mayor, float base_menor, float altura){
    return ((base_mayor+base_menor) / 2.0 * altura);
}
float area_triangulo(float base, float altura){
    return (base * altura) / 2.0;
}
float area_cuadrado(float lado){
    return (lado * lado);
}
float area_rectangulo(float base, float altura){
    return (base*altura);
}
float area_circulo(float radio){
    return 3.1416*pow(radio, 2.0);
}