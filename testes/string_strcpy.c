#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define N 20

int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");

    char origem[N] = {"Olá mundo!"};
    char destino[N];

    printf("Antes do strcpy:\n");
    puts(origem);
    puts(destino);
    
    strcpy(destino,origem);//duplica o valor de uma string

    printf("\nDepois de ctrpty: \n");
    puts(origem);
    puts(destino);

    return 0;
}

