#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void imprime1(int v[], int n)  //Jeito 1
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}

void imprime2(int *v, int n);//protótipo de função (Jeito 2)


void imprime3(int v[5])       //Jeito 3
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("%d ", v[i]);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int vet[5] = {1, 2, 3, 4, 5};

    puts("Primeiro imprime: ");
    imprime1(vet, 5);

    puts("\nSegundo imprime: ");
    imprime2(vet, 5);

    puts("\nTerceiro imprime: ");
    imprime3(vet);

    return 0;
}

void imprime2(int *v, int n)    //Jeito 2
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}