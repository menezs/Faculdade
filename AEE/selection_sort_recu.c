#include <stdio.h>
#include <stdlib.h>

int menor(int* v, int inicio, int fim){
    int menor, i;
    menor = inicio;
    for(i=inicio; i<fim; i++){
        if(v[i] < v[menor]){
            menor = i;
        }
    }
    return menor;
}
void trocar(int* vet, int pos, int menor){
    int temp = vet[pos];
    vet[pos] = vet[menor];
    vet[menor] = temp;
}
void imprimir(int* vet, int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}
void ordenacao_recursiva(int* vet, int min, int max){
    if(min == max-1){
        return;
    }else{
        trocar(vet, min, menor(vet, min, max));
        min++;
        ordenacao_recursiva(vet, min, max);
    }
}
int main(void){
    int tam = 2;
    int* vet = malloc(tam * sizeof(int));
    int i = 0, num;

    while(scanf("%d", &num) != EOF){
        vet[i] = num;
        if(i == tam-1){
            tam *= 2;
            vet = realloc(vet, tam * sizeof(int));
        }
        i++;
    }
    imprimir(vet, i);
    ordenacao_recursiva(vet, 0, i);
    imprimir(vet, i);
    free(vet);
    return 0;
}