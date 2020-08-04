#include <stdio.h>

void retornaArray(int n, int *vet, int m, int *vet2, int *vetR) {
	int i, j=0, cont=0;

	if(n>=m){
		for(i=0; i<n+m; i++){
			for(j=i+1; j<n+m; j++){
				if(vet[j]<vet2[i]){
					vetR[cont]=vet[i];
					cont++;
					vetR[cont]=vet2[j];
					cont++;
				}else{
					vetR[cont]=vet2[j];
					cont++;
					vetR[cont]=vet[i];
					cont++;
				}
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
		retornaArray(n, vet, m, vet2, vetR);
		for(j=0; j<m+n; j++){
			printf("%d ", vetR[j]);
		}
		printf("\n");
	}
	
	return 0;
}