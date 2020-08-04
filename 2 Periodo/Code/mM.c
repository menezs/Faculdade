#include <stdio.h>
#include <ctype.h>
#define MAX 81

int strequal(char palavra[MAX]){
	char chave[] = "cervo";
	int saida = 0;
	int i=0;
	char resp[MAX];
	while(palavra[i]!=0){
		resp[i]=tolower(palavra[i]);
		i++;
	}
	resp[i]=0;
	i=0;
	while(resp[i]!=0 && saida == 0){
		if(resp[i]!=chave[i]){
			saida=1;
		}
		i++;
	}
	return saida;
}

int main(void){
	char palavra[MAX];
	scanf("%s", palavra);
	if( strequal(palavra) == 0){
		printf("cervo eh patrono do Harry Potter\n");
	}else{
		printf("%s nao eh patrono do Harry Potter\n", palavra);
	}
	
	return 0;
}