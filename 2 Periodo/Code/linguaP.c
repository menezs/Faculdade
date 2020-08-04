#include <stdio.h>
#include <ctype.h>
#define MAX 101

void lingua_p(char *frase){
	int i=0;
	while(frase[i] != 0){
		frase[i]=tolower(frase[i]);
		i++;
	}
	i=0;
	while(frase[i] != 0){
		if(frase[i] != 'a' && frase[i] != 'e' && frase[i] != 'i' && frase[i] != 'o' && frase[i] != 'u' && frase[i] != ' '){
			frase[i] = 'p';
		}
		i++;
	}
}

int main(void){
	int i=0;
	char frase[MAX];
	scanf("%c", &frase[i]);
	while(frase[i] != '\n'){
		i++;
		scanf("%c", &frase[i]);
	}
	frase[i]=0;
	lingua_p(frase);
	printf("%s\n", frase);
	return 0;
}