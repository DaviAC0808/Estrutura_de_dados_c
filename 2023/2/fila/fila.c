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

void insere_primeiro(fila *f, int vlr){
    
}

void insere(fila *f, int vlr)
{

}

int remove(fila *f)
{
    int x;
    no *aux = malloc(sizeof(no));

    aux = f->inicio;
    f->inicio = aux->prox; // ou f->inicio = f->inicio->prox
    aux->prox = NULL;

    if (f->inicio = NULL)
    {
        f->fim = NULL;
    }

    x = aux->Vlr;
    free(aux);
    return x;
}

int mostrar(fila *f){
    
    // no *aux = malloc(sizeof(no));
    // f->inicio = aux;

    // while (aux != NULL)
    // {
    //     printf("%d", f->inicio)
    // }
    
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int;

    printf("\n\n");
    // scanf("%", );
}