#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no
{
    int Vlr;
    struct no *prox;
} no;

typedef struct fila
{
    struct fila *inicio;
    struct fila *fim;
} fila;

void criar(fila *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

int verificar(fila *f)
{
    if (f->inicio == NULL && f->fim == NULL)
    {
        printf("\nFila vazia!\n");
        return 0;
    }
    else
    {
        return 1;
    }
}



int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int;

    printf("\n\n");
    // scanf("%", );
}