#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct reg_end
{
    int num;
    char rua;
    char bairro;
} reg_end;

struct aluno
{
    int cpf;
    char nome;
    char sexo;
    struct reg_end ende;

} aluno;

int main()
{
    struct aluno aluno;
    setlocale(LC_ALL, "Portuguese_Brazil");
    int n;

    printf("\nQuantos alunos existem? \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Endereço: ");
        fflush(stdin);
        gets(aluno.ende.num);
        printf("\nNumero: %d\n", aluno.ende.num);
    }
}