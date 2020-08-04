#include <stdio.h>
//#include "vecfun.h"


int remove_num(int *vet, int tam, int x){
	int temp;
	int i, j;
	for(i=0; i<tam; i++){
		if(vet[i] == x){
			j=i;
			while(j<tam){
				j++;
				temp = vet[j];
				vet[j-1] = temp;
			}
			tam--;
			i=0;
		}
	}
	return tam;
}
/*
void imprime(int* vet, int tam){
	int i;
	for(i=0; i<tam; i++){
		printf("%d ", vet[i]);
	}
	printf("\n");
}
*/
int main(void){
	int vet[100];
	int num, i=0;

	while( scanf("%d", &num) != EOF ){
		vet[i] = num;
		i++;
	}
	num = remove_num(vet, i, 0);
	for(i=0; i<num; i++){
		
		printf("%d ", vet[i]);
	}
	printf("\n");
	return 0;
}