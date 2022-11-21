/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Jueves, 01 de Septiembre del 2022
 * Descripción: Dado un número inicial N, realizar las siguientes operaciones en el orden indicado y con enteros:
 * 1.- Si el valor actual de N es par, divídelo entre 2. En caso contrario, súmale 1.
 * 2.- Si el valor actual de N tiene tres o más cifras, divídelo entre 100. Pero si tiene exactamente dos cifras,
 * divídelo entre 10.
 * 3.- Si el valor actual de N es un múltiplo de tres, réstale uno.
 */

#include <stdio.h>

int main(void) {
    int numero_a = 0;
    int contador = 0;
    scanf("%d", &numero_a);

    if(numero_a%2==0){
        numero_a=numero_a/2;
        contador++;
    }else {
        numero_a++;
        contador++;
    }
    if(numero_a >=10 && numero_a <=99){
        numero_a=numero_a/10;
        contador++;
    } else if(numero_a >= 100){
        numero_a=numero_a/100;
        contador++;
    }
    if(numero_a%3==0){
        numero_a--;
        contador++;
    }
    printf("%d %d", numero_a, contador);
    return 0;
}