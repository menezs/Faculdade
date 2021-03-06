#include <stdio.h>
#include <string.h>

struct Musica {
	char autor[101];
	char titulo[101];
	char arquivo[101];
	int duracao;
};

int repetidos(int *q, int *vet){
	int i, temp;
	
	for(i=1; i<*q; i++){
		temp=vet[i];
		if(temp == vet[i+1]){
			vet[i]=0;
		}
	}
	temp=0;
	for(i=1; i<=*q; i++){
		if(vet[i] != 0){
			temp++;
		}
	}
	return temp;

}
int buscar_musica(struct Musica *base, int tam_base, struct Musica *lista, int tam_lista){
	int i = 0, indice = 0;
	for(i=1; i<=tam_lista; i++){
		for(j=1; i<tam_base; j++){
			if(strcmp(base[i].autor, lista[i].autor) == 0){
				if(strcmp(base[i].titulo, lita[i].titulo) == 0){
					indice = i;
				}
			}
		}
	}

	return indice;
}

int main(void){
	int i, j=1, n, q, quantidade;
	int min=0, seg=0, tempo=0;
	char autor[101], titulo[101];
	//struct Musica lista[100];

	//preencher a base
	scanf("%d\n", &n);
	struct Musica base[n];
	for(i=1; i<=n; i++){
		scanf("%s\n", base[i].autor);
		scanf("%s\n", base[i].titulo);
		scanf("%s\n", base[i].arquivo);
		scanf("%d", &base[i].duracao);
	}
	//a lista do prof
	scanf("%d\n", &q);
	struct Musica lista[q];
	for(i=1; i<=q; i++){
		scanf("%s\n", lista[i].autor);
		scanf("%s", lista[i].titulo);
		vet[i] = buscar_musica(base, n, lista);
	}
	//tira os repetidos
	
	for(i=1; i<=q; i++){
		for(j=1; j<=n; j++){
			if(vet[i] == j){
				tempo+=base[j].duracao;
				if(tempo>3600){
					tempo-=base[j].duracao;
					vet[i]=0;
				}
			}
		}
	}
	quantidade=repetidos(&q, vet);
	//calcula o tempo de todas as musicas
	min=tempo/60;
	seg=tempo%60;
	if(seg<10){
		printf("Lista gerada com %d musicas e duracao %d:%02d\n", quantidade, min, seg);
	}else{
		printf("Lista gerada com %d musicas e duracao %d:%d\n", quantidade, min, seg);
	}

	//imprime o endereço das musicas
	for(i=1; i<=q; i++){
		for(j=1; j<=n; j++){
			if(vet[i] == j){
				printf("%s\n", base[j].arquivo);
			}
		}
	}
	return 0;
}