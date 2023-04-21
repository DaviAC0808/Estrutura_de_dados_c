#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Alocação dinâmica de memoria com a função malloc;
// Retorna um ponteiro para a região de memória alocada ou NULL;

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int *x;

    x = malloc(sizeof(int)); // separa (int)bytes de memória em um endereço

    if (x) //(x != NULL) mas com x é um ponteiro retorna 1 ou 0;
    {
        printf("Alocado com sucesso!\n");
        printf("x = %d\n", *x);
        *x = 50;
        printf("x = %d\n", *x);
    }
    else
    {
        printf("Não foi possivel alocar memória.\n");
    }

    return 0;
}
