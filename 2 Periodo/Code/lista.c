#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct no No;
struct no {
	int dado;
	No *prox;
};

typedef struct lista Lista;
struct lista {
	int tamanho;
	No *inicio;
};

Lista *criar_lista(void){
	Lista *nova = malloc(sizeof *nova);
	assert(nova != NULL);

	nova->tamanho = 0;
	nova->inicio = NULL;

	return nova;
}

void destruir_lista(Lista *lis){
	No *atual = lis->inicio;
	while (atual != NULL) {
		No *prox = atual->prox;
		free(atual);
		atual = prox;
	}

	free(lis);
}

No* buscar_elem(Lista *lis, int elem){
	No *atual = lis->inicio;

	while (atual != NULL) {
		if (atual->dado == elem) {
			return atual;
		}
		atual = atual->prox;
	}
	return NULL;
}

int imprimir(No* parte){
	int num;
	if(parte->prox == NULL){
		num = parte->dado;
	}else{
		No* p = parte->prox;
		num = imprimir(p);
		printf("%d ", num);
		num = parte->dado;
	}

	return num;
}
void imprimir_certo(Lista *lis){
	No *atual;
	if (lis->tamanho > 0) {
		atual = lis->inicio;
		printf("%d ", imprimir(atual));
		printf("\n");
	}
}

void inserir_inicio(Lista *lis, int elem){
	No* p = malloc(sizeof(No));
    p->prox = lis->inicio;
    lis->inicio = p;
    p->dado = elem;
    lis->tamanho += 1;
}
void inserir_apos(Lista *lis, No *ref, int elem){
    if(ref == NULL){
        inserir_inicio(lis, elem);
    }else{
        No* p = malloc(sizeof(No));
        p->dado = elem;
        p->prox = ref->prox;
        ref->prox = p;
    }

}
int ultimo(Lista* l){
	No* p = l->inicio;
	int saida;
	while( p != NULL){
		saida = p->dado;
		p = p->prox;
	}
	return saida;
}

void imprimir_inverso(Lista *lis){
	No *atual;
	if (lis->tamanho > 0) {
		atual = lis->inicio;
		while (atual != NULL) {
			printf("%d ", atual->dado);
			atual = atual->prox;
		}
	}
}

void concatena(Lista* l1, Lista* l2){
	int i=0;
	No* p = l1->inicio;
	No* ant = NULL;
	while( p != NULL){
		ant = p;
		p = p->prox;
	}
	p = l2->inicio;
	while( i<l2->tamanho ){
		inserir_apos(l1, ant, p->dado);
		ant = ant->prox;
		p = p->prox;
		i++;
	}
	destruir_lista(l2);
}
Lista* separa(Lista *l, int x){
	No* p = l->inicio;
	Lista* saida = criar_lista();
	while(p->dado != x){
		inserir_inicio(saida, p->dado);
		p = p->prox;
	}
	No* prox = l->inicio;
	p = l->inicio;
	while(p->dado != x){
		l->inicio = p->prox;
		prox = p;
		p = p->prox;
		 
		prox->prox = NULL;
		free(prox);
	}
	
	return saida;
}

int main(void){
	int tam, num,temp, i;
	Lista* l1 = criar_lista();
	
	scanf("%d%d", &tam, &num);
	for(i=0; i<tam; i++){
		scanf("%d", &temp);
		inserir_inicio(l1, temp);
	}
	Lista* l2 = separa(l1, num);
	imprimir_certo(l1);
	imprimir_inverso(l2);

	destruir_lista(l1);
	destruir_lista(l2);
	return 0;
}

