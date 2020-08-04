#include <stdio.h>
#include "interface.h"

int main(){
	float r, i;

	scanf("%f%f", &r, &i);
	Ponto* num1 = cria(r, i);
	scanf("%f%f", &r, &i);
	Ponto* num2 = cria(r, i);

	Ponto* res;
	res = soma(num1, num2);
	printf("Soma: parte real: %.2f parte imaginaria: %.2f\n", res->r, res->i);
	libera(res);

	res = subtracao(num1, num2);
	printf("Subtracao: parte real: %.2f parte imaginaria: %.2f\n", res->r, res->i);
	libera(res);

	res = multiplicacao(num1, num2);
	printf("Multiplicacao: parte real: %.2f parte imaginaria: %.2f\n", res->r, res->i);
	libera(res);

	res = divisao(num1, num2);
	printf("Divisao: parte real: %.2f parte imaginaria: %.2f\n", res->r, res->i);
	libera(res);

	libera(num1);
	libera(num2);

	return 0;
}