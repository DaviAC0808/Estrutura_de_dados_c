#include <stdio.h>
#include <stdlib.h>

struct produto
{
    int cod;
    float valor;
};

int main()
{

    struct produto p;
    int n;

    printf("1_ Cadarstrar produto.\n");
    printf("2_ Ler produto.\n");
    printf("0_ Sair.\n\n");
    scanf("%d", n);

    while (n < 0 || n > 2)
    {
        printf("Valor invalido, digite o valor novamente.\n\n");
        scanf("%d", &n);
    }

    while (n == 1)
    {
        printf("\nDigite o codigo do produto: ");
        scanf("%d", &p.cod);

        printf("\nDigite o valor do produto: ");
        scanf(" %f", &p.valor);

        if (n == 0)
        {
            break;
        }
        
    }

    if (n == 2 && p.cod == 0)
    {
        printf("O programa parou inesperadamente.");
    }
    
    while (n == 2)
    {
        printf("%d", p.cod);
        printf("R$ %.2f", p.valor);
    }
    
}
