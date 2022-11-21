/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Domingo, 18 de Septiembre del 2022
 * Descripción: Dados A, B, C se desea saber la cantidad  de números T de la que consta la tabla de múltiplos
 *              correspondiente y cuál es el número M más grande en esa tabla.
 */

#include <stdio.h>

void calculo_multiplos(int, int, long long int, long long int *, int *);
void asignacion_producto_mayor(long long int, long long int, long long int *);

int main() {
    int numero_a, numero_b, numero_multiplos=0;
    long long int producto_mayor, numero_limite;
    scanf("%d %d %lld", &numero_a, &numero_b, &numero_limite);

    producto_mayor=numero_a;
    calculo_multiplos(numero_a, numero_b, numero_limite, &producto_mayor, &numero_multiplos);
    printf("%d %lld", numero_multiplos, producto_mayor);
    return 0;
}

void calculo_multiplos(int numero_a, int numero_b, long long int numero_limite, long long int *producto_mayor, int *numero_multiplos){
    long long int producto_a=numero_a, producto_b=numero_b;
    for(int factor=1; (factor*numero_a<=numero_limite) || (factor*numero_b<=numero_limite); factor++) {
        producto_a=factor*numero_a;
        producto_b=factor*numero_b;
        if(producto_a<=numero_limite ){
            *numero_multiplos=*numero_multiplos+1;
            if(producto_a%numero_b==0){
                *numero_multiplos=*numero_multiplos-1;
            }
            asignacion_producto_mayor(producto_a, numero_b, producto_mayor);
        }
        if(producto_b<=numero_limite) {
            *numero_multiplos=*numero_multiplos+1;
            asignacion_producto_mayor(numero_a, producto_b, producto_mayor);
        }

    }
}

void asignacion_producto_mayor(long long int producto_a, long long int producto_b, long long int *producto_mayor){
    if(producto_a > producto_b) {
        if(producto_a> *producto_mayor){
            *producto_mayor=producto_a;
        }
    }else {
        if(producto_b> *producto_mayor){
            *producto_mayor=producto_b;
        }
    }
}