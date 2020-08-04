#include <stdlib.h>
#include <stdio.h>

#include "pilha.h"

struct pilha {
    int tam;
    char* vet;
};

Pilha* pilha_cria(){
    Pilha* p = malloc(sizeof(Pilha));
    p->tam = 0;
    p->vet = malloc(sizeof(char));
    return p;
}
void pilha_push(Pilha* p, char v){

    if(p->tam == 0){
        p->vet[0] = v;
        p->tam++;
    }else{
        p->tam++;
        p->vet = realloc(p->vet, p->tam*sizeof(char));
        p->vet[p->tam-1] = v;
    }
}
char pilha_pop(Pilha* p){
    char temp = p->vet[p->tam-1];
    p->tam--;
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
    printf("%s\n", p->vet);
    //printf("%.2f\n", p->vet[0]);
    /*
    int i;
    for(i=(p->tam-1); i>=0; i--){
        printf("%.1f\n", p->vet[i]);
    }
    */
}
void concatena_pilhas(Pilha* p1, Pilha* p2){
    int cont = 0;
    int i, comeco = p1->tam, final = (p1->tam+p2->tam);
    for(i=comeco; i<final; i++){
        pilha_push(p1, p2->vet[cont]);
        cont++;
    }

}
char confere(Pilha* p){
    char saida='S';
    int i;
    int col = 0, cha = 0, par = 0, cont;

    for(i=0; i<p->tam; i++){
        if(p->vet[i] == '(' || p->vet[i] == ')'){
            par++;
        }else if(p->vet[i] == '[' || p->vet[i] == ']'){
            col++;
        }else if(p->vet[i] == '{' || p->vet[i] == '}'){
            cha++;
        }else{
            p->vet[i]='0';
        }
    }
    
    if(par%2 == 0 && col%2 == 0 && cha%2 == 0){
        while((col!=0 || par!=0 || cha!=0) && saida=='S'){
            if(par%2 == 0 && par!=0){
                for(i=0; i<p->tam; i++){
                    if(p->vet[i]=='('){
                        cont = i;
                        while(p->vet[cont]!=')' && p->vet[cont]!='\0'){
                            cont++;
                        }
                        if(p->vet[cont]==')'){
                            par -= 2;
                        }else{
                            par -= 1;
                            saida='N';
                        }
                    }
                }
            }
            if(col%2 == 0 && col!=0){
                for(i=0; i<p->tam; i++){
                    if(p->vet[i]=='['){
                        cont = i;
                        while(p->vet[cont]!=']' && p->vet[cont]!='\0'){
                            cont++;
                        }
                        if(p->vet[cont]==']'){
                            col -= 2;
                        }else{
                            col -= 1;
                            saida='N';
                        }
                    }
                }
            }
            if(cha%2 == 0 && cha!=0){
                for(i=0; i<p->tam; i++){
                    if(p->vet[i]=='{'){
                        cont = i+1;
                        while(p->vet[cont]!='}' && p->vet[cont]!='\0'){
                            cont++;
                        }
                        if(p->vet[cont]=='}'){
                            cha -= 2;
                        }else{
                            cha -= 1;
                            saida='N';
                        }
                    }
                }
            }
        }
        /*
        if(par==0 && col==0 && cha==0 && saida != 'N'){
            saida = 'S';
        }
        */
    }else{
        saida='N';
    }

    return saida;
}