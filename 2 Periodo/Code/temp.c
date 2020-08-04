#include <stdio.h>
#include <stdlib.h>
typedef struct matriz Matriz;
struct matriz{
  int lin;
  int col;
  int** v;
};

Matriz* mat_cria(int m, int n){
	int i;
	Matriz* mat = (Matriz*)malloc(sizeof(Matriz));
	if(mat == NULL){
		exit(1);
	}
	mat->lin = m;
	mat->col = n;

	int** v = (int**) malloc(m*sizeof(int*));
	for(i=0; i<m; i++){
		v[i] = (int*) malloc(n*sizeof(int));
		if (v[i] == NULL){
			printf("memory\n");
			exit(1);
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
void mat_atribui(Matriz* mat, int i, int j, int v){
	mat->v[i][j] = v;
}
int mat_linhas(Matriz* mat){
	return mat->lin;
}
int mat_colunas(Matriz* mat){
	return mat->col;
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
void imprime(Matriz* mat){
	int i, j;
	for(i=0; i<mat->lin; i++){
		for(j=0; j<mat->col; j++){
			printf("%d ", mat->v[i][j]);
		}
		printf("\n");
	}
}
int main(void){
    int ordem;
    scanf("%d", &ordem);
	Matriz* mat = mat_cria(ordem, ordem);
	desenha(mat);
	imprime(mat);

	mat_libera(mat);
}