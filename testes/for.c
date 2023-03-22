#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var, i;
    for (int i = 0; i < 10; i++)
    {
        printf("%d Digite um valor entre 0 e 10: ");
        scanf("%d",i ,&var);
    }

    printf("\nO valor %i foi inserido com sucesso.\n", &var);
}