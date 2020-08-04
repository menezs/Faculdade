#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

Matriz* mat_cria(int m, int n){
	Matriz* mat = (Matriz*)malloc(sizeof(Matriz));
	if(mat == NULL){
		exit(1);
	}
	mat->lin = m;
	mat->col = n;

	float* v = (float*) malloc(m*n*sizeof(float));
	if (v == NULL){
		exit(1);
	}
	mat->v = v;
	return mat;
}
void mat_libera(Matriz* mat){
	free(mat->v);
	free(mat);
}
float mat_acessa(Matriz* mat, int i, int j){
	int n = mat->col;
	return mat->v[i*n+j];
}
void mat_atribui(Matriz* mat, int i, int j, float v){
	int n = mat->col;
	mat->v[i*n+j] = v;
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
Matriz* mat_mult(Matriz* a, Matriz* b){
	Matriz* resp = mat_cria(a->lin, b->col);
	int i, j, k;
	float cal = 0.0;
	for(i=0; i<a->lin; i++){
		for(j=0; j<b->col; j++){
			for(k=0; k<a->col; k++){
				cal=cal+ (mat_acessa(a, i, k) * mat_acessa(b, k, j));
			}
			mat_atribui(resp, i, j, cal);
			cal = 0.0;
		}
	}

	return resp;
}