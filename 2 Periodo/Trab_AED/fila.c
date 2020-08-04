#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct no {
    int matricula;
    No* prox;
};

struct fila {
    No* inicio;
    No* fim;
};

Fila* fila_cria(void){
    Fila* f = malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}

void fila_insere(Fila* f, int v){
    No* novo = malloc(sizeof(No));
    novo->matricula = v;
    if(f->inicio == NULL){
        f->inicio = f->fim = novo;
        novo->prox = NULL;
    }else{ 
        f->fim->prox = novo;
        f->fim = novo;
        novo->prox = NULL;
    }
}

float fila_retira(Fila* f){
    float saida;
    if(f->inicio != NULL){
        No* temp = f->inicio;
        f->inicio = temp->prox;
        saida = temp->matricula;
        free(temp);
    }
    return saida;
}

int fila_vazia(Fila* f){
    int saida = 0;
    if(f->inicio != NULL){
        saida = 1;
    }
    return saida;
}

void fila_libera(Fila* f){
    No* p = f->inicio;
    while (p != NULL){
        No* temp = p->prox;
        free(p);
        p=temp;
    }
    free(f);
}
void fila_imprime(Fila* f){
    No* p = f->inicio;
    if(p == NULL){
        printf("fila vazia\n");
    }else{
        while (p!=NULL){
            printf("%d", p->matricula);
            p=p->prox;
            if(p!=NULL){
                printf(", ");
            }
        }
        printf("\n");
    }
}