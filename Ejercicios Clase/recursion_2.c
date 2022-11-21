#include <stdio.h>
#include <stdlib.h>

void imprimir_numeros(int);

int main(void) {
    int n;
    scanf("%d", &n);
    imprimir_numeros(n);
    return 0;
}

void imprimir_numeros(int n) {
    if( n> 0){
        imprimir_numeros(n-1);
    }
    printf("%d", n);
}
