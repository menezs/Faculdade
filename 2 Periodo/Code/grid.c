#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 102
#define MAXV 101
void imprimir_palavra(char mat[][MAX], int linha, int coluna, int incL, int incC, char* vetResp){
	int i=linha, j=coluna, k=0;
	while(mat[i][j] != 0){
		vetResp[k]=mat[i][j];
		k++;
		i+=incL;
		j+=incC;
	}
}

int main(){
	char* vetResp = (char*)malloc(MAXV*sizeof(char));
	int linha, coluna, tam=1;
	int i, j, q, n, m;
	bool eh=true;
	char vet[50][MAXV];
	char mat[MAX][MAX];
	for(i=0; i<MAX; i++){
		for(j=0; j<MAX; j++){
			mat[i][j]=0;
		}
	}
	scanf("%d\n", &q);
	for(i=0; i<q; i++){
		scanf("%s", &vet[i][0]);
	}
	scanf("%d%d\n", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%s", &mat[i][1]);
	}
	

	
	return 0;
}
