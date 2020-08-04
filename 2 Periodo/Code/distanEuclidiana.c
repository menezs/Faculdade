#include <stdio.h>
#include <math.h>
float distanEuclidiana(float* vet1, float* vet2, int n){
    int i;
    float saida=0.0;
    for(i=0; i<n; i++){
        saida=saida+pow(vet1[i]-vet2[i], 2);
    }

    return sqrt(saida);
}

int main(void){
    int n, i;

    scanf("%d", &n);
    float vet1[n];
    float vet2[n];

    for(i=0; i<n; i++){
        scanf("%f", &vet1[i]);
    }
    for(i=0; i<n; i++){
        scanf("%f", &vet2[i]);
    }
    printf("%.4f", distanEuclidiana(vet1, vet2, n));
    return 0;
}