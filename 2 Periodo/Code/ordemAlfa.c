#include <stdio.h>

int main(void){
	char n1[10] = "ana";
	char n2[10] = "anas";
	int i=0;

	while(n1[i] == n2[i]){
		i++;
	}
	if (n1[i]<n2[i]){
		printf("%s %s\n", n1, n2);
	}else{
		printf("%s %s\n", n2, n1);
	}

	return 0;
}