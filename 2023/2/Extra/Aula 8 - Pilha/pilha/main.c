#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void menu(){

  //pilhas
  pilha *p1=malloc(sizeof(pilha));
  create_pilha(p1);





 int op;  //opcao recursiva

  do{
         system("cls");
         printf("\n Pilha: \n");
         mostrar(p1);

          printf("\n\n");
          printf("1 - Empilhar \n");
          printf("2 - Desempilhar \n");
          printf("3 - Sair \n ");

          printf("\n\n Informe a opcao :>_");
          scanf("%d",&op);

        switch(op){

         case 1:{ //empilhar

            int valor;
            printf("\n Informe um valor\n");
            scanf("%d",&valor);

          //empilha(2a,30)
            empilha(p1,valor);


            break;
         }

         case 2:{//desempilhando

           if(pilha_vazia(p1)==1){
              printf("pilha vazia\n");
              printf("nao e possivel remover \n");
              getch();

            }else{
               desempilha(p1);
            }

            break;
         }



        case 3:
          op=3;
        }

  }while(op != 3);
}


int main()
{

    menu();






    printf("\n\n");
    return 0;
}





