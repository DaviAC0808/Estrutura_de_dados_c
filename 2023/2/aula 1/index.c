#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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

    

    printf("Informe o nome: ");
    fflush(stdin);
    gets(p.nome);

    printf("informe a idade: ");
    scanf("%d", &p.idade);
    
    printf("informe o endereço: ");
    fflush(stdin);
    gets(p.end);

//==========================================

printf("\n==========Dados==========\n");

printf("Nome: %s\n", p.nome);
printf("Idade: %d\n", p.idade);
printf("Endereço: %s\n", p.end);

}