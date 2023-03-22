#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var;

    printf("digite um valor entre 0 e 10: \n");
    scanf("%d",&var);

    while (var < 0 || var > 10)
    {
        printf("Valor invalido, digite o valor novamente.\n");
        scanf("%d", &var);

    }

    printf("O valor %d foi inserido com sucesso.", var);
}
