#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


typedef struct no
{
    int Vlr;
    struct no *ant;
}no;

typedef struct pilha
{
   no *topo;
}pilha;

//prototipo das funções
void criar(pilha *p);
int verificar(pilha *p);
void empilhar(pilha *p, int vlr);
void mostrar (pilha *p);
void desempilhar(pilha *p);
void manipular(pilha *p);

#endif // PILHA_H_INCLUDED


