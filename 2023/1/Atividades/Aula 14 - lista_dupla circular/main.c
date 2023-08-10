#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

void menu(){
 lista *l=(lista*)malloc(sizeof(lista));
 create_lista(l);

 int op;  //opção recursiva

 do{
     system("cls");
     printf("\n lista: ");

     mostra_lista(l);
     printf("\n\n");
     printf("1 - Inserir inicio lista \n");
     printf("2 - Inserir fim lista \n");
     printf("3 - Remover inicio Lista \n");
     printf("4 - Remover fim Lista \n");
     printf("5 - Imprime recursiva \n");
     printf("6 - Contar no \n");
     printf("7 - Contar no maior que n \n");
     printf("8 - verifica repetido n \n");
     printf("9 - Sair \n");

     printf("\n\n Informe a opcao :>_");
     scanf("%d",&op);

    switch(op){

     case 1:{
      int x;

      printf("Informe o valor: ");
      scanf("%d",&x);

//          if(verifica_repetido(l,x)==1){
//            printf("valor ja se encontra na lista");
//            getch();
//          }else{
            inserir_ini_lista(l,x);
          //}


      break;
     }


     case 2:{
          int x;
          printf("Informe o valor: ");
          scanf("%d",&x);

//          if(verifica_repetido(l,x)==1){
//            printf("valor ja se encontra na lista");
//            getch();
//          }else{
            inserir_fim_lista(l,x);
        //  }


          break;
     }

     case 3:{
            remove_ini_lista(l);
             break;

        }

       case 4:{
            remove_fim_lista(l);
            break;
       }

       case 5:{
          //  imprime_recursiva(l->inicio);
            //mostra_lista(l);
            //getch();
            break;
       }

       case 6:{
           int x;
           x=conta_no(l);
           printf("numero de nos: %d ",x);
           getch();
           break;
       }


        case 7:{
           int x,n;

           printf("Informe o valor: ");
           scanf("%d",&n);

           x=conta_no_maiores(l,n);

           printf("numero de nos maior que:%d = %d",n,x);
           getch();
           break;
       }


         case 8:{
           int x,n;

           printf("Informe o valor: ");
           scanf("%d",&n);

           x=verifica_repetido(l,n);

          // printf("numero de nos maior que:%d = %d",n,x);
           getch();
           break;
       }




        case 9:
         op= 9;
 }

 }while(op != 9);
}


int main()
{

    menu();
    printf("\n\n");
    return 0;
}
