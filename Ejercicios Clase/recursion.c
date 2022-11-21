#include <stdio.h>
#include <stdlib.h>

void a();
void b();
void c();

int main(void) {
    a();
    return 0;
}

void a() {
    puts("Entrando en A");
    b();
    puts("saliendo de A");
}
void b() {
    puts("Entrando en B");
    c();
    puts("saliendo de B");
}

void c() {
    puts("entrando en c");
    puts("saliendo de c");
}