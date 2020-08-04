#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;
struct aluno {
	char nome[81]; // nome
	float p1, p2, p3; // notas
};

Aluno* vet_cria(){
	Aluno* novo = malloc(sizeof(Aluno));
	if(novo == NULL){
		exit(1);
	}
	return novo;
}
void libera(Aluno* tab){
	free(tab);
}
Aluno* realoca(int n, Aluno* tab){
	tab = realloc(tab, n*sizeof(Aluno));
	if(tab == NULL){
		exit(1);
	}
    return tab;
} 

void imprime(Aluno* tab, int n){
	int i;
	for(i=0; i<n; i++){
		printf("Nome: %s\n", tab[i].nome);
		printf("P1: %.1f\n", tab[i].p1);
		printf("P2: %.1f\n", tab[i].p2);
		printf("P3: %.1f\n", tab[i].p3);
	}
}

int main(void){
	int i=1;
	char nome[81];
	Aluno* tab = vet_cria();
    scanf("%s\n", nome);
    scanf("%f%f%f", &tab[0].p1, &tab[0].p2, &tab[0].p3);
	strcpy(tab[0].nome, nome);

	while(scanf("%s\n", nome) != EOF){
		i++;
		tab = realoca(i, tab);
        scanf("%f%f%f", &tab[i-1].p1, &tab[i-1].p2, &tab[i-1].p3);
        strcpy(tab[i-1].nome, nome);
	}
	imprime(tab, i);

	libera(tab);
	return 0;
}