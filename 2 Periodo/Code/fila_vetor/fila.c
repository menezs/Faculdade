#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


struct fila {
    int tam;
    float* vet;
};

Fila* fila_cria(void){
    Fila* f = malloc(sizeof(Fila));
    f->tam = 0;
    f->vet = malloc(sizeof(float));
    return f;
}

void fila_insere(Fila* f, float v){
    if(f->tam == 0){
        f->vet[0] = v;
        f->tam++;
    }else{ 
        f->tam++;
        f->vet = realloc(f->vet, f->tam*sizeof(float));
        f->vet[f->tam-1] = v;
    }
}

float fila_retira(Fila* f){
    int i;
    float saida = f->vet[0];

    if(f->tam > 0){
        for(i=0; i<f->tam-1; i++){
            f->vet[i] = f->vet[i+1];
        }
        f->tam -= 1;
    }
    return saida;
}

int fila_vazia(Fila* f){
    int saida = 0;
    if(f->tam > 0){
        saida = 1;
    }
    return saida;
}

void fila_libera(Fila* f){
    free(f->vet);
    free(f);
}
void fila_imprime(Fila* f){
    int i;
    for(i=0; i<f->tam; i++){
        printf("%.1f ", f->vet[i]);
    }
    printf("\n");
}

void combina_filas(Fila* res, Fila* f1, Fila* f2){
    int cont1=0, cont2=0;
    while(cont1!=f1->tam || cont2!=f2->tam){
        if(cont1!= f1->tam){
            fila_insere(res, f1->vet[cont1]);
            cont1++;
        }
        if(cont2 != f2->tam){
            fila_insere(res, f2->vet[cont2]);
            cont2++;
        }
    }
}