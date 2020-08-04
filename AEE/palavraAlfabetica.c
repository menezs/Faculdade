#include <stdio.h>
#include <string.h>

void troca(char* palavra, int ant, int prox){
    char temp = palavra[ant];
    palavra[ant]=palavra[prox];
    palavra[prox]=temp;
}
int hoare(char* palavra, int in, int fim){
    int meio = (in+fim)/2;
    char pivo = palavra[meio];
    int i=in-1, j=fim+1;

    while (1){
        do{
            i++;
        } while (palavra[i]<pivo);
        do{
            j--;
        } while (palavra[j]>pivo);
        if(i < j){
            troca(palavra, i, j);
        }else if(i>= j){
            return j;
        }
    }
}

void quickSort(char* palavra, int in, int fim){
    int corte;
    if(fim > in){
        corte = hoare(palavra, in, fim);
        quickSort(palavra, in, corte);
        quickSort(palavra, corte+1, fim);
    }
}
void colocarMinPrimeiro(char* palavra, int tam){
    int i;
    for(i=0; i<tam-1; i++){
        if( (palavra[i+1]-palavra[i])==32 ){
            troca(palavra, i, i+1);
        }
    }
}
int main(void){
    char palavra[100];

    scanf("%s", palavra);
    quickSort(palavra, 0, strlen(palavra)-1);
    colocarMinPrimeiro(palavra, strlen(palavra));
    printf("%s\n", palavra);

    return 0;
}