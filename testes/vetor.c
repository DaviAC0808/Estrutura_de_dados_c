#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i, n;

    // vet={1,2,3,4,5}; erro
    float med;

    printf("Quantas posições voce quer? ");
    scanf("%d", &n);

    // Vetor
    int vet[n];

    for (int i = 0; i < n; i++)
    {
        printf("Insira o elemento da posicao %d: ", i);
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
        med +=vet[i];
    }

    med = med /n;   
    printf("\n%f\n", med);
}
