
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

pilha* createpilha(pilha *p){
    p->topo=NULL;
    return p;
}


void empilha(pilha *p,int valor){

  Tpilha *novo=(Tpilha*)malloc(sizeof(Tpilha));

  novo->item = valor;    //inserindo o valor
  novo->ant = p->topo;
  p->topo = novo;       //ponteiro topo aponta p/ novo

  return;

}

int pilha_vazia(pilha *p){
  if(p->topo == NULL){
    return 1; //pilha está vazia
  }else{
   return 0; //pilha tem elementos
  }

}

int desempilha(pilha *p){

  int valor;

  Tpilha *aux = (Tpilha*)malloc(sizeof(Tpilha));

  aux = p->topo;//aponta para a mesma direção do topo

  valor = aux->item;//guarda o valor desempilhado

  p->topo  = aux->ant;// abaixando o ponteiro do topo
  aux->ant = NULL;

  free(aux);

  return valor;

}

void mostra_pilha(pilha *p){

  if(pilha_vazia(p)==1){
    printf("pilha vazia!!!");

  }else{

     Tpilha *aux;
     aux=p->topo; //aponta para o topo

     while(aux!=NULL){
        printf("%d \n",aux->item); //mostrar o valor
        aux=aux->ant;
     }

     free(aux);
  }
}



