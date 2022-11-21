/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 31 de octubre del 2022
 * Descripción:  El curso ya ha terminado y el profesor desea ordenar a los alumnos bajo los siguientes criterios:
 *                  Los alumnos de mayor calificación final deben aparecer primero.
 *                  En caso de empate en calificación final, los alumnos que hayan presentado la menor cantidad de exámenes deben aparecer primero.
 *                  En caso de empate en calificación final y en número de exámenes presentados, los alumnos con mayor calificación en el examen E1 deben aparecer primero.
*/
#include <stdio.h>

struct grades {
    int first_grade;
    int second_grade;
};

struct student {
    struct grades final_grades;
    double average;
};

void read_grades(int, struct student []);
void quicksort(int, int, struct student []);
int mid(int, int, struct student []);
void swap(struct student *, struct student *);
void print_students(int, struct student []);

int main(void){
    int students;
    scanf("%d", &students);
    struct student list_students[students];
    read_grades(students, list_students);
    quicksort(0, students-1, list_students);
    print_students(students, list_students);
    return 0;
}

void print_students(int total_students, struct student students[]){
    for(int i=total_students-1; i>=0; i--){
        printf("%d %d\n", students[i].final_grades.first_grade, students[i].final_grades.second_grade);
    }
}

void swap(struct student *student_a, struct student *student_b){
    struct student aux = *student_a;
    *student_a=*student_b;
    *student_b=aux;
}


int mid(int ini, int fin, struct student students[]){
    int p=ini;
    for(int i=ini; i<fin; i++){
        if(students[i].average < students[fin].average){
            swap(&students[i], &students[p]);
            p++;
        }
        if(students[i].average == students[fin].average && students[i].final_grades.second_grade == -1 && students->final_grades.second_grade == -1){
            if(students[i].final_grades.second_grade > students[fin].final_grades.second_grade){
                swap(&students[i], &students[p]);
                p++;

            }
        }
        if(students[i].average == students[fin].average){
             if(students[i].final_grades.second_grade > students[fin].final_grades.second_grade){
                swap(&students[i], &students[p]);
                p++;
            }
        }
    }
    swap(&students[p], &students[fin]);
    return p;
}

void quicksort(int ini, int fin, struct student students []){
    if(ini<fin){
        int p=mid(ini, fin, students);
        quicksort(ini, p-1, students);
        quicksort(p+1, fin, students);
    }
}

void read_grades(int total, struct student students[]){
    for(int i=0; i<total; i++) {
        scanf("%d %d", &students[i].final_grades.first_grade, &students[i].final_grades.second_grade);
        if (students[i].final_grades.second_grade != -1) {
            students[i].average = (students[i].final_grades.first_grade + students[i].final_grades.second_grade) / 2.0;
        } else
            students[i].average = students[i].final_grades.first_grade;
    }
}