
typedef struct ponto Ponto;
struct ponto{
	float r;
	float i;
};


Ponto* cria (float r, float i);
void libera(Ponto *num);
Ponto* soma(Ponto *num1, Ponto *num2);
Ponto* subtracao(Ponto *num1, Ponto *num2);
Ponto* multiplicacao(Ponto *num1, Ponto *num2);
Ponto* divisao(Ponto *num1, Ponto *num2);
