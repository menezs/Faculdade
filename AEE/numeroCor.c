#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct  no No;
struct no{
    No* ant;
    int dado;
    char cor[80];
    No* prox;
};
typedef struct lista Lista;
struct lista {
    No* inicio;
    No* fim;
};

Lista* criar_lista(){
    Lista* lis = malloc(sizeof(Lista));
    lis->inicio = lis->fim = NULL;
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
void inserir_fim(Lista* lis, int elem, char* cor){
    No* novo = malloc(sizeof(No));
    novo->dado = elem;
    strcpy(novo->cor, cor);

    if(lis->inicio == NULL){
        lis->inicio = lis->fim = novo;
        novo->prox = novo->ant = NULL;
    }else{
        novo->prox = lis->inicio;
        lis->inicio->ant = novo;
        lis->inicio = novo;
        novo->ant = NULL;
    }
}
void imprimir_lista(Lista* lis){
    No* p = lis->fim;
    while (p != NULL){
        printf("%d %s\n", p->dado, p->cor);
        p = p->ant;
    }
}
void trocar(No* ant, No* prox){
    char cor[80];
    strcpy(cor, prox->cor);
    int temp = prox->dado;

    prox->dado = ant->dado;
    strcpy(prox->cor, ant->cor);

    ant->dado = temp;
    strcpy(ant->cor, cor);
}
void ordenar_lista(Lista* lis){
    No* temp = lis->fim;
    while(temp != lis->inicio){
        int trocou = 0;
        No* temp2 = lis->inicio;
        while(temp2 != temp){
            if(temp2->dado < temp2->prox->dado){
                trocar(temp2, temp2->prox);
                trocou = 1;
            }
            temp2 = temp2->prox;
        }
        if(!trocou){
            break;
        }
        temp = temp->ant;
    }
}
void buscarCor(Lista* lis, int chave){
    ordenar_lista(lis);
    No* temp = lis->fim;
    while(temp != NULL){
        if(temp->dado == chave){
            printf("%s\n", temp->cor);
            break;
        }
        temp = temp->ant;
    }
    if(temp == NULL){
        printf("nada\n");
    }
}

int main (void){
    Lista* lis = criar_lista();
    int  n, i, num;
    char cor[80];

    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d %s", &num, cor);
        inserir_fim(lis, num, cor);
    }
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &num);
        buscarCor(lis, num);
    }
    
    destruir_lista(lis);
    return 0;
}