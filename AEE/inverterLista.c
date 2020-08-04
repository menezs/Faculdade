#include <stdio.h>
#include <stdlib.h>

typedef struct  no No;
struct no{
    int dado;
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
void inserir_fim(Lista* lis, int elem){
    No* novo = malloc(sizeof(No));
    novo->dado = elem;

    if(lis->inicio == NULL){
        lis->inicio = lis->fim = novo;
        novo->prox = NULL;
    }else{
        lis->fim->prox = novo;
        lis->fim = novo;
        novo->prox = NULL;
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
void trocar(No* ant, No* prox){
    int temp = prox->dado;
    prox->dado = ant->dado;
    ant->dado = temp;
}
void trocaNo(No* atual, No* ant){
    if(atual->prox!=NULL)
        trocaNo(atual->prox, atual);
    atual->prox = ant;
}
void inverte(Lista* lis){
	trocaNo(lis->inicio, NULL);
    No* temp = lis->inicio;
    lis->inicio = lis->fim;
    lis->fim = temp;
}
int main (void){
    Lista* lis = criar_lista();
    int  num;

    while(scanf("%d", &num) != EOF){
        inserir_fim(lis, num);
    }
    
    inverte(lis);
    imprimir_lista(lis);
    
    
    destruir_lista(lis);
    return 0;
}