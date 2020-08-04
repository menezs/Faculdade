#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "pilha.h"
#include "lista.h"

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

    scanf("%d\n", &mat);
    while(mat != -1){
        livro = ler_string();
        scanf("%c", &acao);
        if(acao == 'E'){
            emprestar(lis, mat, livro);
        }else if(acao == 'D'){
            devolver(lis, mat, livro);
        }
        scanf("%d\n", &mat);
        free(livro);
    }


    imprimir_lista(lis);

    destruir_lista(lis);
    
    return 0;
}