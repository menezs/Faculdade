#include <stdio.h>
#include <stdlib.h>
typedef struct vetor Vetor;
struct vetor{
    int tam;
    int* v;
};
Vetor* vet_cria(int n){
    Vetor* vet = malloc(sizeof(Vetor));
    vet->tam = n;
    vet->v = malloc(n*sizeof(int));
    if(vet->v == NULL){
        exit(1);
    }
    return vet;
}
void libera(Vetor* vet){
    free(vet->v);
    free(vet);
}
void inserir(Vetor* vet, int w, int v){
    int temp, ant,  i;
    if( w>=0 && w<=vet->tam){
        vet->v = realloc(vet->v, (vet->tam*sizeof(int))+sizeof(int));
        vet->tam += 1;
        for(i=w; i<vet->tam+1; i++){
            if(i==w){
                temp = vet->v[i];
                vet->v[i] = v;
            }else{
                ant = vet->v[i];
                vet->v[i] = temp;
                temp = ant;
            }
        }
    }else if(w>vet->tam){
        vet->v = realloc(vet->v, w*sizeof(int));
        for(i=w; i>=vet->tam; i--){
            if(i==w-1){
                vet->v[i] = v;
            }else{
                vet->v[i] = 0;
            }
        }
        vet->tam = w;
    }
}
void remover(Vetor* vet, int w){
    int i;
    if(w<vet->tam){
        for(i=w; i<vet->tam-1; i++){
            vet->v[i] = vet->v[i+1];
        }
        vet->v = realloc(vet->v, (vet->tam*sizeof(int))-sizeof(int));
        vet->tam -=1;
    }
    
}

void imprime(Vetor* vet){
    int i;
    for(i=0; i<vet->tam; i++){
        printf("%d ", vet->v[i]);
    }
    printf("\n");
}
int main(void){
    int n, rep, op, w, v;
    int i;
    scanf("%d", &n);
    Vetor* vet = vet_cria(n);
    for(i=0; i<n; i++){
        scanf("%d", &vet->v[i]);
    }
    scanf("%d", &rep);
    for(i=0; i<rep; i++){
        scanf("%d", &op);
        if(op == 1){
            scanf("%d%d", &w, &v);
            inserir(vet, w, v);
            //imprime(vet);
        }else if(op == 0){
            scanf("%d", &w);
            remover(vet, w);
            //imprime(vet);
        }
    }
    imprime(vet);
    libera(vet);
    return 0;
}