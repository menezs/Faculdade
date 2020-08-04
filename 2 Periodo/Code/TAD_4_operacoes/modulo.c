#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "interface.h"

Ponto* cria(float r, float i){
	Ponto* p = (Ponto*) malloc(sizeof(Ponto));
	if (p == NULL){
		exit(1);
	}
		p->r = r;
		p->i = i;
	return p;
}
void libera(Ponto *num){
	free(num);
}

Ponto* soma(Ponto *num1, Ponto *num2){
	Ponto* res = (Ponto*) malloc(sizeof(Ponto));
	if (res == NULL){
		exit(1);
	}
	res->r = num1->r + num2->r;
	res->i = num1->i + num2->i;
	return res;
}
Ponto* subtracao(Ponto *num1, Ponto *num2){
	Ponto* res = (Ponto*) malloc(sizeof(Ponto));
	if (res == NULL){
		exit(1);
	}
	res->r = num1->r - num2->r;
	res->i = num1->i - num2->i;
	return res;
}

Ponto* multiplicacao(Ponto *num1, Ponto *num2){
	Ponto* res = (Ponto*) malloc(sizeof(Ponto));
	if (res == NULL){
		exit(1);
	}
	res->r= (num1->r*num2->r)-(num1->i*num2->i);
	res->i= (num1->i*num2->r)+(num1->r*num2->i);
	return res;
}
Ponto* divisao(Ponto *num1, Ponto *num2){
	Ponto* res = (Ponto*) malloc(sizeof(Ponto));
	if (res == NULL){
		exit(1);
	}
	res->r = ((num1->r*num2->r)+(num1->i*num2->i))/(pow(num2->r, 2)+pow(num2->i, 2));
	res->i = ((num1->i*num2->r)-(num1->r*num2->i))/(pow(num2->r, 2)+pow(num2->i, 2));
	return res;
}
