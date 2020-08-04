#include <stdio.h>
#include <stdlib.h>

char** criaTabuleiro(int n){
	int i,j;
	char** v = (char**) malloc(n*sizeof(char*));
	for(i=0;i<n;i++){
		v[i]=(char*)malloc(n*sizeof(char));
		for(j=0;j<n;j++){
			v[i][j]='#';
		}
	}

    return v;
}

void preencheTabuleiro(char** tab,int n){
	int i,j;
	int bombas=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(tab[i][j]=='9') tab[i][j]='*';
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(tab[i][j]=='0'){
				if(tab[i-1][j-1]=='*') bombas++;
				if(tab[i-1][j]=='*') bombas++;
				if(tab[i-1][j+1]=='*') bombas++;
				if(tab[i][j-1]=='*') bombas++;
				if(tab[i][j+1]=='*') bombas++;
				if(tab[i+1][j-1]=='*') bombas++;
				if(tab[i+1][j]=='*') bombas++;
				if(tab[i+1][j+1]=='*') bombas++;
				tab[i][j]=bombas+'0';
			}
			bombas=0;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(tab[i][j]=='0') tab[i][j]='.';
		}
	}
}

int main(void){
	int n;
	char temp;
	scanf("%d",&n);
	n += 2;
	char** tab = criaTabuleiro(n);
	int i,j;
	
	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			temp=getchar();
			if(temp!=' ' && temp!='\n'){
				tab[i][j]=temp;
			}
		}
	}
	//preencheTabuleiro(tab,n);
	
	for(i=0;i<n+2;i++){
		for(j=0;j<n+2;j++){
			printf("%c",tab[i][j]);
		}
		printf("\n");
	}
	return 0;
}