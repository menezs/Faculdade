#include <stdio.h>
#include <stdlib.h>
typedef struct no No;
struct no{
    int num;
    No* prox;
};
typedef struct lista Lista;
struct lista{
    No* incio;
    No* fim;
};

Lista* criar_lista(){
    Lista* lis = malloc(sizeof(Lista));
    lis->fim = NULL;
    lis->incio =NULL;
    return lis;
}
void destruir_lista(Lista* lis){
    No* p = lis->incio;
    while(p != NULL){
        No* temp = p;
        p=p->prox;
        temp->prox = NULL;
        free(temp);
    }
    free(p);
    free(lis);
}
void inserir_fim(Lista* lis, int elem){
    No* novo = malloc(sizeof(No));
    novo->num = elem;
    if(lis->incio == NULL){
        lis->incio = novo;
        lis->fim = novo;
        novo->prox = novo;
    }else{
        lis->fim->prox = novo;
        novo->prox = lis->incio;
        lis->fim = novo;
    }
}
void imprimir(Lista* lis){
    No* temp = lis->incio;
    while( temp != lis->fim){
        printf("%d\n", temp->num);
        temp = temp->prox;
    }
    printf("%d\n", temp->num);
}
void numero_perfeito(Lista* lis, int num){
    int i, soma = 0;
    for(i=1; i<num; i++){
        if(num%i == 0){
            inserir_fim(lis, i);
        }
    }
    imprimir(lis);
    No* temp = lis->incio;
    while(temp != lis->fim){
        soma += temp->num;
        temp = temp->prox;
    }
    soma += temp->num;
    if(soma == num){
        printf("PERFEITO\n");
    }else{
        printf("NAO PERFEITO\n");
    }
}

int main(void){
    int num;
    Lista* lis = criar_lista();
    scanf("%d", &num);
    numero_perfeito(lis, num);

    destruir_lista(lis);
    return 0;
}