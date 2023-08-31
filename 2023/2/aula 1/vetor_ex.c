#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 5

void add(int *vet2)
{
    int *vet1 = malloc(sizeof(int) * MAX);
    for (int i = 0; i < MAX; i++)
    {
        printf("Informe o valor de vet1 [%d]: ", i);
        scanf("%d", &vet1[i]);
    }

    for (int i = 0; i < MAX; i++)
    {
        vet2[i] = vet1[i] + 15;
    }

    free(*vet1);
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int vet2[MAX];

    add(vet2);

    printf("\n\n");

    printf("\n=======Vet 2=======\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("vet2 [%d] = %d\n", i, vet2[i]);
    }

}