/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Jueves, 01 de Septiembre del 2022
 * Descripción: Escribe un programa que lea cuatro años e
 * imprima cuántos días tendrá febrero en esos años.
 */

#include <stdio.h>

int main(void) {
    int year_a=0, year_b=0, year_c=0, year_d=0;
    int year_a_solved, year_b_solved, year_c_solved, year_d_solved;
    scanf("%d%d%d%d", &year_a, &year_b, &year_c, &year_d);
    if(year_a%4==0 && year_a%100!=0){
        year_a_solved=29;
    } else {
        if (year_a % 400 == 0) {
            year_a_solved = 29;
        } else {
            year_a_solved = 28;
        }
    }
    if(year_b%4==0 && year_b%100!=0){
        year_b_solved=29;
    } else {
        if (year_b % 400 == 0) {
            year_b_solved = 29;
        } else {
            year_b_solved = 28;
        }
    }
    if(year_c%4==0 && year_c%100!=0){
        year_c_solved=29;
    } else {
        if (year_c % 400 == 0) {
            year_c_solved = 29;
        } else {
            year_c_solved = 28;
        }
    }
    if(year_d%4==0 && year_d%100!=0){
        year_d_solved=29;
    } else {
        if (year_d % 400 == 0) {
            year_d_solved = 29;
        } else {
            year_d_solved = 28;
        }
    }
    printf("%d %d %d %d", year_a_solved, year_b_solved, year_c_solved, year_d_solved);
    return 0;
}
