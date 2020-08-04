#include <stdio.h>

int star(int l, int c, char mat[l][c]){
	int exit=0, i, j;
	for(i=1; i<l-1; i++){
		for(j=1; j<c-1; j++){
			if(mat[i][j]=='*' && mat[i][j-1]!='*' && mat[i][j+1]!='*' && mat[i-1][j]!='*' && mat[i+1][j]!='*'
				&& mat[i+1][j+1]!='*' && mat[i-1][j-1]!='*' && mat[i-1][j+1]!='*' && mat[i+1][j-1]!='*'){
				exit++;
			}
		}
	}
	
	 return exit;
}

int main(){
	int i, j;
	int l, c;
	char x;
	scanf("%d%d\n", &l, &c);
	
	while(l!=0 && c!=0){
		l=l+2;
		c=c+2;
		char mat[l][c];
		for(i=1; i<l-1; i++){
			for(j=1; j<c-1; j++){
				x=getchar();
				if( x!='\n' ){
					mat[i][j]=x;
				}else{
					j--;
				}
			}
		}
		for(i=0; i<l; i++){
			for(j=0; j<c; j++){
				if(i==0 || i==l-1){
					mat[i][j]='.';
				}
				if(j==0 || j==c-1){
					mat[i][j]='.';
				}
			}
		}
		printf("%d\n", star(l, c, mat));
		scanf("%d%d\n", &l, &c);
	}
	return 0;
}

