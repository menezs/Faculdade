#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "fila.h"
#include "pilha.h"

struct no{
    int quantidade;
    int ano;
    char* autor;
    char* titulo;

    Pilha* pilha_ex;
    Fila* fila_alunos;
    No* prox;
};
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
    No* p = lis->inicio;
    while(p !=  NULL){
        pilha_libera(p->pilha_ex);
        p = p->prox;
    }
    
    fila_libera(p->fila_alunos);

    if(lis->inicio != NULL){
        while(lis->inicio != NULL){
            No* temp = lis->inicio->prox;
            free(lis->inicio);
            lis->inicio = temp;
        }
    }
    free(lis);
}
No* buscar_ano(Lista *lis, int x){
	No *atual = lis->inicio;
    No* saida = NULL;
	while (atual != NULL) {
		if (x >= atual->ano) {
			saida = atual;
		}
		atual = atual->prox;
	}
    
	return saida;
}
void inserir_fim(Lista* lis){
    char letra;
    int tam = 0;
    No* novo = malloc(sizeof(No));
    novo->fila_alunos = fila_cria();
    
    scanf("%d\n", &novo->ano);
    // Ler o nome do autor!!
    novo->autor = malloc(sizeof(char));
    letra=getchar();
    while (letra != '\n'){
        if(tam == 0){
            novo->autor[tam] = letra;
            tam++;
        }else{
            tam++;
            novo->autor = realloc(novo->autor, tam*sizeof(char));
            novo->autor[tam-1] = letra;
        }
        letra=getchar();
    }
    tam++;
    novo->autor = realloc(novo->autor, tam*sizeof(char));
    novo->autor[tam-1]='\0';

    // Ler o Título!!
    tam=0;
    novo->titulo = malloc(sizeof(char));
    letra=getchar();
    while (letra != '\n'){
        if(tam == 0){
            novo->titulo[tam] = letra;
            tam++;
        }else{
            tam++;
            novo->titulo = realloc(novo->titulo, tam*sizeof(char));
            novo->titulo[tam-1] = letra;
        }
        letra=getchar();
    }
    tam++;
    novo->titulo = realloc(novo->titulo, tam*sizeof(char));
    novo->titulo[tam-1]='\0';

    scanf("%d", &novo->quantidade);
    novo->pilha_ex = pilha_cria(novo->quantidade);
    
    if(lis->inicio == NULL){
        lis->inicio = lis->fim = novo;
        novo->prox = NULL;
    }else{
        No* ref = buscar_ano(lis, novo->ano);
        if(ref == NULL){
            novo->prox = lis->inicio;
            lis->inicio = novo;
        }else if(lis->fim == ref){
            novo->prox = NULL;
            lis->fim->prox = novo;
            lis->fim = novo;
        }else{
            novo->prox = ref->prox;
            ref->prox = novo;
        }
    }
}
void imprimir_lista(Lista* lis){
    No* p = lis->inicio;
    while (p != NULL){
        printf("%d\n", p->ano);
        printf("%s\n", p->autor);
        printf("%s\n", p->titulo);
        if(p->quantidade == 0){
            printf("pilha vazia\n");
        }else{
            printf("%d\n", p->quantidade);
        }
        fila_imprime(p->fila_alunos);
        
        p = p->prox;
    }
}

No* buscar_nome(Lista* lis, char* nome){
    No* p = lis->inicio;
    while(p != NULL){
        if(strcmp(p->titulo, nome) == 0){
            break;
        }
        p = p->prox;
    }
    return p;
}

void emprestar(Lista* lis, int mat, char* nome){
    No* p = buscar_nome(lis, nome);
    if(p->quantidade != 0 && p != NULL){
        pilha_push(p->pilha_ex, mat);
        p->quantidade--;
    }else if(p->quantidade == 0 && p != NULL){
        fila_insere(p->fila_alunos, mat);
    }
}

void devolver(Lista* lis, int mat, char* nome){
    No* p = buscar_nome(lis, nome);
    if(p != NULL){
        p->quantidade++;
        pilha_pop(p->pilha_ex);
        fila_retira(p->fila_alunos);
    }
}


