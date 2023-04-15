#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct produto
{
    int cod;
    float valor;
};

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    struct produto p;
    int n, erro;

    printf("1_ Cadarstrar produto.\n");
    printf("2_ Ler produto.\n");
    printf("0_ Sair.\n\n");
    scanf("%d", &n);

    while (n != 0)
    {
        if (n < 0 || n > 2)
        {
            printf("Valor inválido, digite o valor novamente.\n\n");
            scanf("%d", &n);
        }

        if (n == 1)
        {
            printf("\nDigite o código do produto: ");
            scanf("%d", &p.cod);

            printf("\nDigite o valor do produto: ");
            scanf("%f", &p.valor);

            printf("\n\n1_ Cadarstrar produto.\n");
            printf("2_ Ler produto.\n");
            printf("0_ Sair.\n\n");
            scanf("%d", &n);
        }

        if (n == 2 && p.cod != 0)
        {
            printf("\nCódigo do produto: %d\n", p.cod);
            printf("Valor: R$%.2f\n", p.valor);

            printf("\n\n1_ Cadarstrar produto.\n");
            printf("2_ Ler produto.\n");
            printf("0_ Sair.\n\n");
            scanf("%d", &n);

        }else{
            printf("escaneie o produto e tente novamente.");

            printf("\n\n1_ Cadarstrar produto.\n");
            printf("2_ Ler produto.\n");
            printf("0_ Sair.\n\n");
            scanf("%d", &n);

        }
    }

    printf("Saindo...");
}
