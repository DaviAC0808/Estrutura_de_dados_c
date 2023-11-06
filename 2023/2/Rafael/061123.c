#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct dados
{
    char nome;
    int matricula;
    float cpf[11];

}dados;

typedef struct no
{
    dados *Funcionario;
    struct no *prox;
}no;

typedef struct Fila
{
    no *inicio;
    no *fim;
}fila;



int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int;

    printf("\n\n");
    // scanf("%", );
}