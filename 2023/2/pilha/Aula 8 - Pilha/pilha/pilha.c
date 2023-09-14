#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// funções           //2A
void create_pilha(pilha *p)
{
  // 2A->topo=NULL;
  p->topo = NULL;
}

// função pilha vazia
int pilha_vazia(pilha *p)
{

  if (p->topo == NULL)
  {
    return 1; // Pilha está vazia
  }
  else
  {
    return 0; // pilha tem elementos
  }
}

void empilha(pilha *p, int valor)
{

  Tpilha *novo = malloc(sizeof(Tpilha));

  novo->valor = valor;
  novo->ant = p->topo; // anterior aponte para o de baixo

  p->topo = novo;

  novo = NULL;
  free(novo);
  return;
}

void mostrar(pilha *p)
{

  // if(!pilha_vazia(p)){

  if (pilha_vazia(p) == 0)
  {

    Tpilha *aux;
    aux = p->topo;

    while (aux != NULL)
    {
      printf("\n %d", aux->valor);
      aux = aux->ant;
    }
  }
  else
  {
    printf("Pilha Vazia !!!\n");
  }
}

void desempilha(pilha *p)
{

  Tpilha *aux;
  aux = p->topo;
  p->topo = aux->ant;
  aux->ant = NULL;
  free(aux);
}