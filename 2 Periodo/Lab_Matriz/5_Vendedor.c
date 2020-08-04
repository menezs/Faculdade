#include <stdio.h>
#define col 7

int tabela(int lin, int mat[lin][col]){
	int i, j, maior, cal, exit;
	for(i=0; i<lin; i++){
		cal=0;
		for(j=0; j<col; j++){
			cal=cal+mat[i][j];
		}
		if(cal>maior){
			maior=cal;
			exit=i;
		}
	}
	return exit;
}
int main(){
	int i, j;
	int lin;
	scanf("%d", &lin);
	int mat[lin][col];
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	printf("%d\n", tabela(lin, mat));
	return 0;
}