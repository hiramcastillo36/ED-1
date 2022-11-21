/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Marte, 18 de Octubre del 2022
 * Descripción: Escribe un programa que calcule cuántas operaciones aritméticas (sumas, multiplicaciones por 2,
 *              divisiones entre 2) necesitará el algoritmo anterior para calcular el producto de dos números.
 *              La detección de la paridad de a es gratuita y no necesitas contarla.
 */

#include <stdio.h>
#define MAX_STRING 1010

long long int product(int, int);
long long int product_rec(int, int, long long int *);

int main() {
    int number_a, number_b;
    scanf("%d%d", &number_a, &number_b);
    long long int total = product(number_a, number_b);
    printf("%lld", total);
    return 0;
}

long long int product(int number_a, int number_b){
    long long int counter = 0;
    product_rec(number_a, number_b, &counter);
    return counter;
}

long long int product_rec(int number_a, int number_b, long long int *counter){
    if(number_a==0) {
        return -1;
    }
    if(number_a>0 && number_a%2==0 ){
        *counter = *counter + 2;
        return (2 * product_rec(number_a/2, number_b, counter));
    }
    if(number_a > 0 && number_a%2!=0) {
        *counter = *counter + 3;
        return (2 * product_rec(number_a/2, number_b, counter) + number_b);
    }
}