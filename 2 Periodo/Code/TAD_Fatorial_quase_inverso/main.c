#include <stdio.h>
#include "fatorial.h"

int main (void){
    int n;

    while( scanf("%d", &n) != EOF){
        if(fatMax(n) == n){
            printf("%d\n", fatMax(n));
        }
    }

    return 0;
}