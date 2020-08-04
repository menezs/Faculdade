#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
struct no{
    int dado;
    No *prox;
};

typedef struct lista Lista;
struct lista{
    int tam;
    No *inicio;
    No *fim;
};

Lista *criar_lista(void){
    Lista* nova = malloc(sizeof(Lista));
    nova->tam = 0;
    nova->inicio = NULL;
    nova->fim = NULL;
    return nova;
}

void destruir_lista(Lista *lis){
    No* p = lis->inicio;
    while( p != lis->fim){
        No* t = p;
        p = p->prox;
        free(t);
    }
    free(p);
    free(lis);
}

void inserir_fim(Lista *lis, int elem){
    No* novo = malloc(sizeof(No));
    lis->tam++;
    novo->dado = elem;
    if(lis->inicio == NULL){
        lis->inicio = novo;
        novo->prox = novo;
        lis->fim = novo;
    }else{
        novo->prox = lis->inicio;
        lis->fim->prox = novo;
        lis->fim = novo;

    }   
}
void lst_imprime(Lista* l){
    No* p = l->inicio;
    if (p != NULL ) {
        do {
            printf("%d\n", p->dado);
            p=p->prox;
        }while (p != l->inicio);
    }
}
void removerNo(Lista* lis, No* rem){
    lis->tam--;
    if(lis->inicio == rem){
        No* temp = rem->prox;
        free(rem);
        lis->inicio = temp;
        lis->fim->prox = temp;
    }else if(lis->fim == rem){
        No* p = lis->inicio;
        while( p->prox != rem){
            p = p->prox;
        }
        free(rem);
        p->prox = lis->inicio;
        lis->fim = p;
    }else{
        No* p = lis->inicio;
        while (p->prox != rem){       
            p = p->prox;
        }
        p->prox = rem->prox;
        free(rem);
    }
}
void sorte_josephus(Lista* lis, int jump){
    int i=1;
    No* p = lis->inicio;
    while(lis->tam != 1){
        while(i != jump){
            i++;
            p = p->prox;
        }
        No* temp = p->prox;
        removerNo(lis, p);
        p = temp;
        i=1;
    }

}

int main(void){
    int i, num, jump;
    Lista* lis = criar_lista();
    
    scanf("%d%d", &num, &jump);
    for(i=1; i<=num; i++){
        inserir_fim(lis, i);
    }
    sorte_josephus(lis, jump);
    lst_imprime(lis);

    destruir_lista(lis);
    return 0;
}