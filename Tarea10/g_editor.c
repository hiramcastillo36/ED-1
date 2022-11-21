/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 14 de noviembre del 2022
 * Descripción: Dada una cadena si # es el carácter de borrado, la cadena abc#d##e es en realidad la cadena ae.
 * El primer # cancela la c, el segundo la d y el tercero la b.
 * Los editores de texto también tienen un carácter de eliminación de línea, que cancela todos los caracteres anteriores
 * de la línea actual. Por ejemplo, si @ es el carácter de eliminación de línea, la cadena abc@de#f es en realidad
 * la cadena df. El @ cancela la línea abc y el carácter # elimina e. La salida es la misma cadena de entrada sin
 * incluir los caracteres especiales ni los caracteres que fueron borrados.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10001
typedef char TDPila;

struct pila{
    TDPila arreglo[MAX];
    int tope;
};

void inicializar_pila(struct pila *);
void apilar(struct pila *, TDPila);
TDPila desapilar(struct pila *);
bool esta_vacia(const struct pila *);
void eliminar_caracter(struct pila *);
void eliminar_linea(struct pila *);
int size_pila(const struct pila *);
void print_pila(struct pila *);
void leer_linea(struct pila *, char []);
struct pila invertir_pila(struct pila *);

int main(void){
    char cadena[MAX];
    scanf("%[^\n]s", cadena);
    struct pila linea_de_texto;
    inicializar_pila(&linea_de_texto);
    leer_linea(&linea_de_texto, cadena);
    struct pila texto_invertido=invertir_pila(&linea_de_texto);
    print_pila(&texto_invertido);
}

struct pila invertir_pila(struct pila *p){
    struct pila invertida;
    inicializar_pila(&invertida);
    while(!esta_vacia(p)){
        apilar(&invertida, desapilar(p));
    }
    return invertida;
}

void leer_linea(struct pila *p, char cadena[]){
    for(int i=0; i< strlen(cadena); i++){
        if(cadena[i] != '@' && cadena[i] != '#'){
            apilar(p, cadena[i]);
        } else {
            if(cadena[i]=='@'){
                eliminar_linea(p);
            }
            if(cadena[i]=='#'){
                eliminar_caracter(p);
            }
        }
    }
}

void eliminar_caracter(struct pila *p){
    desapilar(p);
}
void eliminar_linea(struct pila *p){
    while(!esta_vacia(p)){
        desapilar(p);
    }
}

void print_pila(struct pila *p){
    while(!esta_vacia(p)) {
        printf("%c", desapilar(p));
    }
}

int size_pila(const struct pila *p){
    return p->tope;
}

void inicializar_pila(struct pila *p){
    p->tope=0;
}

void apilar(struct pila *p, TDPila dato){
    p->arreglo[p->tope] = dato;
    p->tope++;
}

TDPila desapilar(struct pila *p){
    if(!esta_vacia(p)){
        p->tope--;
        return p->arreglo[p->tope];
    }
}

bool esta_vacia(const struct pila *p){
    if(p -> tope == 0) {
        return true;
    } else {
        return false;
    }
}
