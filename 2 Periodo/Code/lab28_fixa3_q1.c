#include <stdio.h>

typedef struct tempo Tempo;
struct tempo{
    int hora;
    int min;
    int seg;
};
void converte(Tempo* temp, int entrada){
    temp->hora = entrada/(60*60);
    if(((temp->hora*3600) - entrada) == 0){
        temp->min = temp->seg = 0;
    }else{
        temp->min = (entrada - (temp->hora*3600))/60;
        if((entrada - (temp->hora*3600)) - (temp->min*60) == 0){
            temp->seg = 0;
        }else{
            temp->seg = (entrada - (temp->hora*3600)) - (temp->min*60);
        }
    }
    
}
int main(void){
    int entrada;
    Tempo temp;

    while( scanf("%d", &entrada) != EOF){
        converte(&temp, entrada);
        if(temp.hora<10 && temp.min<10 && temp.seg<10){
            printf("0%d:0%d:0%d\n", temp.hora, temp.min, temp.seg);
        }else if(temp.min<10 && temp.seg<10){
            printf("%d:0%d:0%d\n", temp.hora, temp.min, temp.seg);
        }else if(temp.hora<10 && temp.min<10){
            printf("0%d:0%d:%d\n", temp.hora, temp.min, temp.seg);
        }else if(temp.hora<10 && temp.seg<10){
            printf("0%d:%d:0%d\n", temp.hora, temp.min, temp.seg);
        }else if(temp.hora<10){
            printf("0%d:%d:%d\n", temp.hora, temp.min, temp.seg);
        }else if(temp.min<10){
            printf("%d:0%d:%d\n", temp.hora, temp.min, temp.seg);
        }else if(temp.seg<10){
            printf("%d:%d:0%d\n", temp.hora, temp.min, temp.seg);
        }else{
            printf("%d:%d:%d\n", temp.hora, temp.min, temp.seg);
        }
    }

    return 0;
}