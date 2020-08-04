#include <stdio.h>
#define MAX 1000

int modulo(int n1, int n2){
	int resul;
	resul = n1*n2;
	resul = resul % MAX;
	return resul;
}

int main(void){
	int mult=1;
	int num;
    
	while( scanf("%d", &num) != EOF ){
		mult=modulo(mult, num);
	}
	printf("%d\n", mult);
	return 0;
}

