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
    setlocale(LC_ALL, "Portuguese");

    struct produto p = {0, 0.0};
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

        if (n == 2)
        {
            printf("%d\n", p.cod);
            printf("R$%.2f\n", p.valor);

            printf("\n\n1_ Cadarstrar produto.\n");
            printf("2_ Ler produto.\n");
            printf("0_ Sair.\n\n");
            scanf("%d", &n);
        }
    }

    printf("Saindo...");
}
