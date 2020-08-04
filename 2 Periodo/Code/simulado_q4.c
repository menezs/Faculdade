#include <stdio.h>
#include <stdlib.h>
typedef struct no No;
struct no {
	int dado;
	No* prox;
};
typedef struct lista Lista;
struct lista{
	No* inicio;
	No* fim;
};
Lista* criar_lista(){
	Lista* l = malloc(sizeof(Lista));
	l->inicio = l->fim = NULL;
	return l;
}

void inserir_final(Lista* l, int n){
	No* novo = malloc(sizeof(No));
	novo->dado = n;
	if(l->fim == NULL){
		l->inicio = l->fim = novo;
		novo->prox = novo;
	}else{
		l->fim->prox = novo;
		novo->prox = l->inicio;
        l->fim = novo;
	}
}

void inserir_inicio(Lista* l, int n){
	No* novo = malloc(sizeof(No));
	novo->dado = n;
	if(l->inicio == NULL){
		l->inicio = l->fim = novo;
		novo->prox = novo;
	}else{
		novo->prox = l->inicio;
		l->inicio = novo;
		l->fim->prox = novo;
	}
}
void liberar_lista(Lista* l){
	No* p = l->inicio;
	while( p != l->fim){
		No* temp = p->prox;
		free(p);
		p = temp;
	}
	free(p);
	free(l);
}
No* procurar_menor(Lista* l){
	No* menorNo = NULL;
	int menor;
	if(l->inicio!=NULL){
		No* p = l->inicio;
		menor = p->dado;
        p = p->prox;
		while(p!=l->inicio){
			if(p->dado < menor){
				menorNo = p;
				menor = p->dado;
			}
			p = p->prox;
		}
		
	}
	
	return menorNo;
}
void trocar(Lista* l){
	No* menor = procurar_menor(l);
    if(menor != NULL && menor != l->inicio){
        No* p = l->inicio;
        while(p->prox != menor){
            p = p->prox;
        }
        l->fim = p;
        l->inicio = menor;
	}
	
}
void remover(Lista* l){
	int ant;
	ant = l->inicio->dado;
	while(l->inicio != NULL && ant <= l->inicio->dado){
        if(l->fim == l->inicio){
            printf("%d ", l->inicio->dado);
            free(l->inicio);
            l->fim = l->inicio = NULL;
        }else{
            No* p = l->inicio;
            l->inicio = p->prox;
            l->fim->prox = p->prox;
            ant = l->inicio->dado;
            printf("%d ", p->dado);
            free(p);
        }
	}
}
void imprimir(Lista* l){
	No* p = l->inicio;
	while(p!=l->fim){
		printf("%d ", p->dado);
		p = p->prox;
	}
    printf("%d\n", p->dado);
}
int main(void){
	int num;
	Lista* l = criar_lista();

    scanf("%d", &num);
	while(num != -1){
		inserir_final(l, num);
        scanf("%d", &num);
	}
	while(l->inicio != NULL){
		trocar(l);
		remover(l);
	}
    
	liberar_lista(l);
	
	return 0;
}