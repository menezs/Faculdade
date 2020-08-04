#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct no {
    float dado;
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

void fila_insere(Fila* f, float v){
    No* novo = malloc(sizeof(No));
    novo->dado = v;
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
        saida = temp->dado;
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
    while (p!=NULL){
        printf("%.1f ", p->dado);
        p=p->prox;
    }
    printf("\n");
}

void combina_filas(Fila* res, Fila* f1, Fila* f2){
    No* p1 = f1->inicio;
    No* p2 = f2->inicio;

    while(p1 !=NULL || p2!=NULL){
        if(p1 != NULL){
            fila_insere(res, p1->dado);
            p1 = p1->prox;
        }
        if(p2 != NULL){
            fila_insere(res, p2->dado);
            p2 = p2->prox;
        }
    }
}