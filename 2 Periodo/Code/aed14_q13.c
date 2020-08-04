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
    while(p != lis->fim){
        No* temp = p->prox;
        free(p);
        p = temp;
    }
    free(p);
    free(lis);
}
void inserir_incio(Lista* lis, int n){
    No* novo = malloc(sizeof(No));
    novo->num = n;
    if(lis->inicio == NULL){
        novo->prox = novo;
        novo->anterior = novo;
        lis->inicio = novo;
        lis->fim = novo;
    }else{
        novo->prox = lis->inicio;
        lis->inicio->anterior = novo;
        lis->inicio = novo;
        novo->anterior = lis->fim;
    }
}
void imprimir(Lista* lis){
    if(lis->inicio != NULL){
        No* p = lis->inicio;
        while(p != lis->fim){
            printf("%d ", p->num);
            p = p->prox;
        }
        printf("%d\n", p->num);
    }
}

void retira_inicio(Lista* l){
    if(l->inicio != NULL){
        No* p = l->inicio;
        l->inicio = p->prox;
        l->inicio->anterior = l->fim;
        p->prox = p->anterior = NULL;
        free(p);
    }
}

int main(void){
    int i, num, temp, vezes;
    Lista* lis = criar_lista();
    
    scanf("%d", &vezes);
    for(i=0; i<vezes; i++){
        scanf("%d", &num);
        if(num == 0){
            scanf("%d", &temp);
            inserir_incio(lis, temp);
        }else if(num == 1){
            retira_inicio(lis);
        }
    }
    imprimir(lis);

    destruir_lista(lis);
    return 0;
}