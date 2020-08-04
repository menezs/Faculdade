#include <stdio.h>
#include <math.h>
typedef struct ponto Ponto;
struct ponto{
  float x,y;
};

typedef struct circulo Circulo;
struct circulo {
  Ponto c; // centro do circulo
  float r; //raio
};

int intersecao(Circulo* a, Circulo* b){
	int saida=0;
	float somaRaio, distan;
	somaRaio=(a->r+b->r);
	distan=sqrt( pow((b->c.x - a->c.x), 2) + pow( (b->c.y - a->c.y), 2));
	if(somaRaio>=distan){
		saida=1;
	}

	return saida;
}

int main(){
	Circulo cc1;
	Circulo cc2;

	scanf("%f%f%f", &(cc1.c).x, &(cc1.c).y, &cc1.r);
	scanf("%f%f%f", &(cc2.c).x, &(cc2.c).y, &cc2.r);
	printf("%d", intersecao(&cc1, &cc2));
	
	return 0;
}
