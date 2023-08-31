#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// #define MAX 3

typedef struct endereco
{
    char rua;
    int numero;
    char bairro;
}endereco;


typedef struct aluno
{
    int cod;
    char nome[50];
    endereco endereco;
} aluno;

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int x;

    printf("Informe a quantidade de alunos: ");
    scanf("%d", &x);

    aluno *p = malloc(x * sizeof(aluno));

    for (int i = 0; i < x; i++)
    {

        printf("\nInforme o cod: ");
        scanf("%d", &p->cod);

        printf("Informe o nome: ");
        fflush(stdin);
        fgets(p->nome, 50, stdin);

        printf("Informe o endereço\n");
        printf("Rua: ");
        fflush(stdin);
        gets(p->endereco.rua);
    }

    printf("\n\n =================== Dados =================== \n\n");

    for (int i = 0; i < x; i++)
    {
        printf("Código: %d\n", p->cod);
        printf("Nome: %s\n", p->nome);
    }
    free(p);
}