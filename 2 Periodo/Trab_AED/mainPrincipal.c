#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
* Chamada para os arquivos de interface do TAD
* #include "fila.h"
* #include "pilha.h"
* #include "lista.h"
* 
* Interface da Lista Principal, que contem os livros.
* Possui os protótipos de todas a funções e estruturas
* da Lista.
*/
typedef struct no No;
typedef struct lista Lista;
Lista* criar_lista();
void destruir_lista(Lista* lis);
void inserir_fim(Lista* lis);
void imprimir_lista(Lista* lis);
No* buscar_ano(Lista* lis, int x);
No* buscar_nome(Lista* lis, char* nome);
void emprestar(Lista* lis, int mat, char* nome);
void devolver(Lista* lis, int mat, char* nome);
void troca(Lista* lis, No* maior, No* menor);
void ordem_alfa(Lista* lis);

/*
* Interface da pilha que vai armazenar os Exemplares.
* Possui os prototipos de todas as funções e estruturas
* da Pilha.
*/
typedef struct pilha Pilha;
Pilha* pilha_cria();
void pilha_push(Pilha* p, int mat);
int pilha_pop(Pilha* p);
int pilha_vazia(Pilha* p);
void pilha_libera(Pilha* p);
void imprimir(Pilha* p);

/*
* Interfaca da Fila que vai armazenar a matricula dos Alunos
* que estão aguardando para emprestar o livro.
* Possui o prototipos de todas as funções e estruturas
* da Fila.
*/
typedef struct filano FilaNo;
typedef struct fila Fila;
Fila* fila_cria(void);
void fila_insere(Fila* f, int v);
int fila_retira(Fila* f);
int fila_vazia(Fila* f);
void fila_libera(Fila* f);
void fila_imprime(Fila* f);

/*
* Função auxiliar, para a leitura de Strings.
*/
char* ler_string(){
    int tam = 0;
    char letra;
    char* palavra = malloc(sizeof(char));
    scanf("%c", &letra);
    while (letra != '\n'){
        if(tam == 0){
            palavra[tam] = letra;
            tam++;
        }else{
            tam++;
            palavra = realloc(palavra, tam*sizeof(char));
            palavra[tam-1] = letra;
        }
        scanf("%c", &letra);
    }
    tam++;
    palavra = realloc(palavra, tam*sizeof(char));
    palavra[tam-1]='\0';

    return palavra;
}

int main(void){
    int x, i;
    char* livro;
    char acao;
    int mat;
    Lista* lis = criar_lista();

    scanf("%d", &x);
    for(i=0; i<x; i++){
        inserir_fim(lis);
    }
    ordem_alfa(lis);

    while(scanf("%d\n", &mat) != EOF){
        livro = ler_string();
        scanf("%c", &acao);
        if(acao == 'E'){
            emprestar(lis, mat, livro);
        }else if(acao == 'D'){
            devolver(lis, mat, livro);
        }
        free(livro);
    }


    imprimir_lista(lis);

    destruir_lista(lis);
    
    return 0;
}

//Funções da Lista de Livros.

/*
* Struct para o No da lista de livros,
* possui a quantidade de livros, ano, autor,
* Titulo, uma Pilha para os exemplares,
* uma Fila para os alunos que estão em espera
* e um ponteiro do Tipo No para o proximo Livro.
*/
struct no{
    int quantidade;
    int ano;
    char* autor;
    char* titulo;

    Pilha* pilha_ex;
    Fila* fila_alunos;
    No* prox;
};
/*
* Struct principal da lista,
* possui dos ponteiros do tipo No
* para o inicio e o fim da Lista.
*/
struct lista {
    No* inicio;
    No* fim;
};

/*
* Função que tem como retorno
* uma struct do tipo lista.
*/
Lista* criar_lista(){
    Lista* lis = malloc(sizeof(Lista));
    lis->inicio = lis->fim = NULL;
    return lis;
}

/*
* Função que que recebe a lista de livros
* e libera a memoria alocada.
*/
void destruir_lista(Lista* lis){
    No* p = lis->inicio;
    fila_libera(p->fila_alunos);

    while(p !=  NULL){
        pilha_libera(p->pilha_ex);
        p = p->prox;
    }
    if(lis->inicio != NULL){
        while(lis->inicio != NULL){
            No* temp = lis->inicio->prox;
            free(lis->inicio);
            lis->inicio = temp;
        }
    }
    free(lis);
}

