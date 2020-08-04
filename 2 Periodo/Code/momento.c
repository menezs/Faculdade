#include <stdio.h>

int main(void){
    double velFinal=0.0, velZero;
    double massaA, massaB;

    scanf("%lf%lf%lf", &massaA, &massaB, &velZero);
    velFinal = ((2*massaA + massaB)/(massaA + massaB)) * velZero;
    printf("%.15f", velFinal);

    return 0;
}