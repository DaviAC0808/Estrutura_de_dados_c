#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");
    float a, b, res;

    printf("Digite o 1� valor: ");
    scanf("%f", &a);

    printf("Digite o 2� valor: ");
    scanf("%f", &b);

    res = a+b;
    printf("a soma dos valores � %f.", res); 

    return 0;
}
