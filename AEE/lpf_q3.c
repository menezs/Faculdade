#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define nomeA "Arbento"
#define nomeB "Berlina"
#define nomeC "Carlen"
#define nomeD "Drogenilson"
#define nomeE "Erdovaldo"
#define nomeF "Familiza"
#define nomeG "Guimliana"

typedef struct no No;
struct no {
    char dado[80];
    No* prox;
};
typedef struct fila Fila;
struct fila {
    int tam;
    No* inicio;
    No* fim;
};

Fila* fila_cria(void){
    Fila* f = malloc(sizeof(Fila));
    f->tam = 0;
    f->inicio = f->fim = NULL;
    return f;
}

void fila_insere(Fila* f, char* v){
    f->tam++;
    No* novo = malloc(sizeof(No));
    strcpy(novo->dado, v);
    if(f->inicio == NULL){
        f->inicio = f->fim = novo;
        novo->prox = NULL;
    }else{ 
        f->fim->prox = novo;
        f->fim = novo;
        novo->prox = NULL;
    }
}

void fila_retira(Fila* f){
    if(f->inicio != NULL){
        No* temp = f->inicio;
        f->inicio = temp->prox;
        free(temp);
    }
    f->tam--;
}

int fila_vazia(Fila* f){
    int saida = 0;
    if(f->inicio != NULL){
        saida = 1;
    }
    return saida;
}

void fila_libera(Fila* f){
    No* p = f->inicio;
    while (p != NULL){
        No* temp = p->prox;
        free(p);
        p=temp;
    }
    free(f);
}
void fila_imprime(Fila* f){
    No* p = f->inicio;
    while (p!=NULL){
        printf("%s\n", p->dado);
        p=p->prox;
    }
}
int confereOrdem(Fila* f, char* nome){
    No* temp = f->inicio;
    int b=1;
    while(temp != NULL){
        if(strcmp(nome, temp->dado) == 0){
            break;
        }else{
            b++;
        }
        temp = temp->prox;
    }
    if(b == f->tam){
        b=0;
    }
    return b;
}
void casoArbento(Fila* f){
    if(strcmp(nomeA, f->inicio->dado) == 0 &&  f->tam > 1){ 
        No* temp = f->inicio;
        f->inicio = temp->prox;
        temp->prox = f->inicio->prox;
        f->inicio->prox =temp;
    }else if(strcmp(nomeA, f->inicio->dado) == 0 &&  f->tam <= 1){ 
        No* temp = f->inicio;
        f->inicio = f->fim = NULL;
        free(temp);
    }
}
void casoBerlinaCarlen(Fila* f){
    No* temp = f->inicio;
    int b=confereOrdem(f, nomeB);
    int c=confereOrdem(f, nomeC);
    
    if(b<c && b > 0 && b <= f->tam){
        temp = f->inicio;
        if(strcmp(nomeC, temp->dado) == 0){
            f->inicio = temp->prox;
            free(temp);
        }else{
            while(temp->prox != NULL){
                if(strcmp(nomeC, temp->prox->dado) == 0 ){
                    No* excluir = temp->prox;
                    temp->prox = excluir->prox;
                    free(excluir);
                    break;
                }
                temp = temp->prox;
            }
        }
        
    }else if(c<b && c > 0 && c <= f->tam){
        temp = f->inicio;
        if(strcmp(nomeB, temp->dado) == 0){
            f->inicio = temp->prox;
            free(temp);
        }else{
            while(temp->prox != NULL){
                if(strcmp(nomeB, temp->prox->dado) == 0 ){
                    No* excluir = temp->prox;
                    temp->prox = excluir->prox;
                    free(excluir);
                    break;
                }
                temp = temp->prox;
            }
        }
        
    }   
}

void casoErdovaldoFamiliza(Fila* f){
    No* temp = f->inicio;
    int e = confereOrdem(f, nomeE);
    int fa = confereOrdem(f, nomeF);
    int i = 1;

    if(e<fa && e > 0 && e <= f->tam && fa>0 && fa<=f->tam){
        temp = f->inicio;
        if(strcmp(nomeE, temp->dado) == 0){
           strcpy(temp->dado, nomeF);
           fila_insere(f, nomeE);
            while (temp != NULL && i != (fa-1) ){
                i++;
                temp=temp->prox;    
            }
            if(strcmp(nomeF, temp->prox->dado) == 0){
                No* excluir = temp->prox;
                temp->prox = excluir->prox;
                excluir->prox = NULL;
                free(excluir);
            }
        }else{
            while(temp->prox != NULL){
                if(strcmp(nomeE, temp->prox->dado) == 0 ){
                    strcpy(temp->prox->dado, nomeF);
                    fila_insere(f, nomeE);
                    No* excluir = temp->prox;
                    temp->prox = excluir->prox;
                    free(excluir);
                    break;
                }
                temp = temp->prox;
            }
        }
    }   
}
void casoDrogenilsonGuimliana(Fila* f){
    No* temp = f->inicio;
    int d = confereOrdem(f, nomeD);
    int g = confereOrdem(f, nomeG);
    printf("d: %d tam: %d\n", d, f->tam);

    if(g<d && (d > 0 && d <= f->tam) && (g > 0 && g<=f->tam) ){
        temp = f->inicio;
        if(strcmp(nomeG, temp->dado) == 0){
            f->inicio = temp->prox;
            free(temp);
            fila_insere(f, nomeG);
        }else{
            while(temp->prox != NULL){
                if(strcmp(nomeG, temp->prox->dado) == 0 ){
                    No* excluir = temp->prox;
                    temp->prox = excluir->prox;
                    free(excluir);
                    break;
                }
                temp = temp->prox;
            }
            fila_insere(f, nomeG);
        }
        
    }else if(d == 0){
        temp = f->inicio;
        if(strcmp(nomeG, temp->dado) == 0){
            f->inicio = temp->prox;
            free(temp);
        }else{
            while(temp->prox != NULL){
                if(strcmp(nomeG, temp->prox->dado) == 0 ){
                    No* excluir = temp->prox;
                    temp->prox = excluir->prox;
                    free(excluir);
                    break;
                }
                temp = temp->prox;
            }
        }
    }
}
void organiza_fila(Fila* f){

    casoBerlinaCarlen(f);
    casoErdovaldoFamiliza(f);
    casoDrogenilsonGuimliana(f);
    casoArbento(f);
}

int main(void){
    Fila* bandeijao = fila_cria();
    char nome[80];
    
    scanf("%s", nome);
    while( strcmp(nome, "0")!= 0){
        fila_insere(bandeijao, nome);
        scanf("%s", nome);
    }
    organiza_fila(bandeijao);
    fila_imprime(bandeijao);

    fila_libera(bandeijao);
    return 0;
}