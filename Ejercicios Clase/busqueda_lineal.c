/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Sabado, 8 de Octubre del 2022
 * Descripción: Consiste de dos cadenas A, B, que pueden contener espacios, una en cada renglón y con un máximo
 *              de 100 caracteres cada una. La salida consiste de la inversión de A, la inversión de B,
 *              la intercalación de A y B, la intercalación de B y A, la intercalación de A con la inversión de A,
 *              y la intercalación de B con la inversión de B, cada una en un renglón.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_STRING 105

void scanf_array( int size, int [size]);
int odds_or_evens(int size, int [size], int, int);

int main() {
    short int size_array;
    int state = 0 ;
    scanf("%hi", &size_array);
    int array[size_array];
    scanf_array(size_array-1, array);
    printf("%d\n", odds_or_evens(size_array , array, 5,0));
    return 0;
}

void scanf_array(int size, int array[size]) {
    if(size != 0) {
        scanf_array(size-1, array);
    }
    scanf("%d", &array[size]);
}

int odds_or_evens(int size, int array[size], int encontrar, int n){
    if(n>size ){
        return -1;
    }

    if(array[n]==encontrar) {
        return n;
    }


    return odds_or_evens(size, array, encontrar, n+1);
}




