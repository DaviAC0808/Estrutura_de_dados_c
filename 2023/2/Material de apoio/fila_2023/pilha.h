#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct Tpilha{
 int item;
 struct Tpilha *ant;
}Tpilha;


//entregador do correio
typedef struct pilha{
  Tpilha *topo;
}pilha;


pilha* createpilha(pilha *p); //função que cria a pilha
void empilha(pilha *p,int valor);//função que empilha elementos

int pilha_vazia(pilha *p); //função que verifica se a pilha está vazia

int desempilha(pilha *p); //função que desempilha elementos

void mostra_pilha(pilha *p); //função que mostra a pilha


#endif // PILHA_H_INCLUDED
