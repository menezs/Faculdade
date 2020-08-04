#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
struct no{
    No* anterior;
    No* prox;
    int num;
};

typedef struct lista Lista;
struct lista{
    No* inicio;
    No* fim;
};

Lista* criar_lista(){
    Lista* lis = malloc(sizeof(Lista));
    lis->fim = lis->inicio = NULL;
    return lis;
}

void destruir_lista(Lista* lis){
    No* p = lis->inicio;
    while(p != NULL){
        No* temp = p;
        free(p);
        p = temp;
        p = p->prox;
    }
    free(lis);
}
void inserir_incio(Lista* lis, int n){
    No* novo = malloc(sizeof(No));
    novo->num = n;
    if(lis->inicio == NULL){
        novo->prox = NULL;
        novo->anterior = NULL;
        lis->inicio = novo;
        lis->fim = novo;
    }else{
        novo->prox = lis->inicio;
        lis->inicio->anterior = novo;
        lis->inicio = novo;
        novo->anterior = NULL;
    }
}
void imprimir(Lista* lis){
    if(lis->inicio != NULL){
        No* p = lis->inicio;
        while(p != NULL){
            printf("%d ", p->num);
            p = p->prox;
        }
        printf("\n");
    }
}


void retira_inicio(Lista* l){
    if(l->inicio != NULL){
        No* p = l->inicio;
        l->inicio = p->prox;
        l->inicio->anterior = NULL;
        p->prox = NULL;
        free(p);
    }
}

void retira_final(Lista* l){
    No* p = l->fim;
    l->fim = p->anterior;
    l->fim->prox = NULL;
    p->anterior = NULL;
    free(p);
}

int main(void){
    int i, num, temp;
    Lista* lis = criar_lista();
    scanf("%d", &num);
    for(i = 0; i<num; i++){
        scanf("%d", &temp);
        inserir_incio(lis, temp);
    }
    scanf("%d", &num);
    for(i=0; i<num; i++){
        scanf("%d", &temp);
        if(temp == 0){
            retira_inicio(lis);
        }else if(temp == 1){
            retira_final(lis);
        }
    }
    imprimir(lis);

    destruir_lista(lis);
    return 0;
}