#include <stdio.h>

int confereAd(int ordem, int mat[][ordem], int i, int j){
    int saida=0;
    if(mat[i][j] == 9){
        saida = 100;
    }else{
        if(mat[i][j] == 0 ){
            if(mat[i][j+1] == 9){
                saida++;
            }
            if(mat[i][j-1] == 9){
                saida++;
            }
            if(mat[i+1][j] == 9){
                saida++;
            }
            if(mat[i-1][j] == 9){
                saida++;
            }
            if(mat[i+1][j-1] == 9){
                saida++;
            }
            if(mat[i+1][j+1] == 9){
                saida++;
            }
            if(mat[i-1][j+1] == 9 ){
                saida++;
            }
            if(mat[i-1][j-1] == 9){
                saida++;
            }
        }
    }

    return saida;
}

int main(void){
    int i, j;
    int ordem;

    scanf("%d", &ordem);
    ordem += 2;
    int mat[ordem][ordem];
    for(i=0; i<ordem; i++){
        for(j=0; j<ordem; j++){
            if(i==0 || j==(ordem-1) || i==(ordem-1) || j==0 ){
                mat[i][j] = 99;
            }else{
                scanf("%d", &mat[i][j]);
            }
        }
    }

    for(i=1; i<ordem-1; i++){
        for(j=1; j<ordem-1; j++){
            if(confereAd(ordem, mat, i, j) == 100){
                printf("*");
            }else if(confereAd(ordem, mat, i, j) == 0){
                printf(".");
            }else{
                printf("%d", confereAd(ordem, mat, i, j));
            }
        }
        printf("\n");
    }


    return 0;
}


