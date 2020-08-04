#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10

int main(void){
    int i=0, j=3, k=1;
    char* patrono = malloc(k*MAX*sizeof(char));
    if(patrono == NULL){
        exit(1);
    }
    char* frase = malloc((j*MAX)*sizeof(char));
    if(frase == NULL){
        exit(1);
    }

    while( (patrono[i]=getchar()) != '\n'){
        i++;
        if(i == (k*MAX)){
            k++;
            patrono = realloc(patrono, k*MAX*sizeof(char));
            if(patrono == NULL){
                exit(1);
            }
        }
    }
    patrono[i]=0;

    i=0;
    while( (frase[i]=getchar()) != '\n'){
        i++;
        if(i == (j*MAX)){
            j=j+3;
            frase = realloc(frase, j*MAX*sizeof(char));
            if(frase == NULL){
                exit(1);
            }
        }
    }
    frase[i]=0;
    
    if(strstr(frase, patrono) == NULL){
        printf("o texto nao fala sobre patronos\n");
    }else{
        printf("o texto fala sobre patronos\n");
    }
    
    free(patrono);
    free(frase);
    return 0;
}