#include <stdio.h>
#include "pilha.h"

int main(void){
    int tam, i;
    float temp;
    Pilha* p1 = pilha_cria();
    Pilha* p2 = pilha_cria();
    
    scanf("%d", &tam);
    for(i=0; i<tam; i++){
        scanf("%f", &temp);
        pilha_push(p1, temp);
    }
    scanf("%d", &tam);
    for(i=0; i<tam; i++){
        scanf("%f", &temp);
        pilha_push(p2, temp);
    }
    concatena_pilhas(p1, p2);
    imprimir(p1);

    pilha_libera(p1);
    pilha_libera(p2);
    return 0;
}