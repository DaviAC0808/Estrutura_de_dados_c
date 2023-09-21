#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// #include "ex_pilha.h"

typedef struct no
{
    int Vlr;
    struct no *ant;
} no;

typedef struct pilha
{
    no *topo;
} pilha;

void criar(pilha *p)
{
    p->topo = NULL;
}

int verificar(pilha *p)
{
    if (p->topo == NULL)
    {
        return 1; // pilha vazia
    }
    else
    {
        return 0;
    }
}

void empilhar(pilha *p, int vlr)
{
    no *novo = malloc(sizeof(no));

    novo->Vlr = vlr;
    novo->ant = p->topo;
    p->topo = novo;

    novo = NULL;
    free(novo);
}

int desempilhar(pilha *p)
{
    int x;
    no *aux;
    x = p->topo->Vlr;
    aux = p->topo;
    p->topo = aux->ant;
    aux->ant = NULL;
    free(aux);
    return x;
}

/*
    1_Desenvolva uma função para inverter a posição dos elementos de uma
    pilha P.
*/

void inverter(pilha *pa, pilha *pb)
{
    int vlr;
    no *aux = malloc(sizeof(no));
    aux->ant = NULL;

    if (verificar(pa) == 0)
    {
        // pilha cheia
        vlr = desempilhar(pa);
        empilhar(pb, vlr);
    }
    else
    {
        pb->topo = NULL;
    }
    aux = NULL;
    free(aux);
}

/*
    2_Desenvolva uma função para testar se uma pilha P1 tem mais elementos
    que uma pilha P2.
*/

int testar_quantidade()
{
}

/*
    3_Desenvolva uma função para testar se duas pilhas P1 e P2 são iguais.
*/

int testar_igualdade(pilha *pa, pilha *pb)
{
    no *aux = malloc(sizeof(no));

    do
    {
        aux->Vlr = pb->topo->Vlr;
        if (aux->Vlr == pa->topo->Vlr){
            aux = pb->topo->ant;
        }
        else
        {
            printf("As pilhas não são iguais!");
        }
    } while (aux == NULL);
    free(aux);
}

void mostrar(pilha *p)
{
    if (verificar(p) == 0)
    {

        no *aux;
        aux = p->topo;

        while (aux != NULL)
        {
            printf("\n %d", aux->Vlr);
            aux = aux->ant;
        }
    }
    else
    {
        printf("Pilha Vazia !!!\n");
    }
}

void menu()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    // pilhas
    pilha *p1 = malloc(sizeof(pilha));
    criar(p1);

    pilha *p2 = malloc(sizeof(pilha));
    criar(p2);

    int op, x; // opcao recursiva

    do
    {
        system("cls");
        printf("\n Pilha: \n");
        mostrar(p1);
        printf("\n");
        printf("0 - Sair \n");
        printf("1 - Empilhar \n");
        printf("2 - Desempilhar \n");
        printf("3 - Questão 1 \n");
        printf("4 - Questão 2 \n");
        printf("5 - Questão 3 \n");

        printf("\n\n Informe a opcao :>_");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            op = 0;
            break;

        case 1:
        { // empilhar

            int valor;
            printf("\n Informe um valor\n");
            scanf("%d", &valor);

            // empilha(2a,30)
            empilhar(p1, valor);
            break;
        }

        case 2:
        { // desempilhando

            if (verificar(p1) == 1)
            {
                printf("pilha vazia\n");
                printf("nao e possivel remover \n");
                getchar();
            }
            else
            {
                x = desempilhar(p1);
                printf("\nDesempilhando o valor %d?\n", x);
                system("pause");
            }
            break;
        }
        case 3:
        {
            inverter(p1, p2);
            printf("\nDesempilhando p1\n");
            mostrar(p1);
            printf("\nEmpilhando p1 em p2\n");
            mostrar(p2);
            printf("\n\n");
            system("pause");
        }
        case 4:
        {
        }
        case 5:
        {
            testar_igualdade(p1, p2);
        }
        }

    } while (op != 0);
}

int main()
{

    menu();

    printf("\n\n");
    return 0;
}
