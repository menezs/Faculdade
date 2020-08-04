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
    int tam;
    No* inicio;
    No* fim;
};

Lista* criar_lista(){
    Lista* lis = malloc(sizeof(Lista));
    lis->tam = 0;
    lis->fim = lis->inicio = NULL;
    return lis;
}

void destruir_lista(Lista* lis){
    No* p = lis->inicio;
    while(p != NULL){
        No* temp = p->prox;
        free(p);
        p = temp;
    }
    free(lis);
}
void inserir(Lista* lis, int pos,  int valor){
    int i=0;
    lis->tam++;
    No* novo = malloc(sizeof(No));
    novo->num = valor;

    if( pos == 0){
        novo->prox = lis->inicio;
        lis->inicio->anterior = novo;
        novo->anterior = NULL;
    }else{
        No* p = lis->inicio;
        while(p != NULL && i != pos){
            i++;
            p = p->prox;
        }
        if( i == pos){
            if( p == NULL){
                novo->prox = NULL;
                lis->fim->prox = novo;
                novo->anterior = lis->fim;
                lis->fim = novo;
            }else{
                p->prox->anterior = novo;
                novo->prox = p->prox;
                p->prox = novo;
                novo->anterior = p;  
            }
        }
    }
    
}
void imprimir(Lista* lis){
    if(lis->inicio != NULL){
        No* p = lis->fim;
        while(p != NULL){
            printf("%d ", p->num);
            p = p->anterior;
        }
        printf("\n");
    }
}
void retirar(Lista* lis, int pos){
    if(lis->inicio != NULL){
        int i=0;
        No* temp = lis->inicio;
        while( temp != NULL && i != pos){
            i++;
            temp = temp->prox;
        }
        if(i == pos){
            if(lis->inicio == temp){
                lis->inicio = temp->prox;
                lis->inicio->anterior = NULL;
                temp->prox = NULL;
                free(temp);
            }else if(lis->fim == temp){
                lis->fim = temp->anterior;
                lis->fim->prox = NULL;
                temp->anterior = NULL;
                free(temp);
            }else{
                temp->anterior->prox = temp->prox;
                temp->prox->anterior = temp->anterior;
                free(temp);
            }
        }
    }

}

int main(void){
    int i, quant, op, pos, valor;
    Lista* lis = criar_lista();
    scanf("%d", &quant);
    for(i=0; i<quant; i++){
        scanf("%d", &op);
        if(op == 0){
            scanf("%d", &pos);
            retirar(lis, pos);
        }else if(op == 1){
            scanf("%d%d", &pos, &valor);
            inserir(lis, pos, valor);
        }
    }
    imprimir(lis);

    destruir_lista(lis);
    return 0;
}