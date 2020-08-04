#include <stdio.h>
#include <stdlib.h>

/* Estrutura de dados para os nos da lista. Nao altere.
 */
typedef struct no No;
struct no{
    int dado;
    No *prox;
};

/* Estrutura de dados para uma lista encaeada. Nao altere.
 */
typedef struct lista Lista;
struct lista
{
    No *inicio;
    No *fim;
};

/* Prototipos das funcoes que voce deve implementar. Voce pode
 * modificar os NOMES dos parametros. Nao altere os TIPOS
 * dos parametros, nem dos retornos das funcoes!
 */

/* Cria uma lista circular encadeada vazia. Tanto "inicio" quanto
 * "fim" apontam para NULL.
 */
Lista *criar_lista(void){
    Lista* nova = malloc(sizeof(Lista));
    nova->inicio = NULL;
    nova->fim = NULL;
    return nova;
}


/* Libera memoria de uma lista. Deve remover todos os nos e
 * tambem a memoria para a estrutura da lista.
 */
void destruir_lista(Lista *lis){
    No* p = lis->inicio;
    while( p != lis->fim){
        No* t = p;
        p = p->prox;
        free(t);
    }
    free(p);
    free(lis);
}

/* Procura por um elemento na lista. Se o elemento for
 * encontrado, retorna um ponteiro parao no' que o contem. Caso
 * contrario, retorna NULL.
 */
No* buscar_elem(Lista *lis, int elem){
    No* p = lis->inicio;
    while (  p != lis->fim && p->dado != elem ){
        p = p->prox;
    }
    if(p->dado != elem){
        p = NULL;
    }
    return p;
}

/* Procura por um no' em uma certa posicao da lista. Assuma que o
 * primeiro no' esta' na posicao zero e que cada no' tem uma unica
 * posicao. Se a posicao passada para a funcao for invalida, retorne
 * NULL. Caso contrario, retorne um ponteiro para o no'
 */
No *buscar_pos(Lista *lis, int pos){
	int cont = 0;
	No* p = lis->inicio;
    while( p != lis->fim && cont != pos ){
        p = p->prox;
        cont++;
    }
    if(cont != pos){
        p = NULL;
    }
    return p;
}

/* Insere um elemento no comeco da lista. Lembre-se de atualizar o
 * ultimo no' da lisa para que ela continue sendo circular. Use o
 * ponteiro "fim", contido na estrutura da lista, para nao precisar
 * percorrer toda a lista em busca do fim.
 */
void inserir_fim(Lista *lis, int elem){
    No* novo = malloc(sizeof(No));
    novo->dado = elem;
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

/* Cria um novo no' e o insere apos um no de referencia. Esse
 * no de referencia deve ser obtido com ajuda da funcao
 * buscar_elem().
 *
 * Se o no de referencia for o ultimo da lista, o novo no' devera
 * ser inserido no fim e o ponteiro "fim" devera' ser atualizado
 */
void inserir_apos(Lista *lis, No *ref, int elem){
    No* p = buscar_elem(lis, ref->dado);
 
    if(p != NULL){
        No* saida = malloc(sizeof(No));
        saida->dado = elem;
        if(p == lis->fim){
            inserir_fim(lis, elem);
        }else{
            saida->prox = p->prox;
            p->prox = saida;
        }
    }
}

void lst_imprime(Lista* l){
    No* p = l->inicio;
    if (p != NULL ) {
        do {
            printf("info = %d\n", p->dado);
            p=p->prox;
            // printf("prox info = %d\n", p->info); //descomentar para ver o próximo elemento
        }while (p != l->inicio);
    }else {
        printf("lista vazia\n");
    }
}


int main(void){
    int num, x, y;
    Lista* l = criar_lista();
    scanf("%d", &num);
    while( num >= 0){
        inserir_fim(l, num);
        scanf("%d", &num);
    }
    //lst_imprime(l);
    scanf("%d%d", &x, &y);
    while( x != -1 && y != -1 ){
        No* temp = buscar_elem(l, x);
        if(temp != NULL){
            inserir_apos(l, temp, y);
        }
        scanf("%d%d", &x, &y);
    }
    //lst_imprime(l);
    
    while( scanf("%d", &num) != EOF ){
        No* p = buscar_pos(l, num);
        if(num<0 || p==NULL){
            printf("invalido\n");
        }else{
            printf("%d\n", p->dado);
        }
    }
    

    destruir_lista(l);
    return 0;
}