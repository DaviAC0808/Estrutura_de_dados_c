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
        printf("3 - Calcular o perímetro do Circulo.\n");
        printf("4 - Calcular o área do Triângulo.\n");
        printf("5 - Calcular o área do Triângulo.\n");
        printf("6 - Calcular o área do Triângulo.\n");
        printf("7 - Sair.\n");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Digite os lados do triângulo: ");
            scanf("%d,%d,%d", &a, &b, &c);
            fflush(stdin);
            printf("Perímetro do Triângulo: %.2f\n", CalPerimetroTri(a, b, c));
            system("pause");
            break;

        case 2:
            printf("Digite os lados do triângulo: ");
            scanf("%d,%d", &a, &b);
            fflush(stdin);
            printf("O perímetro do retângulo é: %.2f", CalPerimetroRet(a, b));
            system("pause");
            break;

        case 3:
            printf("Digite os lados do triângulo: ");
            scanf("%d", &r);
            fflush(stdin);
            printf("O perímetro do círculo é: %.2f", CalPerimetroCir(r));
            system("pause");
            break;

        case 4:
            printf("Digite os lados do triângulo: ");
            scanf("%d,%d", &b, &a);
            fflush(stdin);
            printf("A área do triângulo é: %.2f", CalAreaTri(b, a));
            system("pause");
            break;

        case 5:
            printf("Digite os lados do triângulo: ");
            scanf("%d,%d", &b, &a);
            fflush(stdin);
            printf("A área do retângulo é: %.2f", CalAreaRet(b, a));
            system("pause");
            break;

        case 6:
            printf("Digite os lados do triângulo: ");
            scanf("%d", &r);
            fflush(stdin);
            printf("A área do circulo é: %.2f", CalAreaCir(r));
            system("pause");
            break;

        default:
            printf("Valor incorreto, tente novamente.");
        }
    } while (n != 7);

    return 0;
}