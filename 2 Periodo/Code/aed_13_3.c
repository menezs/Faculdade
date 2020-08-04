#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cria(int tam){
    char* palavra = malloc(tam);
    return palavra;
}
void realoca(char* palavra, int n){
    palavra = realloc(palavra, n);
}
void concatena(char* palavra1, int tam1, char* palavra2, int tam2){
    int i, j=0;
    for(i=tam1; i<(tam1+tam2); i++){
        palavra1[i]=palavra2[j];
        j++;
    }
}
void libera(char* palavra){
    free(palavra);
}

int main(void){
    int i=0, tam1 = 10, tam2 = 10;
    char temp;
    char* palavra1 = cria(tam1);
    char* palavra2 = cria(tam2);

    while( scanf("%c", &temp) != EOF && temp != '\n' ){
        
        palavra1[i] = temp;
        i++;
    }
    palavra1[i]='\0';
    if(i<tam1){
        tam1=i;
        realoca(palavra1, tam1);
    }

    i=0;
    while( scanf("%c", &temp) != EOF && temp != '\n' ){
        if(i>tam2){
            tam2 *= 2;
            realoca(palavra2, tam2);
        }
        palavra2[i] = temp;
        i++;
    }
    palavra2[i]='\0';
    if(i<tam2){
        tam2=i;
        realoca(palavra2, tam2);
    }
    realoca(palavra1, (tam1+tam2));
    concatena(palavra1, tam1, palavra2, tam2);
    printf("%s\n", palavra1);

    libera(palavra1);
    libera(palavra2);
    return 0;
}