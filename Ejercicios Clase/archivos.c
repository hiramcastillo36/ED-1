#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE* archivo;
    archivo = fopen("data/entrada.txt", "r");
    int pares=0, impares=0, numero;
    if(archivo == NULL) {
        printf("NO EXiSTE");
        exit(EXIT_FAILURE);
    }

    while(!feof(archivo)){
        //fgetc(archivo); para leer caracter por caracter
        fscanf(archivo, "%d", &numero);
        if(numero%2==0){
            pares++;
        } else {
            impares++;
        }
    }
    printf("Pares;%d Impares:%d",pares, impares);
    fclose(archivo);
    return 0;
}