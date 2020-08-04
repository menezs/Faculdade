#include <stdio.h>
//#include <string.h>
#include "pilha.h"

int main(void){
    int n, i;
    char temp;
    Pilha* p = pilha_cria();

    scanf("%d\n", &n);
    for(i=0; i<n; i++){
        
        scanf("%c", &temp);
        while (temp != '\n'){
            pilha_push(p, temp);
            scanf("%c", &temp);
        }
        printf("%c\n", confere(p));

        pilha_libera(p);
        p = pilha_cria();
    }
    
    pilha_libera(p);
    return 0;
}