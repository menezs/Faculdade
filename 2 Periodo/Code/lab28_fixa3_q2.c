#include <stdio.h>

int main(void){
    int mat[5][5];
    int i, j, linha, col;

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
    
            if(i==2 && j==2){
                mat[i][j]=16;
            }else if( i==0 || j==0 || i==4 || j==4 ){
                mat[i][j]=2;
            }else if(i==1 || j==1 || i== 3 || j==3){
                mat[i][j]=8;
            }
            if( (i==0 && j==0) || (i==0 && j==4) || (i==4 && j==0) || (i==4 && j==4)){
                mat[i][j]=0;
            }
            if( ( i==1 && j==1) || (i==1 && j==3) || (i==3 && j==1) || (i==3 && j==3) ){
                mat[i][j]=5;
            }
            
        }
    }


    scanf("%d%d", &linha, &col);
    linha -= 1;
    col -=
    printf("%d\n", mat[linha][col]);

    return 0;
}