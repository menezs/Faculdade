#include <stdio.h>
#include "fila.h"

int main(void){
    char temp;
    float num;
    Fila* f1 = fila_cria();
    Fila* f2 = fila_cria();
    Fila* res = fila_cria();

    scanf("%c", &temp);
    while(temp != '*'){
        ungetc(temp, stdin);
        scanf("%f", &num);
        fila_insere(f1, num);
        scanf(" %c", &temp);
    }

    scanf("%c", &temp);
    while(temp != '*'){
        ungetc(temp, stdin);
        scanf("%f", &num);
        fila_insere(f2, num);
        scanf(" %c", &temp);
    }
    
    combina_filas(res, f1, f2);
    fila_imprime(res);

    fila_libera(f1);
    fila_libera(f2);
    fila_libera(res);
    return 0;
}