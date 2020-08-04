#include <stdio.h>
void imprimir_palavra(int m, int n, char mat[][m], int linha, int coluna);
int main(){
	int i, j=1, n, m;
	int linha, coluna;
	FILE *file = fopen("entrada.txt", "r");
	FILE *vezes = fopen("vezes.txt", "r");

	scanf("%d%d\n", &n, &m);
	char mat[n][m];
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			fscanf(file, "%c", &mat[i][j]);
			if(mat[i][j] == '\n'){
				j--;
			}
		}
	}
	while( (fscanf(vezes, "%d%d", &linha, &coluna)) != EOF){
		imprimir_palavra(m, n, mat, linha, coluna);
	}

	return 0;
}
void imprimir_palavra(int m, int n, char mat[][m], int linha, int coluna){
	int j;

	printf("(%d, %d)\n", linha, coluna);
	for(j=linha; j>=1; j--){
		printf("%c", mat[j][coluna]);
	}
	printf("\n");

	for(j=coluna; j<=m; j++){
		printf("%c", mat[linha][j]);
	}
	printf("\n");

	for(j=linha; j<=n; j++){
		printf("%c", mat[j][coluna]);
	}
	printf("\n");

	for(j=coluna; j>=1; j--){
		printf("%c", mat[linha][j]);
	}
	printf("\n");
}