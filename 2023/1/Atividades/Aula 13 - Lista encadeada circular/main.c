#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *prox; //simples
}no;

typedef struct lista{
 no *inicio;
 no *fim;
}lista;


void inicializa_lista(lista *l){
 l->inicio=NULL;
 l->fim=NULL;
}


int lista_vazia(lista *l){

  if(l->inicio==NULL){
    return 1;
  }else {
   return 0;
  }

}

void inserir_fim_lista(lista *l,int valor){

  //cria um novo no
  no *novo=malloc(sizeof(no));
  novo->dado =valor;
  novo->prox=NULL;

  if(lista_vazia(l)){ //primeira vez
    l->inicio=novo;
  }else{
    l->fim->prox = novo;
  }

    l->fim=novo; //ajusta-se o ponteiro
    novo->prox = l->inicio; //aponta para o inicio da lista

    novo=NULL;
    free(novo);


}



void consultar(lista *l,int valor){

  no *aux=malloc(sizeof(no));     //ponteiro auxiliar
  int achou =0;//flag //marcador

    if(lista_vazia(l)){
        printf("Lista Vazia!!!\n");
    }else{

      aux=l->inicio;

      do{
        if(aux->dado==valor){
            printf("Valor encontrado %d \n", aux->dado);
            achou = 1;
        }else{
           aux=aux->prox;
        }

      }while(aux != l->inicio && achou == 0);


      if(achou == 0){
       printf("Valor nao encontrado!!!!");
      }
    }
}



int remove_elemento(lista *l, int valor){
  int x;

  no *aux=malloc(sizeof(no));     //ponteiro auxiliar
  no *ant=malloc(sizeof(no));     //ponteiro auxiliar

  if(lista_vazia(l)){
     printf("Lista Vazia!!!");
  }else{

   aux= l->inicio;
   ant= l->inicio;

    do{
       if(aux->dado == valor){ //achou o valor

              if(l->inicio ==l->fim){//se tenho 1 elemento

                l->inicio=NULL;
                l->fim = NULL;
                x=aux->dado;
                aux=NULL;
                free(aux);
                free(ant);
                return x;

              }else if(aux==l->inicio){ //se o elemento está no inicio da lista
                 l->inicio = aux->prox;

                 //l->fim->prox= aux->prox;
                 l->fim->prox= l->inicio;
                 x=aux->dado;
                 aux->prox = NULL;
                 free(aux);
                 free(ant);
                 return x;

              }else{ //caso não seja o primeiro elemento da lista

                 ant->prox= aux->prox;
                 x = aux->dado;
                 aux->prox = NULL;

                 if(aux == l->fim){
                    l->fim = ant;
                 }
                 free(aux);
                 ant = NULL;
                 free(ant);
                 return x;
              }

      }else{
         ant=aux;
         aux=aux->prox;
      }

    }while(aux != l->inicio);
  }
}


void mostra_lista(lista *l)
{

    if(lista_vazia(l)){

        printf("Lista Vazia!!!\n");


    }else{

       no *aux=malloc(sizeof(no));
       aux =l->inicio;


        do{
            printf(" | %d ", aux->dado);
            aux = aux->prox; //incrementa o ponteiro
        }while(aux != l->inicio);


    }
}


void menu(){
 lista *l=(lista*)malloc(sizeof(lista));
 inicializa_lista(l);

 int op;  //opção recursiva

 do{
     system("cls");
     printf("\n lista: ");
     mostra_lista(l);
     printf("\n\n");
     printf("1 - Inserir elemento lista \n");
     printf("2 - Buscar  elemento lista \n");
     printf("3 - Remover elemento lista \n");
     printf("4 - Sair \n");

     printf("\n\n Informe a opcao :>_");
     scanf("%d",&op);

    switch(op){

     case 1:{
      int x;

      printf("Informe o valor: ");
      scanf("%d",&x);
      inserir_fim_lista(l,x);
      break;
     }


     case 2:{
          int x;
          printf("Informe o valor que deseja buscar: ");
          scanf("%d",&x);
          consultar(l,x);
          printf("\n pressione uma tecla!!!");
          getch();
          break;
     }

     case 3:{
          int x;
          printf("Informe o valor que deseja buscar: ");
          scanf("%d",&x);
          remove_elemento(l,x);
          break;

      }

        case 4:
        op=4;
 }

 }while(op != 4);
}


int main()
{

    menu();
    printf("\n\n");
    return 0;
}
