#include <stdio.h>
#include <stdlib.h>

int main()
{
    float m;

    printf("Digite a nota do aluno:\n");
    scanf("%f",&m);

    if (m >= 7.0)
    {
        printf("Aluno aprovado!!\n");
    }else
    {
        printf("Aluno reprovado.\n");
    }

}
