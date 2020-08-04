#include <stdio.h>
#include "interface.h"

int main(void){
	int n, ordem;
	Matriz* mat = mat_cria(5, 5);

	imprime(mat);

	mat_libera(mat);

/*	
	int i, j, linha, coluna;
	float temp;

	scanf("%d%d", &linha, &coluna);
	Matriz* mat = mat_cria(linha, coluna);
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			scanf("%f", &temp);
			mat_atribui(mat, i, j, temp);
		}
	}

	Matriz* matResp = transposta(mat);
	for(i=0; i<matResp->lin; i++){
		for(j=0; j<matResp->col; j++){
			printf("%.2f ", matResp->v[i][j]);
		}
		printf("\n");
	}

	mat_libera(matResp);
	mat_libera(mat);
	*/
	return 0;
}