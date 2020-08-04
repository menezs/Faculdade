#include <stdio.h>
#include <stdlib.h>

int crescre_ou_nao(int* vet, int tam){
    int menor;
    int i, j;
    for(i=0; i<tam; i++){
        menor = vet[i];
        for(j=i; j<tam; j++){
            if(menor > vet[j]){
                return 0;
            }
        }
    }
    return 1;
}
void imprimir(int* vet, int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main(){
    int num, i=0, tam = 2;
    int* vet = malloc(tam*sizeof(int));

    while(scanf("%d", &num) != EOF){
        vet[i] = num;
        if(i == tam-1){
            tam *= 2;
            vet = realloc(vet, tam*sizeof(int));
        }
        i++;
    }
    //imprimir(vet, i);
    if(crescre_ou_nao(vet, i)){
        printf("NAO CRESCENTE\n");
    }else
    {
        printf("CRESCENTE\n");
    }
    
    free(vet);
    return 0;
}