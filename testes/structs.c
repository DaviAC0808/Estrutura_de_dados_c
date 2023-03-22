#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[5]={1,2,3,4,5};
    //vet={1,2,3,4,5}; erro

    for (int i = 0; i < 5; i++)
    {
        printf("Insira o elemento da posicao %d: ", i);
        scanf("%d ", &vet[i]);
    }
    

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", vet[i]);
    }
}
