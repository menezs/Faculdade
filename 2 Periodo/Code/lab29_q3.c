#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
struct no{
	No* ant;
	No* prox;
	int dado;
};

typedef struct lista Lista;
struct lista{
    int tam;
	No* inicio;
	No* fim;	
};

Lista* criar_lista(){
	Lista* lis = malloc(sizeof(Lista));
    lis->tam = 0;
	lis->inicio = NULL;
	lis->fim = NULL;
	return lis;
}
void destruir_lista(Lista* lis){
	if(lis->inicio != NULL){
		No* p = lis->inicio;
		while(p != NULL){
			No* temp = p->prox;
			free(p);
			p = temp;
		}
	}
	free(lis);
}
void inserir_lista(Lista* lis, int elem){
    lis->tam++;
	No* p = lis->inicio;
	No* novo = malloc(sizeof(No));
	novo->dado = elem;
	if(p == NULL){
		lis->inicio= lis->fim = novo;
		novo->prox = novo->ant = NULL;
	}else{
		novo->prox = lis->inicio;
		lis->inicio->ant = novo;
		lis->inicio = novo;
		novo->ant = NULL;
	}
}
void imprimir(Lista* lis){
	if(lis->inicio != NULL){
		No* p =lis->inicio;
		while(p != NULL){
			printf("%d ", p->dado);
			p = p->prox;
		}
		printf("\n");
	}
}
void removerNo_inicio(Lista* lis){
    lis->tam--;
    No* temp = lis->fim->ant;
    free(lis->fim);
    lis->fim = temp;
    temp->prox = NULL;
}
void remover_trocar(Lista* lis){
    
    if(lis->tam == 2){
        printf("%d", lis->fim->dado);
        removerNo_inicio(lis);
    }else if(lis->tam != 1){
        while(lis->tam != 1){
            printf("%d", lis->fim->dado);
            removerNo_inicio(lis);
            if(lis->tam != 1){
                printf(", ");
                No* p = lis->fim->ant;
                lis->fim->prox = lis->inicio;
                lis->inicio->ant = lis->fim;
                lis->fim->ant = NULL;
                lis->inicio = lis->fim;
                lis->fim = p;
            }
        }
    }
    
}

int main(void){
	int num, i;
	Lista* lis = criar_lista();
	
    scanf("%d", &num);
    while(num != -1){
        if(num != 1 && num > 0){
            destruir_lista(lis);
            lis = criar_lista();
            for(i=1; i<=num; i++){
                inserir_lista(lis, i);
            }
            if(lis->tam != 1){
                printf("Descartadas: ");
                remover_trocar(lis);
                printf("\nRestou: %d\n", lis->inicio->dado);
            }
        }else if(num == 1){
            destruir_lista(lis);
            lis = criar_lista();
            for(i=1; i<=num; i++){
                inserir_lista(lis, i);
            }
            printf("Descartadas: ");
            printf("\nRestou: %d\n", lis->inicio->dado);
        }
        scanf("%d", &num);
    }
    /*
    while(scanf("%d", &num) != EOF){
        if(num != 1){
            destruir_lista(lis);
            lis = criar_lista();
            for(i=1; i<=num; i++){
                inserir_lista(lis, i);
            }
            if(lis->tam != 1){
                printf("Descartadas: ");
                remover_trocar(lis);
                printf("\nRestou: %d\n", lis->inicio->dado);
            }
        }else if(num == 1){
            destruir_lista(lis);
            lis = criar_lista();
            for(i=1; i<=num; i++){
                inserir_lista(lis, i);
            }
            printf("Descartadas: %d", lis->inicio->dado);
            free(lis->inicio);
            lis->inicio = lis->fim = NULL;
            printf("\nRestou: \n");
        }
    }
    */
	destruir_lista(lis);
	return 0;
}