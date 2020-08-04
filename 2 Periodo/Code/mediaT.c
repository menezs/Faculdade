#include <stdio.h>
#include <stdlib.h>
typedef struct aluno Aluno;
struct aluno{
  char nome[81];
  char matricula[8];
  char turma;
  float p1;
  float p2;
  float p3;
};
float media_turma(int n, Aluno** turmas, char tur){
	int i, j=0;
	float temp=0.0;
	for(i=0; i<n; i++){
		if( turmas[i]->turma == tur){
			temp+=(turmas[i]->p1+turmas[i]->p2+turmas[i]->p3);
			j=j+3;
		}	
	}
	if(temp>0){
		temp=temp/j;
	}
	return temp;
}
int main(){
	int n, t, i;
	char turma;
	scanf("%d\n", &n);
	Aluno *tab[n];
	for(i=0; i<n; i++){
		tab[i]=(Aluno*)malloc(sizeof(Aluno));
		scanf("%s\n", tab[i]->nome);
		scanf("%s\n", tab[i]->matricula);
		scanf("%c", &tab[i]->turma);
		scanf("%f%f%f", &tab[i]->p1, &tab[i]->p2, &tab[i]->p3 );
	}
	scanf("%d\n", &t);
	for(i=0; i<t; i++){
		scanf("\n%c", &turma);
		printf("%.2f\n", media_turma(n, tab, turma));
	}



	for(i=0; i<n; i++){
		free(tab[i]);
	}

	return 0;
}


