#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"


struct pilha {
    int tam;
    int uso;
    int* vet;
};

Pilha* pilha_cria(int tam){
    Pilha* p = malloc(sizeof(Pilha));
    p->uso = 0;
    p->tam = tam;
    p->vet = malloc(tam*sizeof(int));
    return p;
}
void pilha_push(Pilha* p, int mat){
    if(p->uso != p->tam){
        p->vet[p->uso]= mat;
        p->uso++;
    }
}
int pilha_pop(Pilha* p){
    int temp = p->vet[p->tam-1];
    p->tam--;
    p->uso--;
    return temp;
}
int pilha_vazia(Pilha* p){
    int saida = 0;
    if(p->tam > 0){
        saida = 1;
    }
    return saida;
}
void pilha_libera(Pilha* p){
    free(p->vet);
    free(p);
}
void imprimir(Pilha* p){
    int i;
    for(i=0; i<p->uso; i++){
        printf("%d\n", p->vet[i]);
    }
}
