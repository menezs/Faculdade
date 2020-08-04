#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int* inicializa(int x){
    int i;
	int* vet = (int*)malloc(x*sizeof(int));
    if(vet == NULL){
        exit(1);
    }
	for(i=0; i<x; i++){
		vet[i]=0;
	}
    return vet;
}
void libera(int *vet){
	free(vet);
}
void set_vetor(int* vet, int a, int b, int x){
    int i;
    for(i=a; i<=b; i++){
        vet[i]=x;
    }
}
void seq_vetor(int* vet, int a, int b){
    int i, cont=0;
    for(i=a; i<=b; i++){
        vet[i]=cont;
        cont++;
    }
}
void troca(int* vet, int a, int b){
    int temp;
    temp=vet[a];
    vet[a]=vet[b];
    vet[b]=temp;
}
void rev_vetor(int* vet, int a, int b){
    int cont, k=0, i=a, j=b;
    
    for(cont=a; cont<=b; cont++){
        k++;
    }
    if(k%2 == 0){
        for(cont=0; cont<=(k/2)-1; cont++){
            troca(vet, i, j);
            i++;
            j--;
        }
    }else{
        for(cont=0; cont<=k/2; cont++){
            troca(vet, i, j);
            i++;
            j--;
        }
    }
}
void add_vetor(int* vet, int a1, int b1, int a2){
    int i, j=a2;
    for(i=a1; i<=b1; i++){
        vet[i] = vet[i]+vet[j];
        j++;
    }
}
void sum_vetor(int* vet, int a, int b, int z){
    int i, temp=0;
    for(i=a; i<=b; i++){
        temp = temp + vet[i];
    }
    vet[z]=temp;
}
void prt_vetor(int* vet, int a, int b){
    int i;
    for(i=a; i<=b; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}
int main(void){
	int a, b, x, z;
    int a1, a2, b1, b2;
	char comando[10];
   
	scanf("%s ", comando);
    scanf("%d", &x);
    int* vet = inicializa(x);
	while(strcmp(comando, "hlt") != 0){
	    if(strcmp(comando, "set") == 0){
			scanf("%d%d%d", &a, &b, &x);
            set_vetor(vet, a, b, x);
		}else if(strcmp(comando, "seq") == 0){
			scanf("%d%d", &a, &b);
            seq_vetor(vet, a, b);
		}else if(strcmp(comando, "rev") == 0){
            scanf("%d%d", &a, &b);
			rev_vetor(vet, a, b);
		}else if(strcmp(comando, "add") == 0){
			scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
            add_vetor(vet, a1, b1, a2);
		}else if(strcmp(comando, "sum") == 0){
			scanf("%d%d%d", &a, &b, &z);
            sum_vetor(vet, a, b, z);
		}else if(strcmp(comando, "prt") == 0){
            scanf("%d%d", &a, &b);
			prt_vetor(vet, a, b);
		}
		scanf("%s", comando);
	}

	libera(vet);
	return 0;
}