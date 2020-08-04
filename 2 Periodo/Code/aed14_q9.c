#include <stdio.h>
#include <stdlib.h>
typedef struct no No;
struct no{
    char c;
    No* prox;
};

typedef struct lista Lista;
struct lista{
    No* inicio;
};

Lista* criar_lista(){
    Lista* lis = malloc(sizeof(No));
    lis->inicio = NULL;
    return lis;
}
void destruir_lista(Lista* lis){
    No* temp = lis->inicio;
    while(temp != NULL){
        No* prox = temp->prox;
        free(temp);
        temp = prox;
    }
    free(lis);
}
void inserir_fim(Lista* lis, char letra){
    No* novo = malloc(sizeof(No));
    novo->c = letra;
    if(lis->inicio == NULL){
        lis->inicio = novo;
        novo->prox = NULL;
    }else{
        No* p = lis->inicio;
        while( p->prox != NULL){
            p = p->prox;
        }
        novo->prox = NULL;
        p->prox = novo;
    }
}
Lista* copia(Lista* l){
    Lista* lis2 = criar_lista();
    No* temp = l->inicio;
    while( temp != NULL){
        inserir_fim(lis2, temp->c);
        temp = temp->prox;
    }

    return lis2;
}
void imprimir(Lista* lis){
    No* temp = lis->inicio;
    while(temp != NULL){
        printf("%c", temp->c);
        temp = temp->prox;
    }
    printf("\n");
}
int main(void){
    char letra;
    Lista* lis = criar_lista();
    scanf("%c", &letra);
    while( letra != '\n'){
        inserir_fim(lis, letra);
        scanf("%c", &letra);
    }
    Lista* lis2 = copia(lis);
    imprimir(lis2);

    destruir_lista(lis);
    destruir_lista(lis2);
    return 0;
}