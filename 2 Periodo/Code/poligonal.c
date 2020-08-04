#include <stdio.h>
#include <math.h>
typedef struct ponto Ponto;
struct ponto{
  float x,y;
};

float comprimento(int n, Ponto* vet){
	float saida=0;
	int i;
	for(i=0; i<n-1; i++){
		saida=saida + sqrt( pow((vet[i+1].x - vet[i].x), 2) + pow( (vet[i+1].y - vet[i].y), 2) );
	}
	
	return saida;
}
int main(){
	int n, i;
	scanf("%d", &n);
	if(n>=2){
		Ponto vet[n];
		for(i=0; i<n; i++){
			scanf("%f%f", &vet[i].x, &vet[i].y);
		}
		printf("%.2f\n", comprimento(n, vet));
	}
	return 0;
}

