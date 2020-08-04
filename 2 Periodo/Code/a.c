#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 102
#define MAXV 101
void imprimir_palavra(char mat[][MAX], int linha, int coluna, int incL, int incC, char* vetResp){
	int i=linha, j=coluna, k=0;
	while(mat[i][j] != 0){
		vetResp[k]=mat[i][j];
		k++;
		i+=incL;
		j+=incC;
	}
}

int main(){
	char* vetResp = (char*)malloc(MAXV*sizeof(char));
	int i, j, k, t, q, n, m;
	bool eh=true;
	char vet[51][MAXV];
	char mat[MAX][MAX];
	for(i=0; i<MAX; i++){
		for(j=0; j<MAX; j++){
			mat[i][j]=0;
		}
	}
	scanf("%d\n", &q);
	for(i=0; i<q; i++){
		scanf("%s", &vet[i][0]);
	}
	scanf("%d%d\n", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%s", &mat[i][1]);
	}


	k=0;
	while(k<q){
		for(i=1; i<=n; i++){
			for(j=1; j<=m; j++){
				//superior
				imprimir_palavra(mat, i, j, -1, 0, vetResp);
				eh=true;
				t=0;
				while(vet[k][t] != 0){
					if(vetResp[t] != vet[k][t]){
						eh=false;
					}
					t++;
				}
				if(eh){
					t=0;
					while(vet[k][t] != 0){
						printf("%c", vetResp[t]);
						t++;
					}
					printf("\n");
				}

				//diagonal superior direita
				imprimir_palavra(mat, i, j, -1, 1, vetResp);
				eh=true;
				t=0;
				while(vet[k][t] != 0){
					if(vetResp[t] != vet[k][t]){
						eh=false;
					}
					t++;
				}
				if(eh){
					t=0;
					while(vet[k][t] != 0){
						printf("%c", vetResp[t]);
						t++;
					}
					printf("\n");
				}

				//direita
				imprimir_palavra(mat, i, j, 0, 1, vetResp);
				eh=true;
				t=0;
				while(vet[k][t] != 0){
					if(vetResp[t] != vet[k][t]){
						eh=false;
					}
					t++;
				}
				if(eh){
					t=0;
					while(vet[k][t] != 0){
						printf("%c", vetResp[t]);
						t++;
					}
					printf("\n");
				}

				//diagonal inferior esquerda
				imprimir_palavra(mat, i, j, 1, 1, vetResp);
				eh=true;
				t=0;
				while(vet[k][t] != 0){
					if(vetResp[t] != vet[k][t]){
						eh=false;
					}
					t++;
				}
				if(eh){
					t=0;
					while(vet[k][t] != 0){
						printf("%c", vetResp[t]);
						t++;
					}
					printf("\n");
				}
				//inferior
				imprimir_palavra(mat, i, j, 1, 0, vetResp);
				eh=true;
				t=0;
				while(vet[k][t] != 0){
					if(vetResp[t] != vet[k][t]){
						eh=false;
					}
					t++;
				}
				if(eh){
					t=0;
					while(vet[k][t] != 0){
						printf("%c", vetResp[t]);
						t++;
					}
					printf("\n");
				}
				//diagonal inferior esquerda
				imprimir_palavra(mat, i, j, 1, -1, vetResp);
				eh=true;
				t=0;
				while(vet[k][t] != 0){
					if(vetResp[t] != vet[k][t]){
						eh=false;
					}
					t++;
				}
				if(eh){
					t=0;
					while(vet[k][t] != 0){
						printf("%c", vetResp[t]);
						t++;
					}
					printf("\n");
				}
				//esquerda
				imprimir_palavra(mat, i, j, 0, -1, vetResp);
				eh=true;
				t=0;
				while(vet[k][t] != 0){
					if(vetResp[t] != vet[k][t]){
						eh=false;
					}
					t++;
				}
				if(eh){
					t=0;
					while(vet[k][t] != 0){
						printf("%c", vetResp[t]);
						t++;
					}
					printf("\n");
				}
				//diagonal superior esquerda
				imprimir_palavra(mat, i, j, -1, -1, vetResp);
				eh=true;
				t=0;
				while(vet[k][t] != 0){
					if(vetResp[t] != vet[k][t]){
						eh=false;
					}
					t++;
				}
				if(eh){
					t=0;
					while(vet[k][t] != 0){
						printf("%c", vetResp[t]);
						t++;
					}
					printf("\n");
				}
			}
		}
	k++;
	}

	

	return 0;
}
