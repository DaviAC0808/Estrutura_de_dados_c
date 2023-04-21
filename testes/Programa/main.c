#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "poligonos.h"
#include "poligonos.c"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int n, a, b, c, r;

    printf("\n======POLIGONOS======\n");
    system("pause");
    do
    {
        system("cls");
        printf("1 - Calcular o perímetro do Triângulo.\n");
        printf("2 - Calcular o perímetro do Retângulo.\n");
        printf("3 - Calcular o perímetro do Círculo.\n");
        printf("4 - Calcular o área do Triângulo.\n");
        printf("5 - Calcular o área do Triângulo.\n");
        printf("6 - Calcular o área do Triângulo.\n");
        printf("7 - Sair.\n");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("\nDigite os lados do triângulo: [x,y,z] ");
            scanf("%d,%d,%d", &a, &b, &c);
            fflush(stdin);
            printf("\nO perímetro do Triângulo é: %.2f\n", CalPerimetroTri(a, b, c));
            system("pause");
            break;

        case 2:
            printf("\nDigite os lados do retângulo: [x,y]");
            scanf("%d,%d", &a, &b);
            fflush(stdin);
            printf("\nO perímetro do retângulo é: %.2f\n", CalPerimetroRet(a, b));
            system("pause");
            break;

        case 3:
            printf("\nDigite o raio do Círculo: [x]");
            scanf("%d", &r);
            fflush(stdin);
            printf("\nO perímetro do círculo é: %.2f\n", CalPerimetroCir(r));
            system("pause");
            break;

        case 4:
            printf("\nDigite os lados do triângulo: [x,y] ");
            scanf("%d,%d", &b, &a);
            fflush(stdin);
            printf("\nA área do triângulo é: %.2f\n", CalAreaTri(b, a));
            system("pause");
            break;

        case 5:
            printf("\nDigite os lados do retângulo: [x,y]");
            scanf("%d,%d", &b, &a);
            fflush(stdin);
            printf("\nA área do retângulo é: %.2f\n", CalAreaRet(b, a));
            system("pause");
            break;

        case 6:
            printf("\nDigite o raio do círculo: [x]");
            scanf("%d", &r);
            fflush(stdin);
            printf("\nA área do círculo é: %.2f\n", CalAreaCir(r));
            system("pause");
            break;

        default:
            if (n == 7)
            {
                printf("Saindo...");
            }
            else
            {
                printf("\nValor incorreto, tente novamente.\n");
                system("pause");
            }
        }
    } while (n != 7);

    return 0;
}