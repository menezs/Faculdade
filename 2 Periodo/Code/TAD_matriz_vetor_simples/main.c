#include <stdio.h>
#include "interface.h"

int main(void){
	int l, c, i, j;

	scanf("%d%d", &l, &c);
	Matriz* matA = mat_cria(l, c);
	for(i=0; i<matA->lin; i++){
		for(j=0; j<matA->col; j++){
			scanf("%f", &matA->v[i*matA->col]+j);
		}
	}
	scanf("%d%d", &l, &c);
	Matriz* matB = mat_cria(l, c);
	for(i=0; i<matB->lin; i++){
		for(j=0; j<matB->col; j++){
			scanf("%f", &matB->v[i*matB->col]+j);
		}
	}
	Matriz* matResp = mat_mult(matA, matB);
	for(i=0; i<matResp->lin; i++){
		for(j=0; j<matResp->col; j++){
			printf("%.2f ", matResp->v[i*matResp->col+j]);
		}
		printf("\n");
	}

	mat_libera(matResp);
	mat_libera(matA);
	mat_libera(matB);
	return 0;
}