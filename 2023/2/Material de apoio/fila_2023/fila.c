#include <stdio.h>
#include <stdlib.h>

// #include "fila.h"
// #include "pilha.h"

typedef struct Tpilha
{
  int item;
  struct Tpilha *ant;
} Tpilha;

// entregador do correio
typedef struct pilha
{
  Tpilha *topo;
} pilha;

typedef struct Tfila
{
  int valor;
  struct Tfila *prox;
} Tfila;

typedef struct fila
{
  Tfila *inicio;
  Tfila *fim;
} fila;
void create_fila(fila *f)
{
  f->inicio = NULL;
  f->fim = NULL;
}

int fila_vazia(fila *f)
{

  if (f->inicio == NULL)
  {
    return 1;
  }
  else
    return 0;
}

fila *insere_fila(fila *f, int valor)
{

  Tfila *novo = (Tfila *)malloc(sizeof(Tfila));
  novo->valor = valor;
  novo->prox = NULL;

  if (fila_vazia(f) == 1)
  { // primeiro elemento
    f->inicio = novo;
    f->fim = novo;
  }
  else
  {
    f->fim->prox = novo;
    f->fim = novo;
  }
  novo = NULL;
  free(novo);
  return f;
}

int remove_fila(fila *f)
{
  int x;

  Tfila *aux = f->inicio;

  f->inicio = aux->prox;
  aux->prox = NULL;

  if (f->inicio == NULL)
  {
    f->fim = NULL;
  }

  x = aux->valor;
  free(aux);

  return x;
}

void mostra_fila(fila *f)
{

  Tfila *aux = f->inicio;

  while (aux != NULL)
  {
    printf("| %d", aux->valor);
    aux = aux->prox;
  }
}

// void fila_pilha(fila *f, pilha *p)
// {
//   int valor;

//   while (!fila_vazia(f))
//   {
//     valor = remove_fila(f);
//     empilha(p, valor);
//   }

//   while (fila_vazia(f) != 1)
//   {
//     valor = remove_fila(f);
//     empilha(p, remove_fila(f));
//   }
  return 0;
}
