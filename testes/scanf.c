#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");

    int var;

    printf("Digite um dado:");
    scanf("%d", &var);

    printf("O valor do dado é: %d", var);


}
