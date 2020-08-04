#include<stdio.h>
#include<math.h>
float converte(int n1, int n2, float valor){
    float saida=0.0;
    if(n1 == 1){
        if(n2 == 1){
            saida=0.4536*valor;
        }else if(n2 == 2){
            saida=valor/0.4536;
        }else if(n2 == 3){
            saida=28.3495*valor;
        }else if(n2 == 4){
            saida=valor/28.3495;
        }
    }else if(n1 == 2){
        if(n2 == 1){
            saida=3.7854*valor;
        }else if(n2 == 2){
            saida=valor/3.7854;
        }else if(n2 == 3){
            saida=29.5735*valor;
        }else if(n2 == 4){
            saida=valor/29.5735;
        }
    }else if(n1 == 3){
        if(n2 == 1){
            saida=1.6093*valor;
        }else if(n2 == 2){
            saida=valor/1.6093;
        }else if(n2 == 3){
            saida=0.9144*valor;
        }else if(n2 == 4){
            saida=valor/0.9144;
        }
    }
    return saida;
}
int main(void){
    int num1, num2;
    float valor;

    scanf("%d%d%f", &num1, &num2, &valor);
    printf("%.2f", converte(num1, num2, valor));

    return 0;
}