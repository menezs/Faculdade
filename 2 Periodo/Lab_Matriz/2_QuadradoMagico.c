#include <stdio.h>
#include <stdbool.h>

void quadradoMagico(int N, double A[][N]){
	bool naoEh=false;
	double acu=0.0;
	double exit=0.0;
	int i, j;
	for(j=0; j<N; j++){
		acu=acu+A[0][j];
	}
	for(i=0; i<N; i++){
		exit=0.0;
		for(j=0; j<N; j++){
			exit=exit+A[i][j];
		}
		if(acu != exit ){
			naoEh=true;
		}
	}
	for(i=0; i<N; i++){
		exit=0.0;
		for(j=0; j<N; j++){
			exit=exit+A[j][i];
		}
		if( acu != exit){
			naoEh=true;
		}
	}
	exit=0.0;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(i==j){
				exit=exit+A[i][j];
			}
		}
	}
	if( acu != exit){
		naoEh=true;
	}
	exit=0.0;
	i=N-1;
	for(j=0; j<N; j++){
		exit=exit+A[j][i];
		i--;
	}
	if( acu != exit){
		naoEh=true;
	}
	
	if(naoEh){
		printf("nao\n");
	}else{
		printf("sim\n");
	}
	
}


int main(){
	int i, j, N;
	scanf("%d", &N);
	while(N!=0){
		double A[N][N];
		for(i=0; i<N; i++){
			for(j=0; j<N; j++){
				scanf("%lf", &A[i][j]);
			}
		}
		quadradoMagico(N, A);
		scanf("%d", &N);
	}
	return 0;
}



