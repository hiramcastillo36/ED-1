/*
 * Alumno: Castillo Gutierrez Hiram Jalil
 * Materia: Estructuras de Datos I
 * Fecha: Lunes, 31 de octubre del 2022
 * Descripción: Simular de una manera muy básica lo que ocurre con las cuentas de los clientes. Generalmente todo
 *              cliente de un banco tiene asociado un número de cliente , un nombre  y al menos una cuenta, sin embargo
 *              en esta práctica consideraremos que todo cliente tiene una sola cuenta y ésta es de débito.
 *              Para abrir una cuenta de débito es necesario realizarle un depósito inicial . A partir de allí se
 *              pueden realizar tantos depósitos , consultas  o retiros  (siempre que haya dinero) como el cliente desee.
 *              Si en algún momento lo desea el cliente puede dar de baja  una cuenta y evidentemente dejarla en ceros.
*/
#include <stdio.h>
#include <string.h>

struct client {
    int client_number;
    char name[4025];
    int balance;
};

void read_operations(int, struct client []);
void init_clients(struct client []);

int main(void){
    int operations;
    scanf("%d\n", &operations);
    struct client clients[15];
    init_clients(clients);
    read_operations(operations, clients);
}

void init_clients(struct client clients[]){
    for(int i=0; i<15; i++) {
        clients[i].balance = -1;
    }
}

void read_operations(int operations, struct client clients []){
    char op;
    int client_number_aux;
    int aux_balance;
    char name_ax[4025];
    for(int i=0; i<operations; i++) {
        scanf("\n%c", &op);
        switch (op) {
            case 'A':
                scanf("%d", &client_number_aux);
                scanf(" %s %d", name_ax, &aux_balance);
                if(clients[client_number_aux].balance==-1 && aux_balance > 0) {
                    clients[client_number_aux].client_number = client_number_aux;
                    clients[client_number_aux].balance = aux_balance;
                    strcpy(clients[client_number_aux].name, name_ax);
                    printf("OK\n");
                } else {
                    printf("ERROR\n");
                }
                break;
            case 'B':
                scanf("%d", &client_number_aux);
                if(clients[client_number_aux].client_number==client_number_aux  && clients[client_number_aux].balance != -1) {
                    clients[client_number_aux].client_number=0;
                    clients[client_number_aux].balance=-1;
                    printf("OK\n");
                } else {
                    printf("ERROR\n");
                }
                break;
            case 'C':
                scanf("%d", &client_number_aux);
                if(clients[client_number_aux].balance != -1) {
                    printf("%s %d\n", clients[client_number_aux].name, clients[client_number_aux].balance);
                } else {
                    printf("ERROR\n");
                }
                break;
            case 'D':
                scanf("%d", &client_number_aux);
                scanf(" %d", &aux_balance);
                if(clients[client_number_aux].balance != -1) {
                    clients[client_number_aux].balance = clients[client_number_aux].balance + aux_balance;
                    printf("%s %d\n", clients[client_number_aux].name, clients[client_number_aux].balance);
                } else {
                    printf("ERROR\n");
                }
                break;
            case 'E':
                scanf("%d %d", &client_number_aux, &aux_balance);
                if(clients[client_number_aux].balance != -1 && clients[client_number_aux].balance >= aux_balance) {
                    clients[client_number_aux].balance -= aux_balance;
                    printf("%s %d\n", clients[client_number_aux].name, clients[client_number_aux].balance);
                } else {
                    printf("ERROR\n");
                }
                break;
        }
    }
}
