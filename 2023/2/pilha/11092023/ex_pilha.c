#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ex_pilha.h"

void criar(pilha *p)
{
    p->topo = NULL;
}

int verificar(pilha *p)
{
    if (p->topo == NULL)
    {
        printf("\nA pilha está vazia!\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

void empilhar(pilha *p, int vlr)
{
    no *novo = malloc(sizeof(no));

    novo->Vlr = vlr;
    novo->ant = p->topo;
    p->topo = novo;

    novo = NULL;
    free(novo);
}

void desempilhar(pilha *p)
{
    no *aux;
    aux = p->topo;
    p->topo = aux->ant;
    aux->ant = NULL;
    free(aux);
}

void mostrar(pilha *p)
{

  // if(verificar(p)){

  if (verificar(p) == 0)
  {

    no *aux;
    aux = p->topo;

    while (aux != NULL)
    {
      printf("\n %d", aux->Vlr);
      aux = aux->ant;
    }
  }
  else
  {
    printf("Pilha Vazia !!!\n");
  }
}