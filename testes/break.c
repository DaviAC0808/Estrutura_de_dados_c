#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, v;

    printf("Digite um valor [0,10] para abortar a missao: ");
    scanf("%d", &v);

    for (int i = 0; i <= 10; i++)
    {
        printf("%d ", i);
        if (i == v)
        {
            break;
        }
    }
}