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
    3_Desenvolva uma função para testar se duas pilhas P1 e P2 são iguais.
*/

int testar_quantidade(pilha *pa, pilha *pb)
{
    int x = 0;
    int y = 0;
    no *aux1 = malloc(sizeof(no));
    no *aux2 = malloc(sizeof(no));

    aux1 = pa->topo;
    aux2 = pb->topo;

    while (aux1 != NULL)
    {
        aux1 = aux1->ant;
        x = x + 1;
    }
    while (aux2 != NULL)
    {
        aux2 = aux2->ant;
        y = y + 1;
    }

    if (x == y)
    {
        return 0; // pilhas iguais
    }
    else
    {
        return 1; // pilhas diferentes
    }
}

int testar_igualdade(pilha *pa, pilha *pb)
{
    no *aux1 = pa->topo;
    no *aux2 = pb->topo;

    while (aux1 != NULL && aux2 != NULL)
    {
        if (aux1->Vlr != aux2->Vlr)
        {
            return 0; // Pilhas não são iguais
        }

        aux1 = aux1->ant;
        aux2 = aux2->ant;
    }

    // As pilhas são iguais apenas se ambas forem vazias no final do loop
    if (aux1 == NULL && aux2 == NULL)
    {
        return 1; // Pilhas são iguais
    }
    else
    {
        return 0; // Pilhas não são iguais
    }
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

int menu()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Pilhas
    pilha *p1 = malloc(sizeof(pilha));
    criar(p1);

    pilha *p2 = malloc(sizeof(pilha));
    criar(p2);

    int op;         // Opção do menu
    int resultado;  // Resultado do teste de igualdade
    int valor1;     // p1
    int valor2;     // p2
    int quantidade; // Resultado do teste de quantidade
    int vlrdes1;     //valor desempilhado
    int vlrdes2;     //valor desempilhado

    do
    {
        system("cls");
        printf("\n Pilha 1: \n");
        mostrar(p1);
        printf("\n Pilha 2: \n");
        mostrar(p2);

        printf("\n\n");
        printf("0 - Sair \n");
        printf("1 - Empilhar em P1 \n");
        printf("2 - Empilhar em P2 \n");
        printf("3 - Desempilhar em P1 \n");
        printf("4 - Desempilhar em P2 \n");
        printf("5 - Testar quantidade entre P1 e P2 \n");
        printf("6 - Testar igualdade entre P1 e P2 \n");

        printf("\n\n Informe a opção :>_");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            op = 0;
            break;

        case 1: // Empilhar em p1

            printf("\n Informe um valor para P1: ");
            scanf("%d", &valor1);
            empilhar(p1, valor1);
            break;

        case 2: // Empilhar em p2

            printf("\n Informe um valor para P2: ");
            scanf("%d", &valor2);
            empilhar(p2, valor2);
            break;

        case 3:
            vlrdes1 = desempilhar(p1);
            printf("Valor desempilhado: %d\n", vlrdes1);
            system("pause");
            break;

        case 4:
            vlrdes2 = desempilhar(p2);
            printf("Valor desempilhado: %d\n", vlrdes2);
            system("pause");
            break;

        case 5:

            printf("Teste de quantidade");
            quantidade = testar_quantidade(p1, p2);
            if (quantidade!=0)
            {
                printf("\nA quantidade de numeros não é a mesma!\n");
            }
            else
            {
                printf("\nA quantidade de números é a mesma!\n");
            }

        case 6: // Testar igualdade entre p1 e p2

            resultado = testar_igualdade(p1, p2);
            if (resultado)
            {
                printf("\n As pilhas P1 e P2 são iguais.\n");
            }
            else
            {
                printf("\n As pilhas P1 e P2 não são iguais.\n");
            }
            system("pause");
            break;
        }
    } while (op != 0);

    // Libere a memória alocada para as pilhas antes de sair
    free(p1);
    free(p2);

    printf("\n\n");
    return 0;
}

int main()
{

    menu();

    printf("\n\n");
    return 0;
}
