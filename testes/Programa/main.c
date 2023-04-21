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
        printf("1 - Calcular o per�metro do Tri�ngulo.\n");
        printf("2 - Calcular o per�metro do Ret�ngulo.\n");
        printf("3 - Calcular o per�metro do C�rculo.\n");
        printf("4 - Calcular o �rea do Tri�ngulo.\n");
        printf("5 - Calcular o �rea do Tri�ngulo.\n");
        printf("6 - Calcular o �rea do Tri�ngulo.\n");
        printf("7 - Sair.\n");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("\nDigite os lados do tri�ngulo: [x,y,z] ");
            scanf("%d,%d,%d", &a, &b, &c);
            fflush(stdin);
            printf("\nO per�metro do Tri�ngulo �: %.2f\n", CalPerimetroTri(a, b, c));
            system("pause");
            break;

        case 2:
            printf("\nDigite os lados do ret�ngulo: [x,y]");
            scanf("%d,%d", &a, &b);
            fflush(stdin);
            printf("\nO per�metro do ret�ngulo �: %.2f\n", CalPerimetroRet(a, b));
            system("pause");
            break;

        case 3:
            printf("\nDigite o raio do C�rculo: [x]");
            scanf("%d", &r);
            fflush(stdin);
            printf("\nO per�metro do c�rculo �: %.2f\n", CalPerimetroCir(r));
            system("pause");
            break;

        case 4:
            printf("\nDigite os lados do tri�ngulo: [x,y] ");
            scanf("%d,%d", &b, &a);
            fflush(stdin);
            printf("\nA �rea do tri�ngulo �: %.2f\n", CalAreaTri(b, a));
            system("pause");
            break;

        case 5:
            printf("\nDigite os lados do ret�ngulo: [x,y]");
            scanf("%d,%d", &b, &a);
            fflush(stdin);
            printf("\nA �rea do ret�ngulo �: %.2f\n", CalAreaRet(b, a));
            system("pause");
            break;

        case 6:
            printf("\nDigite o raio do c�rculo: [x]");
            scanf("%d", &r);
            fflush(stdin);
            printf("\nA �rea do c�rculo �: %.2f\n", CalAreaCir(r));
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