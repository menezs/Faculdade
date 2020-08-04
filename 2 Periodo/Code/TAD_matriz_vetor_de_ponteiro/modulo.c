#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

struct matriz{
  int lin;
  int col;
  float** v;
};

Matriz* mat_cria(int m, int n){
	int i, j;
	Matriz* mat = (Matriz*)malloc(sizeof(Matriz));
	if(mat == NULL){
		exit(1);
	}
	mat->lin = m;
	mat->col = n;

	float** v = (float**) malloc(m*sizeof(float*));
	for(i=0; i<m; i++){
		v[i] = (float*) malloc(n*sizeof(float));
		if (v[i] == NULL){
			printf("memory\n");
			exit(1);
		}
		for(j=0; j<n; j++){
			v[i][j] = 0;
		}
	}

	mat->v = v;
	return mat;
}
void mat_libera(Matriz* mat){
	int i;
	for(i=0; i<mat->lin; i++){
		free(mat->v[i]);
	}
	free(mat);
}
float mat_acessa(Matriz* mat, int i, int j){
	return mat->v[i][j];
}
void mat_atribui(Matriz* mat, int i, int j, float v){
	mat->v[i][j] = v;
}
int mat_linhas(Matriz* mat){
	return mat->lin;
}
int mat_colunas(Matriz* mat){
	return mat->col;
}
Matriz* transposta(Matriz* mat){
	int i, j;
	Matriz* matResp = mat_cria(mat->col, mat->lin);
	for(i=0; i<mat->lin; i++){
		for(j=0; j<mat->col; j++){
			mat_atribui(matResp, j, i, mat_acessa(mat, i, j));
		}
	}

	return matResp;
}
void desenha(Matriz* mat){
	int i, j;
	float temp = mat->lin;
	for(i= mat->lin-1; i>=0; i--){
		for(j= mat->col-1; j>=0; j--){
			mat_atribui(mat, i, j, temp);
			mat_atribui(mat, j, i, temp);
		}
		temp--;
	}
}
void somar_algunsElementos(Matriz* mat){

}
void imprime(Matriz* mat){
	int i, j;
	for(i=0; i<mat->lin; i++){
		for(j=0; j<mat->col; j++){
			printf("%.2f ", mat->v[i][j]);
		}
		printf("\n");
	}
}