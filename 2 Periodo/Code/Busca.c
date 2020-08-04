#include <stdio.h>
#include <stdbool.h>
int patrono(char *palavra, char* frase){
	int i=0, anterior, j=0, cont;
	int exit=0;
	bool eh=true;
	while(palavra[i] != '\0'){
		cont=i;
		i++;
	}
	cont++;
	i=0;
	while(frase[i] != '\0' && eh){
		j=0;
		if(frase[i] == palavra[j]){
			anterior=i;
			while(frase[i] == palavra[j]){
				i++;
				j++;
			}
			if(j != cont){
				i=anterior+1;
			}else{
				printf("%d\n", j);
				exit=1;
				eh=false;
			}
		}else{
			i++;
		}
		
	}
	
	return exit;
}
int main(){
	char palavra[201];
	char frase[201];
	scanf("%s\n", palavra);
	fgets(frase, 201, stdin);
	
	if( ( patrono(palavra, frase) ) == 1 ){
		printf("o texto fala sobre patronos\n");
	}else{
		printf("o texto nao fala sobre patronos\n");
	}
	return 0;
}