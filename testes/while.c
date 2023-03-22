#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var;

    printf("Digite um valor entre 0 e 10: ");
    scanf("%d", &var);

    //inicio de 'while'
    while (var < 0 || var > 10)
    {
        printf("Valor invalido, digite o valor novamente.\n\n");
        scanf("%d", &var);
    }

    printf("\nO valor %d foi inserido com sucesso.\n", var);

    printf("\n\n--------------------\n\n");

    // inicio de 'do while'
    do
    {
        if (var < 0 || var > 10)
        {
            printf("Valor invalido, digite o valor novamente.\n\n");
        }        
        printf("Digite um valor entre 0 e 10: ");
        scanf("%d", &var);
    } while (var < 0 || var > 10);

    printf("\nO valor %d foi inserido com sucesso.\n", var);
}
