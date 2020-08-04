#include<stdio.h>
#include<stdlib.h>
#include"fatorial.h"

int fatMax(int n){
    int i, fat=1;
    for(i=1; i<=(2*n); i++){
        fat = fat * i;
        if(fat >= n){
            break;
        }
    }
    return fat;
}