/*
* Função auxiliar, recede a lista de livros
* e um determindado ano e retorna o No no qual
* será usado como referencia para adicionar o
* proximo No da lista.
*/
No* buscar_ano(Lista *lis, int x){
	No* atual = lis->inicio;
    No* saida = NULL;
	while (atual != NULL) {
		if (x >= atual->ano){
			saida = atual;
		}
		atual = atual->prox;
	}
    
	return saida;
}
/*
* Função auxiliar, usada para trocar a ordem dos livros que possuem
* o mesmo ano de publicação, seguindo a ordem alfabética,
* recebe como parametro a lista, um No do elemento que
* devera vir primero (menor) e um No para elemento que
* que vem depois (maior).
*/
void troca(Lista* lis, No* maior, No* menor){
    No* p = lis->inicio;
    
    if(maior == lis->inicio){
        maior->prox = menor->prox;
        menor->prox = maior;
        lis->inicio = menor;
    }else if(menor == lis->fim){
        while (p->prox != maior){
            p = p->prox;
        }
        p->prox = menor;
        maior->prox = menor->prox;
        menor->prox = maior;
        lis->fim = maior;
    }else{
        while (p->prox != maior){
            p = p->prox;
        }
        p->prox = menor;
        maior->prox = menor->prox;
        menor->prox = maior;
    }        
}
/*
* Função principal para ordenar de forma alfabética,
* recebe como parametro a lista de livros e caso existam
* livros com o mesmo ano de publicação faz a ordenação
* alfabética desses mesmos livros.
*/
void ordem_alfa(Lista* lis){
	int i=0;
    No* p = lis->inicio;
    while(p->prox != NULL){
        i=0;
        if(p->ano == p->prox->ano){
            while(p->autor[i] == p->prox->autor[i]){
                i++;
            }
            if(p->autor[i] > p->prox->autor[i]){
                troca(lis, p, p->prox);
                p = lis->inicio;
            }else{
                p = p->prox;
            }
        }else{
            p = p->prox;
        } 
    }
}
//Função que insere novos elementos na lista de Livros.
void inserir_fim(Lista* lis){
    char letra;
    int tam = 0;
    No* novo = malloc(sizeof(No));
    novo->fila_alunos = fila_cria();
    
    scanf("%d\n", &novo->ano);
    novo->autor = ler_string();
    novo->titulo = ler_string();
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
/*
* Função que imprime o ano, nome do autor,
* titulo do livro e, caso houver, a quantidade de livros
* e a matricula dos aulos que estão aguardando para emprestar.
*/
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
/*
* Função auxiliar, recebe como parametro a lista e 
* um ponteiro para uma string(titulo do livro) e, caso 
* exista, retorna o No desse livro.
*/
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
/*
* Função para empresta livros, recebe com parametro
* a lista, um número de matricula e um ponteiro para
* string(titulo do livro) e, caso o livro exista e ainda
* tenha exemplares o livro é emprestado, caso o livro exista
* e os exemplares estejam esgotados a matricula do aluno entra
* para a fila de espera.
*/
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
        if(fila_retira(p->fila_alunos)){
        	p->quantidade--;
        }
    }
}

//Funções da Pilha de Exemplares.
struct pilha {
    int tam;
    int uso;
    int* vet;
};

Pilha* pilha_cria(int tam){
    Pilha* p = malloc(sizeof(Pilha));
    p->uso = 0;
    p->tam = tam;
    p->vet = malloc(tam*sizeof(int));
    return p;
}
void pilha_push(Pilha* p, int mat){
    if(p->uso != p->tam){
        p->vet[p->uso]= mat;
        p->uso++;
    }
}
int pilha_pop(Pilha* p){
    int temp = p->vet[p->tam-1];
    p->tam--;
    p->uso--;
    return temp;
}
int pilha_vazia(Pilha* p){
    int saida = 0;
    if(p->tam > 0){
        saida = 1;
    }
    return saida;
}
void pilha_libera(Pilha* p){
    free(p->vet);
    free(p);
}
void imprimir(Pilha* p){
    int i;
    for(i=0; i<p->uso; i++){
        printf("%d\n", p->vet[i]);
    }
}
// Funções da Fila de Alunos.
struct filano {
    int matricula;
    FilaNo* prox;
};

struct fila {
    FilaNo* inicio;
    FilaNo* fim;
};

Fila* fila_cria(void){
    Fila* f = malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}

void fila_insere(Fila* f, int v){
    FilaNo* novo = malloc(sizeof(FilaNo));
    novo->matricula = v;
    if(f->inicio == NULL){
        f->inicio = f->fim = novo;
        novo->prox = NULL;
    }else{ 
        f->fim->prox = novo;
        f->fim = novo;
        novo->prox = NULL;
    }
}

int fila_retira(Fila* f){
    int saida = 0;
    if(f->inicio != NULL){
        FilaNo* temp = f->inicio;
        f->inicio = temp->prox;
        saida = 1;
        free(temp);
    }
    return saida;
}

int fila_vazia(Fila* f){
    int saida = 0;
    if(f->inicio != NULL){
        saida = 1;
    }
    return saida;
}

void fila_libera(Fila* f){
    FilaNo* p = f->inicio;
    while (p != NULL){
        FilaNo* temp = p->prox;
        free(p);
        p=temp;
    }
    free(f);
}
void fila_imprime(Fila* f){
    FilaNo* p = f->inicio;
    if(p == NULL){
        printf("fila vazia\n");
    }else{
        while (p!=NULL){
            printf("%d", p->matricula);
            p=p->prox;
            if(p!=NULL){
                printf(",");
            }
        }
        printf("\n");
    }
}
