#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no No;
struct no{
    char dado[100];
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
void inserir_fim(Lista* lis, char* elem){
    No* novo = malloc(sizeof(No));
    strcpy(novo->dado, elem);

    if(lis->inicio == NULL){
        lis->inicio = lis->fim = novo;
        novo->prox = NULL;
    }else{
        lis->fim->prox = novo;
        novo->prox = NULL;
        lis->fim = novo;
    }
}
void imprimir_lista(Lista* lis){
    No* p = lis->inicio;
    while (p != NULL){
        printf("%s\n", p->dado);
        p = p->prox;
    }
}
void trocar(Lista* lis, No* ant, No* prox){
    char temp[100];
    strcpy(temp, ant->dado);
    strcpy(ant->dado, prox->dado);
    strcpy(prox->dado, temp);
}
No* acharMenor(No* comeco){
    int i=0;
    No* temp = comeco->prox;
    No* menor = comeco;

    while(temp != NULL){
        if(temp->dado[i] < menor->dado[i]){
            menor = temp;
            temp=temp->prox;
            i=0;
        }else if( temp->dado[i] == menor->dado[i]){
            if(temp->dado[i] == '\0'){
                temp=temp->prox;
                i=0;
            }else{
                i++;
            }
        }else{
            temp=temp->prox;
            i=0;
        }
       
    }
    return menor;
}
void insertionSort(Lista* lis){
    No* temp = lis->inicio;
    No* menor;
    while (temp != NULL){
        menor =  acharMenor(temp);
        trocar(lis, temp, menor);
        temp = temp->prox;
    }
    
}

int main(void){
    Lista* lis = criar_lista();
    char palavra[100];

    while(scanf("%s", palavra) != EOF){
        inserir_fim(lis, palavra);
    }
    insertionSort(lis);
    imprimir_lista(lis);

    destruir_lista(lis);
    return 0;
}