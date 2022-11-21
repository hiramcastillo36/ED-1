#include <stdio.h>
#include <string.h>

void swap(int *a, int *b){
    int aux=*a;
    *a=*b;
    *b=aux;
}

int mid(int ini, int fin, int a[]){
    int p=ini;
    for(int i=ini; i<fin; i++){
        if(a[i]>a[fin]){
            swap(&a[i], &a[p]);
            p++;
        }
    }
    swap(&a[p], &a[fin]);
    return p;
}

void quicksort(int ini, int fin, int a[]){
    if(ini<fin){
        int p=mid(ini, fin, a);
        quicksort(ini, p-1, a);
        quicksort(p+1, fin, a);
    }
}

int fib(int fin){

    if(fin < 2) {
        return fin;
    }
    return fib(fin - 1) + fib(fin - 2);

}

int main(void){
    int array [] = {-3,5,5,5,2,4,2,2,4,1,43,4131,43};
    char string[6][35] = {"hoa", "da", "ad", "de", "uu", "f"};
    /*for(int i=1; i<sizeof (array) / sizeof (int ) ; i++){
        int piv=i;
        while(piv>1 && array[piv] < array[piv-1]){
            swap(&array[piv], &array[piv-1]);
            piv-=1;
        }
    }

    quicksort(0, (sizeof (array)/ sizeof (int) )-1, array);*/
    int menor;
    int j = 5;
    for(int i=5; i>=0; i--){
        char aux[35];
        strcpy(aux, string[i]);
        strcpy(string[i], string[j]);
        strcpy(string[j], aux);
        j--;
    }
    for(int i=0; i<6; i++){
        printf("%s\n", string[i]);
    }
    /*for(int i=0; i<(sizeof (array)/ sizeof (int) )-1; i++){
        menor=i;
        for(int j=i+1; j<(sizeof (array)/ sizeof (int) ); j++){
            if(array[i]>array[j]){
                menor=j;
            }
        }
        swap(&array[menor], &array[i]);
    }
    int pos;
    for(int i=1; i<sizeof (array)/sizeof (int ); i++){
         pos=i;
        while(pos>1 && array[pos]<array[pos-1]){
            swap(&array[pos], &array[pos-1]);
            pos--;
        }
    }*/

    /*int s, fibo= fib(2), i=2;
    scanf("%d", &s);
    while (fibo<s){
        printf("%d ", fibo);
        fibo= fib(i+1);
        i++;
    }
    */
    return 0;
}