#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
  0_typedef
  1_cria
  2_verifica
  3_insere
  4_remove
  5_mostra
*/

typedef struct no
{
    int Vlr;
    struct no *prox;
} no;

typedef struct fila_ex
{
    no *inicio;
    no *fim;
} fila;

void criar(fila *f)
{
    f->fim = NULL;
    f->inicio = NULL;
}

int verificar(fila *f)
{
    if (f->inicio == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void inserir(fila *f, int vlr)
{ //inicialza o novo
    no *novo = malloc(sizeof(no));
    novo->Vlr = vlr;
    novo->prox = NULL;

    

}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int;

    printf("\n\n");
    // scanf("%", );
}