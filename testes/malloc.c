#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Aloca��o din�mica de memoria com a fun��o malloc;
// Retorna um ponteiro para a regi�o de mem�ria alocada ou NULL;

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int *x;

    x = malloc(sizeof(int)); // separa (int)bytes de mem�ria em um endere�o

    if (x) //(x != NULL) mas com x � um ponteiro retorna 1 ou 0;
    {
        printf("Alocado com sucesso!\n");
        printf("x = %d\n", *x);
        *x = 50;
        printf("x = %d\n", *x);
    }
    else
    {
        printf("N�o foi possivel alocar mem�ria.\n");
    }

    return 0;
}
