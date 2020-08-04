#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no{
    int dado;
    No* prox;
};
struct lista {
    No* inicio;
};

Lista* criar_lista(){
    Lista* lis = malloc(sizeof(Lista));
    lis->inicio = NULL;
    return lis;
}
void destruir_lista(Lista* lis){
    if(lis->inicio != NULL){
        while(lis->inicio != NULL){
            No* temp = lis->inicio->prox;
            free(lis->inicio);
            lis->inicio = temp;
        }
    }
    free(lis);
}
void inserir_fim(Lista* lis, int elem){
    No* novo = malloc(sizeof(No));
    novo->dado = elem;

    if(lis->inicio == NULL){
        lis->inicio = novo;
        novo->prox = NULL;
    }else{
        novo->prox = lis->inicio;
        lis->inicio = novo;
    }
}
void imprimir_lista(Lista* lis){
    No* p = lis->inicio;
    while (p != NULL){
        printf("%d ", p->dado);
        p = p->prox;
    }
    printf("\n");
    
}
No* buscar_elem(Lista *lis, int elem){
	No *atual = lis->inicio;
	while (atual != NULL) {
		if (atual->dado == elem) {
			return atual;
		}
		atual = atual->prox;
	}
	return NULL;
}
void remover_no(Lista* lis, No* no){
    
    if(lis->inicio != no){
        No* p = lis->inicio;
        while(p != NULL && p->prox != no){
            p = p->prox;
        }
        if(p->prox == no){
            p->prox = no->prox;
            free(no);
        }
    }else{
        lis->inicio = lis->inicio->prox;
        free(no);
    }
}
void remover_all_elem(Lista* lis, int elem){
    No* rem = buscar_elem(lis, elem);
    while(rem != NULL){
        remover_no(lis, rem);
        rem = buscar_elem(lis, elem);
    }
}
int confere_tripla_nada(Lista* lis){
    int saida = 0;
    if(lis->inicio !=  NULL){
        No* p = lis->inicio;
        while(p != NULL){
            if((p->prox != NULL) && (p->dado == p->prox->dado)){
                if((p->prox->prox != NULL) && (p->prox->dado == p->prox->prox->dado)){
                    saida = 1;
                }
            }
            p = p->prox;
        }

    }
    return saida;
}