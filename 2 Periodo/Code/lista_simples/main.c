#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void){
    int num;
    Lista* lis = criar_lista();

    scanf("%d", &num);
    while(num != -1){
        while (num != 0){
            inserir_fim(lis, num);
            scanf("%d", &num);
        }
        scanf("%d", &num);
        remover_all_elem(lis, num);

        if(confere_tripla_nada(lis)){
            printf("tripla\n");
        }else{
            printf("nada\n");
        }
        
        destruir_lista(lis);
        lis = criar_lista();
        scanf("%d", &num);
    }


    destruir_lista(lis);
    return 0;
}


