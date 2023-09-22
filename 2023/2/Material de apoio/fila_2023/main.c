#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "pilha.h"

void menu(){

  fila  *f1 =(fila*)malloc(sizeof(fila));
  create_fila(f1);

  pilha *p1 =(pilha*)malloc(sizeof(pilha));
  createpilha(p1);


 int op;  //opção recursiva

 do{
     system("cls");
     printf("\n Fila: \n");
     mostra_fila(f1);

     printf("\n Pilha: \n");
     mostra_pilha(p1);


     printf("\n\n");
     printf("1 - Enfileirar \n");
     printf("2 - Desenfileirar \n");
     printf("3 - Fila pilha    \n");
     printf("4 - Sair \n ");

     printf("\n\n Informe a opcao :>_");
     scanf("%d",&op);

    switch(op){

      case 1:{
         int x;
         printf("Informe o valor :");
         scanf("%d",&x);
         f1=insere_fila(f1,x);
         break;
     }


     case 2:{
          int x;
          if(fila_vazia(f1)==1){
            printf("\n nao e possivel remover ");
            printf(" ------>fila vazia!! \n");
          }else{
              x=remove_fila(f1);
              empilha(p1,x);
          }
          break;

      }

      case 3:{ //fila pilha
          int x;
          if(fila_vazia(f1)==1){
            printf("\n nao e possivel remover ");
            printf(" ------>fila vazia!! \n");
          }else{

             fila_pilha(f1,p1);
          }
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
