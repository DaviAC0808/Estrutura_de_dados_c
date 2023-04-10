#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, res;

    printf("Digite o 1º valor: ");
    scanf("%f", &a);

    printf("Digite o 2º valor: ");
    scanf("%f", &b);

    res = a+b;
    printf("a soma dos valores é %f.", res); 

    return 0;
}
