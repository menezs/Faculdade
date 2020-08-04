#include <stdio.h>
#include <stdbool.h>
void identidade( int N, double A[][N]){
	int acu=0;
	int exit=1;
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(i == j ){
				acu=acu+A[i][j];
			}
		}
	}
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if( (i != j && A[i][j]!=0)){
				exit=0;
			}
		}
	}
	if(acu==N && exit==1){
		printf("sim\n");
	}else{
		printf("nao\n");
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
		identidade(N, A);
		scanf("%d", &N);
	}
	return 0;
}



