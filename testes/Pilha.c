#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int op;

    do
    {
        printf("1_ Empilhar\n");
        printf("2_ Desempilhar\n");
        printf("0_ Sair\n");
        fflush(stdin);
        scanf("%d", &op);

        system("cls");

        switch (op)
        {
        case 0:
            break;
        case 1:
            printf("\nOpção 1");
            break;
        case 2:
            printf("\nOpção 2");
            break;

        default:
            printf("\nOpção inválida!\n");
            break;
        }
    } while (op != 0);
}