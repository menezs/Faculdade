#include <stdio.h>

int fatorial(int n){
	int saida = 1, i;
	for(i=n; i>0; i--){
		saida *= i; 
	}
	return saida;
}

void preencheMat(int ordem, int mat[][ordem], int n, int borda){
	int x = ordem/2;
	if(n>x){
		int ini = ordem-n, fim = n;
		int f = fatorial(borda);
		int i, j;
		for(i=ini; i<fim; i++){
			for(j=ini; j<fim; j++){
				mat[i][j]=f;
			}
		}
		preencheMat(ordem, mat, n-1, borda-1);
	}
}

void imprime(int ordem, int mat[][ordem]){
	int i, j;
	for(i=0; i<ordem; i++){
		for(j=0; j<ordem; j++){
			printf("%d", mat[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	int ordem;
	
	scanf("%d", &ordem);
	int mat[ordem][ordem];
	preencheMat(ordem, mat, ordem, (ordem/2)+1);
	
	imprime(ordem, mat);
	
	return 0;
}