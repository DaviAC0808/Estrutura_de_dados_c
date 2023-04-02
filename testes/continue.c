#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, v;

    printf("Digite um valor [0,10] a ser excluido: ");
    scanf("%d", &v);

    for (int i = 0; i <= 10; i++)
    {
        if (i == v)
        {
            continue; // exclui o valor de v
        }

        printf("%d ", i);
    }
}