/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 31 de octubre del 2022
 * Descripción: Considere un conjunto de N registros que representan la información de un usuario de acuerdo con los
 *              siguientes campos:
 *                  * Un número de identificación compuesto por 8 digitos.
 *                  * Un promedio compuesto por un número real no negativo.
 *                  * Un entero que representa la edad del usuario.
 *              Ordene este conjunto de datos con base en la edad del usuario y posteriormente imprima la
 *              información del K-ésimo usuario de acuerdo al valor indicado de K.
 */
#include <stdio.h>

struct user {
    char id[10];
    float average;
    int age;
};

void read_users(int, struct user []);
void print_user(int, int, struct user []);
void quicksort(int, int, struct user []);
int mid(int, int, struct user []);
void swap(struct user *, struct user *);

int main(void) {
    int size, user;
    scanf("%d", &size);
    struct user users[size];
    read_users(size, users);
    scanf("%d", &user);
    quicksort(0, size-1, users);
    print_user(user, size, users);
}

void print_user(int user, int size, struct user users[]) {
    if(user <= size-1){
        printf("%s\n%.2f\n%d", users[user].id, users[user].average, users[user].age);
    } else {
        printf("ERROR");
    }
}

void read_users(int size, struct user users[]){
    for(int i=0; i<size; i++){
        scanf("\n%s\n%f\n%d", &users[i].id, &users[i].average, &users[i].age);
    }
}
void swap(struct user *number_a, struct user *number_b){
    struct user aux = *number_a;
    *number_a=*number_b;
    *number_b=aux;
}

int mid(int init, int fin, struct user users []){
    int p=init;
    for(int i=init; i<fin; i++){
        if(users[i].age < users[fin].age) {
            swap(&users[i], &users[p]);
            p++;
        }
    }
    swap(&users[p], &users[fin]);
    return p;
}

void quicksort(int init, int fin, struct user users[]) {
    if(init<fin) {
        int p=mid(init, fin, users);
        quicksort(init, p-1, users);
        quicksort(p+1, fin, users);
    }
}
