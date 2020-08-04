#include <stdio.h>
#include <stdlib.h>

int* vet_cria(int n){
    int* vet = malloc(n*sizeof(int));
    if(vet == NULL){
        exit(1);
    }

    return vet;
}
void libera(int* vet){
    free(vet);
}
void preenche(int* vet, int n){
    int i;
    for(i=n-1; i>=0; i--){
        scanf("%d",  &vet[i]);
    }
}
void imprime(int* vet, int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d ", vet[i]);
    }
}
int main(void){
    int n;
    scanf("%d", &n);
    int* vet = vet_cria(n);
    preenche(vet, n);
    imprime(vet, n);

    libera(vet);
    return 0;
}