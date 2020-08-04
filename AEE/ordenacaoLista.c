#include <stdio.h>
#include <stdlib.h>

typedef struct  no No;
struct no{
    No* ant;
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
void inserir_inicio(Lista* lis, int elem){
    No* novo = malloc(sizeof(No));
    novo->dado = elem;

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
void ordenar_lista(Lista* lis){
    No* temp = lis->fim;
    while(temp != lis->inicio){
        int trocou = 0;
        No* temp2 = lis->inicio;
        while(temp2 != temp){
            if(temp2->dado > temp2->prox->dado){
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

int main (void){
    Lista* lis = criar_lista();
    int  num;

    while(scanf("%d", &num) != EOF){
        inserir_inicio(lis, num);
    }
    
    ordenar_lista(lis);
    imprimir_lista(lis);
    
    
    destruir_lista(lis);
    return 0;
}