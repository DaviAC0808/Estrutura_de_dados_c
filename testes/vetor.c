#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");

    int n;

    // vet={1,2,3,4,5}; erro
    float med;

    printf("Quantas posi��es voce quer? ");
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
    printf("\nA m�dia dos valores � %f!\n", med);
}
