/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 31 de octubre del 2022
 * Descripción: Gilgamesh piensa destruir primero a la montaña más alta que vea, lo que posiblemente vuelva visibles a
 *              algunas montañas de atrás, y así sucesivamente hasta destruir todo. Dadas las alturas y los nombres de
 *              las montañas, determine el orden en que serán destruídas.
 */

#include <stdio.h>

#define MAX_STRING 15

struct mountain {
    char name[MAX_STRING];
    float height;
    int index;
};

void quicksort(int right, int left, struct mountain[]);
void swap(struct mountain *, struct mountain *);
void print_array(int size, int [size]);
void print_mountains(int size, struct mountain []);
void read_mountains(int size, struct mountain []);
int mid(int, int, struct mountain mountains[]);
void sort(int size, struct mountain []);

int main() {
    int max_size;
    scanf("%d", &max_size);
    struct mountain mountains[max_size];
    read_mountains(max_size, mountains);
    quicksort(0,max_size-1, mountains);
    print_mountains(max_size, mountains);
    return 0;
}

void read_mountains(int size, struct mountain mountains[]){
    for(int i=0; i<size; i++) {
        scanf("%f %s", &(mountains[i]).height, (mountains[i]).name);
        (mountains[i]).index = i;
    }
}

void print_mountains(int max_size, struct mountain mountains[]){
    for(int i=max_size-1; i>0; i--) {
        printf("%s\n", mountains[i].name);
    }
    printf("%s", mountains[0].name);
}

void swap(struct mountain *mountain_a, struct mountain *mountain_b) {
    struct mountain mountain_aux= *mountain_a;
    *mountain_a=*mountain_b;
    *mountain_b=mountain_aux;
}

int mid(int right, int left, struct mountain mountains[]){
    int p=right;
    for(int i=right; i<left; i++){
        if(mountains[i].height<mountains[left].height){
            swap(&mountains[i], &mountains[p]);
            p++;
        }
        if(mountains[i].height==mountains[left].height){
            if(mountains[i].index>mountains[left].index) {
                swap(&mountains[i], &mountains[p]);
                p++;
            }
        }
    }
    swap(&mountains[p], &mountains[left]);
    return p;
}

void quicksort(int right, int left, struct mountain mountains[]){
    if(right<left) {
        int p = mid(right, left, mountains);
        quicksort(right, p-1, mountains);
        quicksort(p+1, left, mountains);
    }
}
