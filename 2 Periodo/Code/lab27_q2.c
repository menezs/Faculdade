#include <stdio.h>
#include <stdlib.h>

/* Sugestao de estrutura de dados para guardar a lista de programa
 * e os programas. Voce pode alterar essa estrutura como quiser,
 * mas deve implementar uma lista circular encadeada.
 */
typedef struct programa Programa;
struct programa {
    char nome[81];
    int tempo;
    Programa *prox;
};

typedef struct lista Lista;
struct lista {
    Programa *inicio;
    Programa *fim;
};


/* Sugestao de funcao para criar uma lista. Voce pode
 * alterar, usar ou remover esta funcao.
 */
Lista *criar_lista(void){
	Lista *nova = malloc(sizeof *nova);
	nova->inicio = nova->fim = NULL;
	return nova;
}
void destruir_lista(Lista *lis){
    Programa* p = lis->inicio;
    while( p != lis->fim){
        Programa* t = p;
        p = p->prox;
        free(t);
    }
    free(p);
    free(lis);
}

/* Sugestao de funcao para ler a descricao de um programa e
 * retornar um novo no' para ele. Voce pode usar, modificar
 * ou remover esta funcao.
 */
void inserir_fim(Lista *lis){
    Programa* novo = malloc(sizeof(Programa));
    scanf("%80s", novo->nome);
    scanf("%d", &novo->tempo);

    if(lis->inicio == NULL){
        lis->inicio = novo;
        novo->prox = novo;
        lis->fim = novo;
    }else{
        novo->prox = lis->fim->prox;
        lis->fim->prox = novo;
        lis->fim = novo;
    }
}
void lst_imprime(Lista* l){
    Programa* p = l->inicio;
    if (p != NULL ) {
        do {
            printf("Nome = %s\n", p->nome);
            printf("Tempo = %d\n", p->tempo);
            p=p->prox;
            // printf("prox info = %d\n", p->info); //descomentar para ver o próximo elemento
        }while (p != l->inicio);
    }else {
        printf("lista vazia\n");
    }
}
void removerNo(Lista* lis, Programa* no){
    Programa* temp = lis->inicio;
    if(no->prox != no){
        if(temp == no){
            lis->inicio = no->prox;
            lis->fim->prox = no->prox;
            no->prox = NULL;
            free(no);
        }else if(no == lis->fim){
            while(temp->prox != no){
                temp = temp->prox;
            }
            temp->prox = lis->inicio;
            lis->fim = temp;
            no->prox = NULL;
            free(no);
        }else{
            while(temp->prox != no){
                temp = temp->prox;
            }
            temp->prox = no->prox;
            no->prox = NULL;
            free(no);
        }
    }else{
        lis->inicio = NULL;
        lis->fim = NULL;
        no->prox = NULL;
        free(no);
    }
}
void rodar_prog(Lista* lis, int cota){
    int cont = 0, tempo = 0;
    Programa* p = lis->inicio;
    while( p != NULL){
        if (cont < cota && (p->tempo - cont) != 0){
            cont++;
            tempo++;
            if( (p->tempo - cont) == 0){
                printf("%d us: %s finalizou\n", tempo, p->nome);
                if(lis->fim == p && lis->inicio == p){
                    removerNo(lis, p);
                }else{
                    Programa* temp = p->prox;
                    removerNo(lis, p);
                    p = temp;
                    cont = 0;
                }
            }
        }else{
            p->tempo = p->tempo - cont;
            p = p->prox;            
            cont = 0;
        }
        
    }
    if(p == NULL){
        printf("%d us: shutdown\n", tempo);
    }
    
}
int main(void){
    int i, cota, n;
    Lista* lis = criar_lista();
    scanf("%d%d", &cota, &n);
    for(i=0; i<n; i++){
        inserir_fim(lis);
    }
    rodar_prog(lis, cota);

    destruir_lista(lis);
    return 0;
}