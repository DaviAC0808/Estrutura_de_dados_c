#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct ponto
{
    int x;
    int y;
};

struct reta
{
    struct ponto inicio;
    struct ponto fim;
};

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