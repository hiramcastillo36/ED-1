/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Martes, 18 de octubre del 2022
 * Descripción: Susana Distancia acaba de ser informada de su nueva misión. Ella debe localizar a N personas
 *              desinformadas, informarles que guarden la sana distancia y pedirles que cada una de ellas haga
 *              exactamente lo mismo con otras N-1 personas desinformadas. Las personas recién informadas harán lo suyo
 *              y le pedirán a las personas que ellos informen que repitan el proceso con N-2 personas desinformadas cada una,
 *              y así sucesivamente
 */

#include <stdio.h>

unsigned int susana(unsigned int);
unsigned int susana_rec(unsigned int, unsigned int);

int main() {
    int number_a;
    scanf("%d", &number_a);
    unsigned int total;
    total = susana(number_a);
    printf("%u", total);
    return 0;
}

unsigned int susana(unsigned int persons) {
    return susana_rec(persons, 1);
}
unsigned int susana_rec(unsigned int persons, unsigned int infec){
    if(persons == 0) {
        return 1;
    }
    return infec*persons+ susana_rec(persons-1,persons*infec);
}
