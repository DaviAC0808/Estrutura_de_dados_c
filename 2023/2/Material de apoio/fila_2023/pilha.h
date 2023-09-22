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


pilha* createpilha(pilha *p); //fun��o que cria a pilha
void empilha(pilha *p,int valor);//fun��o que empilha elementos

int pilha_vazia(pilha *p); //fun��o que verifica se a pilha est� vazia

int desempilha(pilha *p); //fun��o que desempilha elementos

void mostra_pilha(pilha *p); //fun��o que mostra a pilha


#endif // PILHA_H_INCLUDED
