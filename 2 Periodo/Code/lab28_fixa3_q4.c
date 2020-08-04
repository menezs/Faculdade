#include <stdio.h>

int congruenciaZeller(int dia, int mes, int ano){
    int saida;
    int seculo = ano/100;
    saida = ( dia+(13*(mes+1)/5)+ano%100+((ano%100)/4)+(seculo/4)+5*(seculo) )%7;

    return saida;
}
int main(void){
    int dia, mes, ano;

    scanf("%d%d%d", &dia, &mes, &ano);
    if(mes == 1 || mes == 2){
        mes += 12;
        ano -= 1;
    }
    switch (congruenciaZeller(dia, mes, ano)){
        case 0:
            printf("sabado\n");
            break;
        case 1:
            printf("domingo\n");
            break;
        case 2:
            printf("segunda-feira\n");
            break;
        case 3:
            printf("terca-feira\n");
            break;
        case 4:
            printf("quarta-feira\n");
            break;
        case 5:
            printf("quinta-feira\n");
            break;
        case 6:
            printf("sexta-feira\n");
            break;
    }
    return 0;
}