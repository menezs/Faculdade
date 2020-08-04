
#include <stdio.h>
#include <stdlib.h>
typedef struct no No;
struct no{
    int num;
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
void destruir_listaCircular(Lista *lis){
    No* p = lis->inicio;
    while( p->prox != lis->inicio){
        No* t = p;
        p = p->prox;
        free(t);
    }
    free(p);
    free(lis);
}
void inserir_fim(Lista* lis, int n){
    No* novo = malloc(sizeof(No));
    novo->num = n;
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
void imprimir(Lista* lis){
    No* temp = lis->inicio;
    printf("%d ", temp->num);
    temp = temp->prox;
    while(temp != lis->inicio){
        printf("%d ", temp->num);
        temp = temp->prox;
    }
    printf("\n");
}
void para_circular(Lista* l){
    No* p = l->inicio;
    while (p->prox != NULL){
        p = p->prox;
    }
    p->prox = l->inicio;
}

int main(void){
    int num;
    Lista* lis = criar_lista();
    while( scanf("%d", &num) != EOF){
        inserir_fim(lis, num);
    }
    para_circular(lis);
    imprimir(lis);

    destruir_listaCircular(lis);
    return 0;
}