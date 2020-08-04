#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* readline(void){
	int tam = 10, cont=0;
	char letra;
	char* frase = malloc(tam);
	while( scanf("%c", &letra) != EOF && letra != '\n'){
		if(cont == tam){
			tam *= 2;
			frase = realloc(frase, tam);
		}
		frase[cont] = letra;
		cont++;
	}
	frase[cont] = '\0';
	if(cont < tam){
		frase = realloc(frase, cont);
	}
	
	return frase;
}
int main(void){
	int tam;
	char *frase = readline();
	tam = strlen(frase);
    tam--;
	while(tam >= 0){
		printf("%c", frase[tam]);
		tam--;
	}
	printf("\n");
	
	return 0;
}