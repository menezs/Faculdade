#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
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
void inserir_inicio(Lista* lis, int elem){
    No* novo = malloc(sizeof(No));
    novo->dado = elem;

    if(lis->inicio == NULL){
        lis->inicio = lis->fim = novo;
        novo->prox = NULL;
    }else{
        novo->prox = lis->inicio;
        lis->inicio = novo;
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
void remover_all_elem(Lista* lis){
    No* temp = lis->inicio;
    while (lis->inicio != NULL){
        lis->inicio =  temp->prox;
        free(temp);
        temp = lis->inicio;
    }
    lis->inicio = lis->fim = NULL;
    
} 
int distanciaCasas(Lista* lis){
    No* temp = lis->inicio;
    int ret, prim;
    if(temp->prox != NULL){
        prim = temp->dado;
        while(temp->dado == prim){
            temp = temp->prox;
        }
        ret = prim - temp->dado;
    }else{
        ret = temp->dado;
    }
    return ret;
}
int distCasaGus(Lista* lis){
    int dCasas = distanciaCasas(lis);
    No* temp = lis->inicio;
    int aux, ret = 0;
    aux = temp->dado;
    if(temp->prox != NULL){
        while(temp != NULL){
            if(temp->dado == aux){
                temp = temp->prox;
            }else{
                aux = temp->dado;
                ret += dCasas;
                temp = temp->prox;
            }
        }
    }else{
        ret = temp->dado;
    }
    return ret;
}

int main(void){
    Lista* lis = criar_lista();
    int i, j, casos, quantos, num, res;

    scanf("%d", &casos);
    for(i=0; i<casos; i++){
        scanf("%d", &quantos);
        for(j=0; j<quantos; j++){
            scanf("%d", &num);
            inserir_inicio(lis, num);
        }
        res = distCasaGus(lis);
        printf("%d\n", res);
        remover_all_elem(lis);
    }
    destruir_lista(lis);
    return 0;
}