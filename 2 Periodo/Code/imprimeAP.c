#include <stdio.h>
#include <stdlib.h>

struct aluno{
  char nome[81];
  char matricula[8];
  char turma;
  float p1;
  float p2;
  float p3;
};
typedef struct aluno Aluno;
void imprime_aprovados(int n, Aluno** turmas){
	int i;
	float temp;
	for(i=0; i<n; i++){
		temp=(turmas[i]->p1+turmas[i]->p2+turmas[i]->p3)/3;
		if( temp >= 6){
			printf("%s\n", turmas[i]->nome);
			printf("%s\n", turmas[i]->matricula);
			printf("%c\n", turmas[i]->turma);
			printf("%.2f\n", temp);
		}
		
	}
	
}
int main(){
	int n, i;
	scanf("%d\n", &n);
	Aluno *tab[n];
	for(i=0; i<n; i++){
		tab[i]=(Aluno*)malloc(sizeof(Aluno));
		scanf("%s\n", tab[i]->nome);
		scanf("%s\n", tab[i]->matricula);
		scanf("%c", &tab[i]->turma);
		scanf("%f%f%f", &tab[i]->p1, &tab[i]->p2, &tab[i]->p3 );
	}
	imprime_aprovados(n, tab);
	return 0;
}
