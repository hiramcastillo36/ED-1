/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 18 de Octubre del 2022
 * Descripción: El coeficiente binomial (N K) puede definirse de forma recursiva como (N K) = (N-1 K) + (N-1 K-1)
 *              y (N 0) = (N N) = 1. Escribe un programa que calcule el valor de (N K) y cuántas llamadas a función
 *              hace la implementación recursiva (incluyendo la llamada original).
 */

#include <stdio.h>

int coeficiente_binomial(int, int);
int coeficiente_binomial_rec(int, int, long long int *);

int main() {
    int number_a, number_b;
    scanf("%d%d", &number_a, &number_b);
    int calls = coeficiente_binomial(number_a, number_b);
    printf("%lld", calls);
    return 0;
}

int coeficiente_binomial(int number_a, int number_b){
    int counter = 0;
    printf("%d ", coeficiente_binomial_rec(number_a, number_b, &counter));
    return counter;
}

int coeficiente_binomial_rec(int number_a, int number_b, long long int *counter){
    *counter = *counter +1;
    if(number_b==0 || number_a==number_b) {
        return 1;
    }
    return coeficiente_binomial_rec(number_a-1, number_b, counter) + coeficiente_binomial_rec(number_a-1, number_b-1, counter);
}

