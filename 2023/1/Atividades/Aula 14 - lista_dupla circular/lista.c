#include <stdio.h>
#include <stdlib.h>

#include "lista.h"


void create_lista(lista *l){
 l->inicio = NULL;
 l->fim = NULL;
}

int lista_vazia(lista *l){

 if(l->inicio ==NULL){
    return 1;
 }else{
    return 0;
 }
}

void inserir_ini_lista(lista *l, int valor){

  //criar um novo nó
  no *novo=(no*)malloc(sizeof(no));
  novo->dado = valor;
  novo->prox =novo;
  novo->ant =novo;

  if(lista_vazia(l)){ //Primeiro no lista
      l->inicio = novo;
      l->fim = novo;
  }else{

     novo->prox = l->inicio;
     l->inicio->ant = novo;
     l->inicio = novo;

     novo->ant = l->fim; //circular
     l->fim->prox = novo; //circular
  }
}


void inserir_fim_lista(lista *l, int valor){

  //criar novo no
  no *novo=(no*)malloc(sizeof(no));
  novo->dado = valor;
  novo->prox = novo;
  novo->ant = novo;

  if(l->inicio == NULL){ //Primeira vez no lista
   l->inicio = novo;
   l->fim = novo;

  }else{

    l->fim->prox = novo;
    novo->ant = l->fim;
    l->inicio->ant = novo;  //circular
    novo->prox = l->inicio; //circular

    l->fim = novo; //ajusta o ponteiro fim

  }

}


int  remove_ini_lista(lista *l){

  int y;

  //aux
  no *aux =malloc(sizeof(no));

  if(lista_vazia(l)==1){
   printf("Nao e possivel remover ----");
   printf("Lista Vazia!! \n");
   free(aux);
   return 0;

  }else{

     if(l->inicio == l->fim){ //só tenho um no na lista
        aux=l->inicio;
        y =aux->dado;
        l->fim = NULL;
        l->inicio = NULL;
        free(aux);
     }else{
       aux=l->inicio; //aponta para o inicio da lista
       y=aux->dado;   //guarda o valor
       l->inicio= aux->prox; // muda o ponteiro do inicio

       aux->prox =NULL; //desconecta o ponteiro  do proximo
       aux->ant = NULL; //desconecta o ponteiro do anterior

       l->inicio->ant = l->fim;
       l->fim->prox = l->inicio;

       free(aux);

     }
  }
  return y;
}

void mostra_lista(lista *l){

  no *aux=malloc(sizeof(no));
  aux=l->inicio;

  if (lista_vazia(l)){
   printf("lista vazia!!!");

  }else{

    do{
        printf("| %d",aux->dado);
        aux=aux->prox;

    }while(aux!=l->inicio);


  }

}




/* Função recursiva que exibe os valores contidos na lista*/
void imprime_recursiva(no* aux) {

   if (aux!=NULL) {
       printf("| %d\n",aux->dado); /* imprime primeiro elemento */
       imprime_recursiva(aux->prox); /* imprime sub-lista */
   }
}




int remove_fim_lista(lista *l){

  no *aux=(no*)malloc(sizeof(no));     //ponteiro auxiliar
  int y;


     if(lista_vazia(l)==1){
       printf("Nao e possivel remover ----");
       printf("Lista Vazia!! \n");
       free(aux);
       return 0;

     }else if(l->inicio == l->fim){//se so tem um unico nó

        aux=l->fim;  //aponta para o nó final
        y =aux->dado; //passa o valor da struc para a variável
        l->fim=NULL;
        l->inicio=NULL;
        free(aux);
        return y;

     }else{

        aux = l->fim;
        y=aux->dado;

        l->fim = aux->ant;          //passa o final para o anterior
        aux->prox = NULL;
        aux->ant =NULL;


        l->fim->prox =l->inicio;       //desconect ao final
        l->inicio->ant = l->fim;
        free(aux);             //free último elemento
        return y;
     }

}


int conta_no(lista *l){
 no* aux = l->inicio;
 int cont= 0;

 do{
     cont++;
     aux=aux->prox; //incrementa o ponteiro
 }while(aux!=l->inicio);


  return cont;
}



int conta_no_maiores(lista *l,int n){
 no* aux = l->inicio;
 int cont= 0;

 do{
    if(aux->dado > n){
      cont++;
    }
     aux=aux->prox; //incrementa o ponteiro

 }while(aux!=l->inicio);



  return cont;
}


//corrija o código
int verifica_repetido(lista *l,int n){
 no* aux = l->inicio;
 int flag=0;

  while(aux!=NULL){
    if(aux->dado == n){
      flag = 1;
    }
     aux=aux->prox; //incrementa o ponteiro
   }



  return flag;

}




