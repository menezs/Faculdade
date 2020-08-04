#include <stdio.h>

int posalfa(int c){
	int resul = c - 'a';
	return resul;
}

void enumerar_letras(char *str, int *bins){
	int indice, i=0;
	while(str[i] != 0){
		indice = posalfa(str[i]);
		bins[indice]++;
		i++;
	}
}

int vetores_iguais(int n, int a[], int b[]){
	int result=1, i;
	for(i=0; i<n; i++){
		if(a[i] != b[i]){
			result=0;
		}
	}
	return result;
}

int main(void){
	int vet1[26], vet2[26], i=0;
	char palavra1[64], palavra2[64];
	
	while( (scanf("%s %s", palavra1, palavra2) )!= EOF ){
		for(i=0; i<26; i++){
			vet1[i]=0;
		}
		for(i=0; i<26; i++){
			vet2[i]=0;
		}

		enumerar_letras(palavra1, vet1);
		for(i=0; i<26; i++){
			printf("%d ", vet1[i]);
		}
		printf("\n");
		enumerar_letras(palavra2, vet2);
		for(i=0; i<26; i++){
			printf("%d ", vet2[i]);
		}
		printf("\n");


		if(vetores_iguais(26, vet1, vet2) == 1){
			printf("%s eh anagrama de %s\n", palavra1, palavra2);
		}else{
			printf("%s nao eh anagrama de %s\n", palavra1, palavra2);
		}
	}
	return 0;
}

