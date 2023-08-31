#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 10



int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int *vet = malloc(sizeof(int) * MAX);

    for (int i = 0; i < MAX; i++)
    {
        printf("\ninforme o valor de [%d]: \n", i);
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < MAX; i++)
    {
        printf("\nVet [%d] = %d", i, vet[i]);
    }

    free(vet);

}