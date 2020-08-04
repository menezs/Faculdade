#include <stdio.h>
#include <math.h>
#include "pilha.h"

int main(void){
    int i, tam;
    float num1, num2;
    char op;
    Pilha* p = pilha_cria();

    scanf("%f", &num1);
    pilha_push(p, num1);
    scanf(" %c", &op);
    if(op != '#' && op != '^'){
        ungetc(op, stdin);
        scanf("%f", &num2);
        pilha_push(p, num2);
        scanf(" %c", &op);
    }

    while (op != 'q'){
        switch (op){
            case '-': 
                num1 = num1 - pilha_pop(p);
                pilha_pop(p);
                pilha_push(p, num1);
                break;
            case '+':
                num1 = num1 + pilha_pop(p);
                pilha_pop(p);
                pilha_push(p, num1);
                break;
            case '*':
                num1 = num1 * pilha_pop(p);
                pilha_pop(p);
                pilha_push(p, num1);
                break;
            case '/':
                num1 = num1 / pilha_pop(p);
                pilha_pop(p);
                pilha_push(p, num1);
                break;
            case '#':
                num1 = sqrt(pilha_pop(p));
                //pilha_pop(p);
                pilha_push(p, num1);
                break;
            case '^':
            /*
                num1 = 1;
                tam = pilha_pop(p);
                num2 = pilha_pop(p);
                for(i=0; i<tam; i++){
                    num1 *= 2;
                }
                */
                num2 = pilha_pop(p);
                num1 = num2*num2;
                pilha_push(p, num1);
                break;
        }
        
        scanf(" %c", &op);
        if(op != '#' && op != '^'){
            ungetc(op, stdin);
            scanf("%f", &num2);
            pilha_push(p, num2);
            scanf(" %c", &op);
        }
    }
    imprimir(p);
    
    pilha_libera(p);
    return 0;
}