/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Domingo, 18 de Septiembre del 2022
 * Descripción: Un número primo es aquel que solo es divisible entre si mismo y la unidad,
 * tu tarea es encontrar cuantos números primos hay de 1 hasta N y calcular la suma de estos.
 */

#include <stdio.h>
#include <stdbool.h>

void calculo_suma_primos(int, int *, int *);
bool es_primo(int);

int main() {
    int numero_a, suma_numero_primos=0, cantidad_numeros_primos=0;
    scanf("%d", &numero_a);
    calculo_suma_primos(numero_a, &suma_numero_primos, &cantidad_numeros_primos);
    printf("%d %d",  cantidad_numeros_primos, suma_numero_primos);
    return 0;
}

bool es_primo(int numero) {
    int contador=0;
    for(int verificar=1; verificar<=numero; verificar++){
        if(numero%verificar==0) {
            contador++;
        }
    }
    if(contador==2){
        return 1;
    } else {
        return 0;
    }
}

void calculo_suma_primos(int numero_a, int *suma_numero_primos, int *cantidad_numeros_primos) {
    for(int primo=1; primo<=numero_a; primo++){
        if(es_primo(primo) == 1){
            *suma_numero_primos = *suma_numero_primos+primo;
            *cantidad_numeros_primos= *cantidad_numeros_primos+1;
        }
    }
}

