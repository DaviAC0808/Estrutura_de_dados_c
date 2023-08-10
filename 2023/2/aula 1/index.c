#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define max 3

typedef struct pessoa
{
    char nome[50];
    char end[50];
    int idade;
} pessoa;

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    pessoa p[3];

    for (int i = 0; i < max; i++)
    {

        printf("Informe o nome: ");
        fflush(stdin);
        gets(p[i].nome);

        printf("informe a idade: ");
        scanf("%d", &p[i].idade);

        printf("informe o endereço: ");
        fflush(stdin);
        gets(p[i].end);
        printf("\n");
    }
    //==========================================

    printf("\n==========Dados==========\n");

    for (int i = 0; i < max; i++)
    {
        printf("\nNome: %s\n", p[i].nome);
        printf("Idade: %d\n", p[i].idade);
        printf("Endereço: %s\n", p[i].end);
    }
}