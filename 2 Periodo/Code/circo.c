#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct retangulo Ret;
struct retangulo{
	float base, altura;
};

typedef struct circulo Circ;
struct circulo{
	float raio;
};

Ret* ret_circunscrito (Circ* c, float h){
	float diametro;
	Ret *saida = (Ret*)malloc(sizeof(Ret));
	if(saida == NULL){
		printf("memory");
		exit(1);
	}
	diametro=2*(c->raio);
	saida->base=sqrt( (diametro*diametro) - (h*h));
	saida->altura=h;
	return saida;
}

Circ* circ_interno (Ret *r){
	Circ* saida = (Circ*)malloc(sizeof(Circ));
	if(saida == NULL){
		printf("memory");
		exit(1);
	}
	saida->raio=(r->base)/2;
	return saida;
}
int main(){
	Ret r;
	Ret *respR;
	Circ c;
	Circ *respC;

	scanf("%f%f%f", &c.raio, &r.base, &r.altura);
	
	if(r.altura < 2*(c.raio)){
		respC=circ_interno (&r);
		printf("%.2f\n", respC->raio);
		respR=ret_circunscrito (&c, r.altura);
		printf("%.2f %.2f", respR->base, respR->altura);
	}
	free(respC);
	free(respR);
	return 0;
}