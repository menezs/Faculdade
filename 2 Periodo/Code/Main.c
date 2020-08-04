#include <stdio.h>

#define FIRST 1.5

double numeroImpar(int n){
	int i;
	double result=1;
	for(i=0;i<n;i++)
		result+=2;
	return result;
}

double aproximaPI(int n){
	double result=FIRST;
	int i;
	for(i=n;i>0;i--){
		result=1+(i/numeroImpar(i)*result);
	}
	result*=2;
	return result;
}

int main(void){
	int valor;
	scanf("%d",&valor);
	printf("%.10f\n",aproximaPI(valor));
	return 0;
}