#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct produto
{
    float x;
    int qnt;
}produto;

typedef struct estoque
{
    struct ponto inicio;
    struct ponto fim;
}estoque;

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    struct carro c[10];

    struct carro novoCarro;
    novoCarro = CriaNovoCarro();

    mostrar_carros(c, 10);

    printf("\n\n");
    // scanf("%", );
}