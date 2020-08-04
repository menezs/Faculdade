#include <stdio.h>
#include <stdlib.h>

char** mat_cria(){
    int i, j=0;
    char** mat = malloc(10*sizeof(char*));
    for(i=0; i<10; i++){
        mat[i] = malloc(10*sizeof(char));
        for(j=0; j<10; j++){
            mat[i][j] = '\0';
        }
    }
    return mat;
}
void libera(char** mat){
    int i;
    for(i=0; i<10; i++){
        free(mat[i]);
    }
    free(mat);
}
void add_pretas(char** mat, int linha, char coluna){
    int col = coluna - 'A';
    if( linha<10 && linha>=0 && col<10 && col>=0 ){
        if(linha != col && (linha%2 == 0 || col%2 == 0) && mat[linha][col] == '\0'){
            mat[linha][col] = 'p';
        }
    }
}
void add_brancas(char** mat, int linha, char coluna){
    int col = coluna - 'A';
    if( linha<10 && linha>=0 && col<10 && col>=0 ){
        if( linha != col && (linha%2 == 0 || col%2 == 0) && mat[linha][col] == '\0'){
            mat[linha][col] = 'b';
        }
    }
    
}
int mover(char** mat, int linha, char coluna, int linha2, char coluna2){
    char col = coluna - 'A';
    char col2 = coluna2 - 'A';
    int saida=0;

    if( linha2 < 10 && col2 < 10 ){
       if(linha%2 == 0 || col%2 == 0){
            if(mat[linha][col] == 'p' && mat[linha2][col2] == '\0' && (col+1 == col2 || col-1 == col2) && linha2 == linha+1){
                //mat[linha2][col2] = mat[linha][col];
                //mat[linha][col] = '\0';
                saida=1;
            }else if(mat[linha][col] == 'b' && mat[linha2][col2] == '\0' && (col == col2-1 || col-1 == col2) && linha2 == linha-1){
                //mat[linha2][col2] = mat[linha][col];
                //mat[linha][col] = '\0';
                saida=1;
            }
        } 
    }
    return saida;
}
void mat_completo(char** mat){
    int i, j;
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            if(i<=3){
                if(i%2 == 0 && j%2 != 0){
                    mat[i][j] = 'p';
                }
                if(i%2 != 0 && j%2 == 0){
                    mat[i][j] = 'p';
                }
            }
        }
        for(j=9; j>=0; j--){
            if(i>=6){
                if(i%2 == 0 && j%2 != 0){
                    mat[i][j] = 'b';
                }
                if(i%2 != 0 && j%2 == 0){
                    mat[i][j] = 'b';
                }
            }
        }
    }
}

void imprime(char** mat){
    int i, j;
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    int i, lin, lin2, xpretas, xbrancas, xmov;
    char col, col2;

    char** mat = mat_cria();
    scanf("%d%d", &xpretas, &xbrancas);
    if(xpretas == 0){
        mat_completo(mat);
    }else{
        for(i=0; i<xpretas; i++){
            scanf("%d%c", &lin, &col);
            add_pretas(mat, lin, col);
        }
        for(i=0; i<xbrancas; i++){
            scanf("%d%c", &lin, &col);
            add_brancas(mat, lin, col);
        }
    }
    scanf("%d", &xmov);
    for(i=0; i<xmov; i++){
        scanf("%d%c %d%c", &lin, &col, &lin2, &col2);
        printf("%d%c %d%c: ", lin, col, lin2, col2);
        if(mover(mat, lin, col, lin2, col2)){
            printf("ok\n");
        }else{
            printf("invalido\n");
        }      
    }
    return 0;
}