/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 31 de octubre del 2022
 * Descripción: En una encuesta sobre salud, se recogieron los datos de 1<=N<=100 personas,
 *              se requiere capturar id, nombre, peso y estatura para cada una de las N personas, calcular su imc y generar como
 *              salida una lista de ids, nombres e imc.
*/

#include <stdio.h>
#include <math.h>
#define MAX_STRING 4025

struct person {
    int id;
    float height;
    float weight;
    char name[MAX_STRING];
    float imc;
};

void read_structs(int, struct person []);
void print_structs(int, struct person []);
void quicksort(int, int, struct person []);
int mid(int, int, struct person []);
void swap(struct person *, struct person *);

int main(void) {
    int size;
    scanf("%d", &size);
    struct person list_persons[size];
    read_structs(size, list_persons);
    quicksort(0, size-1, list_persons);
    print_structs(size, list_persons);
}

void read_structs(int size, struct person persons[]) {
    for(int i=0; i<size; i++){
        scanf("%d", &persons[i].id, persons[i].name, &persons[i].weight, &persons[i].height);
        scanf("\n%[^\n]s", persons[i].name);
        scanf("%f", &persons[i].weight);
        scanf("%f", &persons[i].height);
        persons[i].imc=persons[i].weight/(pow(persons[i].height, 2));
    }
}

void print_structs(int size, struct person persons[]) {
    for(int i=0; i<size-1; i++){
        printf("%d %s %.1f\n", persons[i].id, persons[i].name, persons[i].imc);
    }
    printf("%d %s %.1f", persons[size-1].id, persons[size-1].name, persons[size-1].imc);
}

void swap(struct person *person_a, struct person *person_b){
    struct person aux=*person_a;
    *person_a=*person_b;
    *person_b=aux;
}

int mid(int init, int fin, struct person persons[]){
    int p=init;
    for(int i=init; i<fin; i++){
        if(persons[i].imc>persons[fin].imc){
            swap(&persons[i], &persons[p]);
            p++;
        }
    }
    swap(&persons[p], &persons[fin]);
    return p;
}

void quicksort(int init, int fin, struct person persons[]) {
    if(init<fin){
        int p=mid(init, fin, persons);
        quicksort(init, p-1, persons);
        quicksort(p+1, fin, persons);
    }
}