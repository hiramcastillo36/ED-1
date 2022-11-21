/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Jueves, 01 de Septiembre del 2022
 * Descripción: Dados los números p,s,r
 * deberás determinar el número  de días que tardará en salir el caracol.
 * el caracol sube S metros cada día, pero se resbala r metros cada noche.
 * Si s es mayor que r, el caracol logrará salir finalmente del agujero.
 */

#include <stdio.h>

int main(void) {
    int profundidad, sube_metros, baja_metros, distancia=0, dias=1;
    scanf("%d%d%d", &profundidad, &sube_metros, &baja_metros);
    while(profundidad > distancia+sube_metros){
        distancia += sube_metros;
        distancia -= baja_metros;
        dias++;
    }
    printf("%d", dias);
    return 0;
}
