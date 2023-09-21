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
        printf("\nA pilha está vazia!\n");
        return 1;
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

        printf("\n\n");
        printf("0 - Sair \n");
        printf("1 - Empilhar \n");
        printf("2 - Desempilhar \n");

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
                printf("\nDeseja desempilhar o valor %d?\n", x);
                system("pause");
            }

            break;
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
