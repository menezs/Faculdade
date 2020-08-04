#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nota Nota;
struct nota{
    float nota1;
    float nota2;
    float nota3;
};

Nota* cria(){
    Nota* tab = malloc(sizeof(Nota));
    if(tab == NULL){
        printf("memory");
        exit(1);
    }
    return tab;
}

Nota* realoca(int n, Nota* tab){
    tab = realloc(tab, n*sizeof(Nota));
    if(tab == NULL){
        printf("memory");
        exit(1);
    }
    return tab;
}

void libera(int n, Nota* tab){
    free(tab);
}

void imprime(Nota* tab, int n){
    int i;
    float media;
    for(i=0; i<n; i++){
        media = (tab[i].nota1+tab[i].nota2+tab[i].nota3)/3;
        printf("%.1f\n", media);
    }
}

int main(void){
    float nota1, nota2, nota3;
    int cont=1;

    Nota* tab = cria();
    scanf("%f%f%f", &nota1, &nota2, &nota3);
    tab[cont-1].nota1 = nota1;
    tab[cont-1].nota2 = nota2;
    tab[cont-1].nota3 = nota3;

    while( (scanf("%f%f%f", &nota1, &nota2, &nota3)) != EOF ){
        cont++;
        tab = realoca(cont, tab);

        tab[cont-1].nota1 = nota1;
        tab[cont-1].nota2 = nota2;
        tab[cont-1].nota3 = nota3;
        
    }
    imprime(tab, cont);

    libera(cont, tab);
    return 0;
}