/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Domingo, 18 de Septiembre del 2022
 * Descripción: Dado un entero positivo N, el problema 3n+1 consiste en determinar si es posible llegar a 1 aplicando
 *              repetidamente las siguientes operaciones:
 *                  Si N es par, divídelo entre .
 *                  Si N es impar, multiplícalo por  y súmale .
 */

#include <stdio.h>

void secuencia(int *, int *);
void intercambio_mayor(int *, int *);

int main() {
    int pasos, contador=0, numero_mayor;
    scanf("%d", &pasos);
    numero_mayor=pasos;
    while(pasos!=1) {
        secuencia(&pasos, &contador);
        intercambio_mayor(&pasos, &numero_mayor);
    }
    printf("%d %d", contador, numero_mayor);
    return 0;
}

void secuencia(int *pasos, int *contador) {
    if(*pasos%2==0){
        *pasos = *pasos / 2;
    }else {
        *pasos=*pasos*3+1;
    }
    *contador=*contador+1;
}

void intercambio_mayor(int *pasos, int *pasos_mayor) {
    if(*pasos > *pasos_mayor) {
        *pasos_mayor = *pasos;
    }
}