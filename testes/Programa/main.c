#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "poligonos.h"

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int n, a, b, c, r;

    printf("\n======POLIGONOS======\n");
    system("pause");

    printf("1_Calcular o per�metro do Tri�ngulo.\n");
    printf("2_Calcular o per�metro do Ret�ngulo.\n");
    printf("3_Calcular o per�metro do Circulo.\n");
    printf("4_Calcular o �rea do Tri�ngulo.\n");
    printf("5_Calcular o �rea do Tri�ngulo.\n");
    printf("6_Calcular o �rea do Tri�ngulo.\n");
    printf("7_Sair.\n");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        printf("Digite os lados do tri�ngulo: ");
        scanf("%d,%d,%d", &a, &b, &c);
        fflush(stdin);
        float CalPerimetroTri(float a, float b, float c);
        break;
    case 2:
        printf("Digite os lados do tri�ngulo: ");
        scanf("%d,%d", &a, &b);
        fflush(stdin);
        float CalPerimetroRet(float a, float b);
        break;
    case 3:
        printf("Digite os lados do tri�ngulo: ");
        scanf("%d", &r);
        fflush(stdin);
        float CalPerimetroCir(float r);
        break;
    case 4:
        printf("Digite os lados do tri�ngulo: ");
        scanf("%d,%d", &b, &a);
        fflush(stdin);
        float CalAreaTri(float b, float a);
        break;
    case 5:
        printf("Digite os lados do tri�ngulo: ");
        scanf("%d,%d", &b, &a);
        fflush(stdin);
        float CalAreaRet(float b, float a);
        break;
    case 6:
        printf("Digite os lados do tri�ngulo: ");
        scanf("%d", &r);
        fflush(stdin);
        float CalAreaCir(float r);
        break;
    default:
        printf("Valor incorreto, tente novamente.");
    }

    return 0;
}