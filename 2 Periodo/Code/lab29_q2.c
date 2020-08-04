#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
struct no{
	No* ant;
	No* prox;
	int dado;
};

typedef struct lista Lista;
struct lista{
	No* inicio;
	No* fim;	
};

Lista* criar_lista(){
	Lista* lis = malloc(sizeof(Lista));
	lis->inicio = NULL;
	lis->fim = NULL;
	return lis;
}
void destruir_lista(Lista* lis){
	if(lis->inicio != NULL){
		No* p = lis->inicio;
		while(p != NULL){
			No* temp = p->prox;
			free(p);
			p = temp;
		}
	}
	free(lis);
}
void inserir_lista(Lista* lis, int elem){
	No* p = lis->inicio;
	No* novo = malloc(sizeof(No));
	novo->dado = elem;
	if(p == NULL){
		lis->inicio= lis->fim = novo;
		novo->prox = novo->ant = NULL;
	}else{
		novo->prox = lis->inicio;
		lis->inicio->ant = novo;
		lis->inicio = novo;
		novo->ant = NULL;
	}
}
void imprimir(Lista* lis){
	if(lis->inicio != NULL){
		No* p =lis->fim;
		while(p != NULL){
			printf("%d ", p->dado);
			p = p->ant;
		}
		printf("\n");
	}
}
void removerNo_inicio(Lista* lis){
    No* temp = lis->fim->ant;
    free(lis->fim);
    lis->fim = temp;
    temp->prox = NULL;
}
void inserir_fim(Lista* lis, No* no){
    No* novo = malloc(sizeof(No));
    novo->dado = no->dado;
    lis->fim->prox = novo;
    novo->ant = lis->fim;
    novo->prox = NULL;
    lis->fim = novo;
}
void sublista_fim(Lista* lis, int num){
    No* p = lis->fim;
    while(p != NULL && p->dado != num){
        p = p->ant;
    }
    if(p->dado == num){
        while(p != NULL){
            inserir_lista(lis, p->dado);
            p =  p->prox;
        }
        p = lis->fim;
        while(p->dado != num){
            No* temp = p->ant;
            removerNo_inicio(lis);
            p = temp;
        }
        removerNo_inicio(lis);
    }
    
}

int main(void){
	int num, i;
	Lista* lis = criar_lista();
	scanf("%d", &num);
	for(i=1; i<=num; i++){
		inserir_lista(lis, i);
	}
    
	while(scanf("%d", &num) != EOF) {
		sublista_fim(lis, num);
	}
    imprimir(lis);

	destruir_lista(lis);
	return 0;
}