#include <stdio.h>

void ordena(int n, int *vet, int m, int *vet2, int *vetR) {
	int i, j, temp, cont=0;
	for(i=0; i<n; i++){
		vetR[cont]=vet[i];
		cont++;
	}
	for(i=0; i<m; i++){
		vetR[cont]=vet2[i];
		cont++;
	}
	for(i=0; i<n+m; i++){
		for(j=i+1; j<n+m; j++){
			if(vetR[j]<vetR[i]){
				temp=vetR[j];
				vetR[j]=vetR[i];
				vetR[i]=temp;
			}
		}
		
	}
}
int main(){
	int repeticoes, n, m, i, j;

	scanf("%d", &repeticoes);
	for(i=0; i<repeticoes; i++){
		scanf("%d", &n);
		int vet[n];
		for(j=0; j<n; j++){
			scanf("%d", &vet[j]);
		}
		scanf("%d", &m);
		int vet2[m];
		for(j=0; j<m; j++){
			scanf("%d", &vet2[j]);
		}
		int vetR[n+m];
		ordena(n, vet, m, vet2, vetR);
		for(j=0; j<m+n; j++){
			printf("%d ", vetR[j]);
		}
		printf("\n");
	}
	
	return 0;
}