#include <stdio.h>

void transposta(int l, int c, int mat[l][c]){
	int i, j;
	for(i=0; i<c; i++){
		for(j=0; j<l; j++){
			printf("%d ", mat[j][i]);
		}
		printf("\n");
	}
}
int main(){
	int i, j;
	int l, c;
	scanf("%d%d", &l, &c);
	int mat[l][c];
	for(i=0; i<l; i++){
		for(j=0; j<c; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	transposta(l,c, mat);
	return 0;
}



