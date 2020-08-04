#include <stdio.h>
#define MAX 102
int direcoes(char mat[][MAX], int linha, int coluna, int incL, int incC){
	int saida=1;
	if(mat[linha+incL][coluna+incC] == '*' ){
		saida=0;
	}
	return saida;
}
int main(){
	int i, j;
	int r, c, star=0;
	char grid[MAX][MAX];
	scanf("%d%d\n", &r, &c);
	while(r != 0 && c != 0){
		star=0;
		for(i=0; i<MAX; i++){
			for(j=0; j<MAX;j++){
				grid[i][j]=0;
			}
		}
		for(i=1; i<=r; i++){
			scanf("%s", &grid[i][1]);
		}
		for(i=1; i<=r; i++){
			for(j=1; j<=c;j++){
				if(grid[i][j] == '*'){
					if(direcoes(grid, i, j, -1, 0) == 1 &&  direcoes(grid, i, j, -1, 1) == 1 &&
						direcoes(grid, i, j, 0, 1) == 1 && direcoes(grid, i, j, 1, 1) == 1 &&
						direcoes(grid, i, j, 1, 0) == 1 && direcoes(grid, i, j, 1, -1) == 1 &&
						direcoes(grid, i, j, 0, -1) == 1 && direcoes(grid, i, j, -1, -1) == 1){
						star++;
					}
				}
			}
		}
		printf("%d\n", star);
		scanf("%d%d", &r, &c);
	}
	
	return 0;
}