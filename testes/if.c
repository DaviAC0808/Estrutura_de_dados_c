#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var;

    printf("\n Digite um numero entre 0 e 10: ");
    scanf("%d", &var);

    // e == &&
    if (var >= 0 && var <= 10)
    {
        printf("\nO numero %d foi inserido\n", var);
    }

    // ou == ||
    if (var < 0 || var > 10)
    {
        printf("Valor invalido.");
    }
}
