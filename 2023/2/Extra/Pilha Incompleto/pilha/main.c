#include <stdio.h>
#include <stdlib.h>

typedef struct Tpilha
{
  int valor;
  struct Tpilha *ant;
  //...
} Tpilha;

typedef struct pilha
{
  Tpilha *topo;
} pilha;

void criate_pilha(pilha *p) // generica pra todas as pilhas do cod
{
  p->topo = NULL;
}

int pilha_vazia(pilha *p) // verifica se a pila esta vazia
{
  if (p->topo == NULL)
  {
    return 0; // Pilha vazia
  }
  else
  {
    return 1; // pilha com pelo menos 1 elemento
  }
}

void empilhar(pilha *p, int valor) // Empilhando
{
  Tpilha *novo = malloc(sizeof(Tpilha));

  novo->valor = valor; // Reorganizando ponteiros
  novo->ant = p->topo;
  p->topo = novo;

  novo = NULL;
  free(novo);
}

void desempilha(pilha *p)
{
  int x;
  Tpilha *aux = p->topo;
  p->topo = aux->ant;
  
  aux->ant = NULL;
  x= aux -> valor; //seguranca

  free(aux);
  return x;
}

void menu()
{

  pilha *p1 = malloc(sizeof(pilha));
  criate_pilha(p1);

  pilha *p2 = malloc(sizeof(pilha));
  criate_pilha(p2);

  int op; // opção recursiva

  do
  {
    system("cls");
    printf("\n Pilha: \n");

    printf("\n\n");
    printf("1 - Empilhar \n");
    printf("2 - Desempilhar \n");
    printf("3 - Sair \n ");

    printf("\n\n Informe a opcao :>_");
    scanf("%d", &op);

    switch (op)
    {

    case 1:
    {
      int x;
      printf("Digite um valor para empilhar: ");
      scanf("%d", &x);
      empilhar(p1, x); // empilha (2a, 10)
      break;
    }

    case 2:
    {
      if (pilha_vazia(p1) == 0)
      {
        printf("pilha vazia, nao e possivel desempilhar!");
      }
      else
      {
        desempilha(p1);
      }

      break;
    }

    case 3:
      op = 3;
    }

  } while (op != 3);
}

int main()
{

  menu();
  printf("\n");
  return 0;
}

//
//
// pilha* createpilha(pilha *p){
//    p->topo=NULL;
//    return p;
//}
//
//
// int pilha_vazia(pilha *p){
// if(p->topo == NULL){
//       return 1;
// }else{
//  return 0;
// }
//}
//
//
//

//
// int desempilha(pilha *p){
//
//  int elemento;
//
//  Tpilha *aux=(Tpilha*)malloc(sizeof(Tpilha));
//  aux= p->topo; //cria auxiliar e aponta para o topo
//
//  p->topo= aux->ant; //baixa o topo
//  elemento = aux->item;
//  aux->ant = NULL;
//  free(aux);
//  return elemento;
//
//}
//
//
// void mostra_pilha(pilha *p){
//
//  if(pilha_vazia(p)==1){
//     printf("pilha vazia!!!");
//  }else{
//
//      Tpilha *aux=(Tpilha*)malloc(sizeof(Tpilha));
//      aux= p->topo; //cria auxiliar e aponta para o topo
//
//      while(aux!=NULL){
//        printf("%d \n",aux->item);
//        aux=aux->ant;
//      }
//  }
//
//}
