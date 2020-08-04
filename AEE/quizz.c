
#include <stdlib.h>
#include <stdio.h>

typedef struct no No;
typedef struct pilha Pilha;
struct no{
    int dado;
    No* prox;
};
struct pilha {
    No* inicio;
};

/* Cria a estrutura Pilha e retorna ela
 * Complexidade
 *   Melhor caso: O(1)
 *   Pior caso  : O(1)
 */
Pilha* criar_pilha(){
    Pilha* p = malloc(sizeof(Pilha));
    p->inicio = NULL;
    return p;
}

/* Libera a memoria alocada para todos os elementos da Pilha
 * e a propria Pilha.
 * Entrada
 *   p: uma pilha
 * Complexidade
 *   Melhor caso: O(n)
 *   Pior caso  : O(n)
 */
void destruir_pilha(Pilha* p){
    if(p->inicio != NULL){
        while(p->inicio != NULL){
            No* temp = p->inicio->prox;
            free(p->inicio);
            p->inicio = temp;
        }
    }
    free(p);
}

/* insere o elemento "elem" no topo da pilha "p"
 * Entrada
 *   p: uma pilha
 *   n: um valor inteiro
 * Complexidade
 *   Melhor caso: O(1)
 *   Pior caso  : O(1)
 */
void inserir_topo(Pilha* p, int elem){
	No* temp = p->inicio;
	No* novo = malloc(sizeof(No));
	novo->dado = elem;
	if(temp == NULL){
		p->inicio = novo;
		novo->prox = NULL;
	}else{
		novo->prox = p->inicio;
		p->inicio= novo;
	}
}

/* Remove um elemento do topo da pilha "p" e retorna esse valor
 * Entrada
 *   p: uma pilha
 * Complexidade
 *   Melhor caso: O(1)
 *   Pior caso  : O(1)
 */
int remover_topo(Pilha* p){
    int saida = p->inicio->dado;
    No* temp = p->inicio;
    p->inicio = p->inicio->prox;
    free(temp);
    return saida;
}

/* Para testar as funções:
void imprimir(Pilha* p){
    No* temp = p->inicio;
    while(temp != NULL){
        printf("%d ", temp->dado);
        temp = temp->prox;
    }
    printf("\n");
}
int main(void){
    int num;
    Pilha* p = criar_pilha();
    scanf("%d", &num);
    while(num != 0){
        inserir_topo(p, num);
        scanf("%d", &num);
    }
    imprimir(p);
    remover_topo(p);
    remover_topo(p);
    remover_topo(p);
    imprimir(p);
    destruir_pilha(p);
    return 0;
}
*/