/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Jueves, 01 de Septiembre del 2022
 * Descripción: Escribe un programa que determine si existe
 * algún número que pertenezca a ambos intervalos.
 */

#include <stdio.h>

int main(void) {
    int intervalo_a1 = 0;
    int intervalo_a2 = 0;
    int intervalo_b1 = 0;
    int intervalo_b2 = 0;
    scanf("%d%d%d%d", &intervalo_a1, &intervalo_a2, &intervalo_b1, &intervalo_b2);
    if (intervalo_a2 <= intervalo_b1) {
        if (intervalo_a2 - intervalo_b1 >= 0) {
            printf("1");
        } else {
            printf("0");
        }
    } else {
        if (intervalo_b2 - intervalo_a1 >= 0) {
                printf("1");
            }else{
            printf("0");
        }
    }

    return 0;
}
