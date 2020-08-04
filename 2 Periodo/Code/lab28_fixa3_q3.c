#include <stdio.h>

double aproximacaoPi(int n){
    double saida=1.5;
    int i;
    double ax=(2*n)+1;
    
    for(i=n; i>0; i--){
        saida =  1+(i/ax*saida);
        ax -= 2;
    }
    saida *= 2;
   
    return saida;
}

int main(void){
    int n;

    scanf("%d", &n);
    printf("%.10f\n", aproximacaoPi(n));
    

    return 0;
}