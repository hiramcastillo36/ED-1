/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Domingo, 18 de Septiembre del 2022
 * Descripción: Escribe un programa que determine el valor máximo p y el valor mínimo y que toma
 *              la función f(x)=ax^3+bx^2+cx+d en los enteros que se encuentran en el intervalo
 *              dado por M y N (incluyéndolos). Además, deberá determinar los puntos r y s en los cuales se
 *              alcanzan estos valores.
 */

#include <stdio.h>
#include <math.h>
#include <limits.h>

void calculo_minimos_maximos( int, int, int, int, int,  int, int *,  int *, long long int *, long long int *);
void verificacion_minimos_maximos( int, long long int, int *, int*, long long int *, long long int *);

int main() {
    int numero_a, numero_b, numero_c, numero_d, intervalo_a, intervalo_b, minimo_x, maximo_x;
    long long int minimo_y=LLONG_MAX, maximo_y=LLONG_MIN;
    scanf("%d %d %d %d %d %d", &numero_a, &numero_b, &numero_c, &numero_d, &intervalo_a, &intervalo_b);
    calculo_minimos_maximos( numero_a, numero_b, numero_c, numero_d, intervalo_a, intervalo_b,
                             &minimo_x, &maximo_x,
                            &minimo_y, &maximo_y);
    printf("%lld %lld %d %d", maximo_y, minimo_y, maximo_x, minimo_x);
    return 0;
}

void calculo_minimos_maximos( int numero_a,  int numero_b,int numero_c, int numero_d,  int intervalo_a,
                              int intervalo_b, int *minimo_x,  int *maximo_x, long long int *minimo_y,long long int *maximo_y){
    long long int resultado_funcion;
    for(int iterador=intervalo_a; iterador<=intervalo_b; iterador++){
        resultado_funcion = (numero_a*pow(iterador, 3)) + (numero_b*pow(iterador, 2)) + (numero_c*iterador) + numero_d;
        verificacion_minimos_maximos(iterador, resultado_funcion, minimo_x, maximo_x, minimo_y, maximo_y);
    }
}

void verificacion_minimos_maximos(int posicion_x, long long int resultado_evalucion, int *minimo_x,  int *maximo_x,long long  int *minimo_y, long long int *maximo_y){
    if(resultado_evalucion >= *maximo_y) {
        *maximo_x = posicion_x;
        *maximo_y = resultado_evalucion;
    }
    if( resultado_evalucion <= *minimo_y) {
        *minimo_y = resultado_evalucion;
        *minimo_x = posicion_x;
    }
}

