
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct no No;
typedef struct pilha Pilha;
struct no{
    double dado;
    No* prox;
    No* ant;
};
struct pilha {
    No* inicio;
    No* fim;
};

Pilha* criar_pilha(){
    Pilha* p = malloc(sizeof(Pilha));
    p->inicio = p->fim = NULL;
    return p;
}

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

void inserir_topo(Pilha* p, double elem){
	No* novo = malloc(sizeof(No));
	novo->dado = elem;
	if(p->inicio == NULL){
		p->inicio = p->fim = novo;
		novo->prox = novo->ant = NULL;
	}else{
		novo->prox = p->inicio;
        p->inicio->ant = novo;
		p->inicio = novo;
        novo->ant = NULL;
	}
}

double remover_topo(Pilha* p){
    double saida = p->inicio->dado;
    if(p->inicio != NULL){
        if(p->inicio == p->fim){
            No* temp = p->inicio;
            p->inicio = p->fim = NULL;
            free(temp);
        }else{
            No* temp = p->inicio;
            p->inicio = temp->prox;
            p->inicio->ant = temp->prox = NULL;
            free(temp);
        }
    }
    return saida;
}

void imprimir_pilha(Pilha* p){
    No* temp = p->fim;
    while(temp != NULL){
        printf("%.2f\n", temp->dado);
        temp = temp->ant;
    }
}

int main(void){
	char elemento[8];
	int num_casos;
    Pilha* posfixa = criar_pilha();

	scanf("%d", &num_casos);

	while (num_casos > 0) {
		// Lê o próximo elemento
		scanf("%s", elemento);
		while (elemento[0] != '.') {
			if (isdigit(elemento[0])) {
				double operando = atof(elemento);
                inserir_topo(posfixa, operando);
				// É um operando
			}
			else {
				char operador = elemento[0];
                double primeiro, segundo;
                segundo = remover_topo(posfixa);
                primeiro = remover_topo(posfixa);
                
                if(operador == '-'){
                    inserir_topo(posfixa, (primeiro - segundo) );
                }else if(operador == '+'){
                    inserir_topo(posfixa, (primeiro + segundo) );
                }else if(operador == '*'){
                    inserir_topo(posfixa, (primeiro * segundo) );
                }else{
                    inserir_topo(posfixa, (primeiro / segundo) );
                }
				// É um operador (+, -, * ou /)
			}
			// Lê o próximo elemento (que pode ser um ponto final)
			scanf("%s", elemento);
		}
		// Fim da expressão
		num_casos--;
	}
    imprimir_pilha(posfixa);

    destruir_pilha(posfixa);
}
/*
int main(void){
    Pilha* teste = criar_pilha();
    int quant;
    double temp;

    scanf("%d", &quant);
    while(quant > 0){

        scanf("%lf", &temp);
        inserir_topo(teste, temp);
        quant--;
    }

    imprimir_pilha(teste);
    destruir_pilha(teste);
    return 0;
}
*/