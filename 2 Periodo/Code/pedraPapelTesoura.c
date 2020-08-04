#include <stdio.h>

int main(void){
    int n, i=0, primeiro=0, segundo=0;
    int vet1[20], vet2[20];

    scanf("%d", &vet1[i]);
    while (vet1[i] > 0){
        i++;
        scanf("%d", &vet1[i]);
    } 
    n=i;

    i=0;
    scanf("%d", &vet2[i]);
    while (vet2[i] > 0){
        i++;
        scanf("%d", &vet2[i]);
    }

    i=0;
    while(vet1[i] > 0 && vet2[i] > 0){
        if(vet1[i] == 11 && vet2[i] == 33){
            primeiro++;
        }else if(vet1[i] == 33 && vet2[i] == 22){
            primeiro++;
        }else if(vet1[i] == 22 && vet2[i] == 11){
            primeiro++;
        }else if(vet2[i] == 11 && vet1[i] == 33){
            segundo++;
        }else if(vet2[i] == 33 && vet1[i] == 22){
            segundo++;
        }else if(vet2[i] == 22 && vet1[i] == 11){
            segundo++;
        }
        i++;
    }
    if(primeiro>segundo){
        printf("%d\nEUSAPIA", n);
    }else if(segundo>primeiro){
        printf("%d\nBARSANULFO", n);
    }else{
        printf("%d\nEMPATE", n);
    }
    return 0;
}