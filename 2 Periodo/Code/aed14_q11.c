#include <stdio.h>
#include <stdlib.h>

typedef struct candidato TCandidato;
struct candidato{
	char operacao;
	int curso, matricula, nota;
	TCandidato *prox;
};

typedef struct lista TLista;
struct lista{
	int quant;
	TCandidato* inicio;
    TCandidato* final;
};

TLista* criarLista(){
	TLista* lista = malloc(sizeof(TLista));
	lista -> inicio = lista -> final = NULL;
	lista -> quant = 0;
	return lista;
}
void destruir_lista(TLista *lis){
    TCandidato* p = lis->inicio;
    while( p != lis->final){
        TCandidato* t = p;
        p = p->prox;
        free(t);
    }
    free(p);
    free(lis);
}
void inserir_fim(TLista* lis, char op){
    lis->quant++;
    TCandidato* novo = malloc(sizeof(TCandidato));
    novo->operacao = op;
    scanf("%d %d %d", &novo->curso, &novo->matricula, &novo->nota);
    if(lis->inicio == NULL){
        lis->inicio = novo;
        lis->final = novo;
        novo->prox = novo;
    }else{
        lis->final->prox = novo;
        novo->prox = lis->inicio;
        lis->final = novo;
    }

}
void inserir_inicio(TLista* lis, char op){
    TCandidato* novo = malloc(sizeof(TCandidato));
    novo->operacao = op;
    scanf("%d%d%d", &novo->curso, &novo->matricula, &novo->nota);
    if(lis->inicio == NULL){
        lis->inicio = novo;
        lis->final = novo;
        novo->prox = novo;
    }else{
        TCandidato* temp = lis->inicio;
        while (temp->operacao == op){
            temp = temp->prox;
        }
        novo->prox = temp->prox;
        temp->prox = novo;
    }
}
void inserir(TLista* lis, char op){
    TCandidato* novo = malloc(sizeof(TCandidato));
    novo->operacao = op;
    scanf("%d%d%d", &novo->curso, &novo->matricula, &novo->nota);
    if(lis->inicio == NULL){
        lis->inicio = novo;
        lis->final = novo;
        novo->prox = novo;
    }else{
        novo->prox = lis->inicio;
        lis->inicio = novo;
        lis->final->prox = novo;
    }

}
void lst_imprime(TLista* l){
    TCandidato* p = l->inicio;
    while (p != l->final){
        printf("%c ", p->operacao);
        printf("%d %d %d\n", p->curso, p->matricula, p->nota);
        p=p->prox;
    }
    printf("%c ", p->operacao);
    printf("%d %d %d\n", p->curso, p->matricula, p->nota);
}

int main(void){
    char op;
    TLista* lis = criarLista();
    scanf("%c", &op);
    while (op != 'F'){
        inserir_fim(lis, op);
        scanf("%c", &op);
    }
    lst_imprime(lis);

    destruir_lista(lis);
    return 0;
}