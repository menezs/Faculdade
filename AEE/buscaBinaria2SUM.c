#include <stdio.h>
void trocar(int* vet, int ant, int prox){
    int temp = vet[prox];
    vet[prox] = vet[ant];
    vet[ant] = temp;
}
void ordenacao_selection(int* vet, int tam){
    int i, j, menor;

    for(i=0; i<tam; i++){
        menor = i;
        for(j=i+1; j<tam; j++){
            if(vet[j]<vet[menor]){
                menor = j;
            }
        }
        if(menor != i){
            trocar(vet, i, menor);
        }
    }
}
int confere(int* vet, int tam, int chave){
    chave *= -1;
    int ret = 0, meio;
    int esq = 0;
    int dir = tam-1;
    while(esq<=dir){
        meio = (esq+dir)/2;    
        if(vet[meio] == chave){
            ret = 1;
            break;
        }
        if(vet[meio] < chave){
            esq = meio +1;
        }else{
            dir = meio - 1;
        }
    }
    return ret;
}
int busca_bi_2sum(int* vet, int tam){
    ordenacao_selection(vet, tam);
    int i;
    for(i=0; i<tam; i++){
        if(confere(vet, tam, vet[i])){
            return 1;
        }
    }
    return 0;
}
void imprimir(int* vet, int tam){
    int i;
    for(i = 0; i<tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}
int main(void){
    int tam, i;

    scanf("%d", &tam);
    while(tam != 0){
        int vet[tam];
        for(i=0; i<tam; i++){
            scanf("%d", &vet[i]);
        }
        if(busca_bi_2sum(vet, tam)){
            printf("sim\n");
        }else{
            printf("nao\n");
        }
        
        scanf("%d", &tam);
    }

    return 0;
}