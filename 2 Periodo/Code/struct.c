#include <stdio.h>
#define MAX 3

struct ponto{
	float vet[MAX];
};
typedef struct ponto Vetor;
float escalar(Vetor* v1, Vetor* v2){
	int i;
	float temp;
	for(i=0; i<MAX; i++){
		temp+=(v1->vet[i] * v2->vet[i]);
	}
	
	return temp;
}
int main(){
	
	Vetor vet1;
	Vetor vet2;
	int i;
	for(i=0; i<MAX; i++){
		scanf("%f", &vet1.vet[i]);
	}
	for(i=0; i<MAX; i++){
		scanf("%f", &vet2.vet[i]);
	}
	printf("%.2f", escalar(&vet1, &vet2));
	
	return 0;
}
