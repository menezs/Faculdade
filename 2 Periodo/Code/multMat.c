#include <stdio.h>
#include <stdlib.h>
double** matmul(int m, int n, int p, double A[][n], double B[][p]);
int main(){
	int linhasA, colunasA, linhasB, colunasB;
	int i, j, cont=1;
	scanf("%d%d", &linhasA, &colunasA);
	while(linhasA != 0 && colunasA != 0){
		double matA[linhasA][colunasA];
		for(i=0; i<linhasA; i++){
			for(j=0; j<colunasA; j++){
				scanf("%lf", &matA[i][j]);
			}
		}
		scanf("%d%d", &linhasB, &colunasB);
		double matB[linhasB][colunasB];
		for(i=0; i<linhasB; i++){
			for(j=0; j<colunasB; j++){
				scanf("%lf", &matB[i][j]);
			}
		}
		printf("Caso #%d\n", cont);
		if(colunasA == linhasB){
			double **matResp = matmul(linhasA, colunasA, colunasB, matA, matB);
			for(i=0; i<linhasA; i++){
				for(j=0; j<colunasB; j++){
					printf("%.2f ", matResp[i][j]);
				}
				printf("\n");
			}
		}
		
		scanf("%d%d", &linhasA, &colunasA);
		cont++;
	}
	
	
	return 0;     
}
double ** matmul(int m, int n, int p, double A[][n], double B[][p]){
	int i, j, k;
	double **C = (double**)malloc(m*sizeof(double*));
	for(i=0; i<m; i++){
		C[i] = (double*)malloc(p*sizeof(double));
	}
	double temp=0.0;
	for(i=0; i<m; i++){
		for(j=0; j<p; j++){
			temp=0.0;
			for(k=0; k<n; k++){
				temp=temp + (A[i][k]*B[k][j]);
			}
			C[i][j]=temp;
		}
	}
	
	return C;
}




