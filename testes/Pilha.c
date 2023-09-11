#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no
{
    int Vlr;
    struct no *ant;
} no;

typedef struct Pilha
{
    no *topo
} pilha;

void inicializar(pilha *p)
{
    p->topo = NULL;
}

int verificar(pilha *p)
{
    if (p->topo == NULL)
    {
        printf("A pilha está vazia");
        return 0;
    }
    else
    {
        return 1;
    }
}

void empilhar(pilha *p, int vlr)
{
    no *novo = malloc(sizeof(no));

    if (novo)
    {
        novo->Vlr = vlr;
        novo->ant = p->topo;
        p->topo = novo;

        novo=NULL;
        free(novo);
    }
    else
    {
        printf("Alocação dinâmica falhou!");
    }
}

int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");
    int op;

    pilha *p1 = malloc(sizeof(pilha));

    do
    {
        printf("\n 1_Empilhar");
        printf("\n 2_Desempilhar");
        printf("\n 3_Mostrar a pilha");
        printf("\n 0_Sair");
        printf("\n\n");
        fflush(stdin);
        scanf("%d", &op);

        system("cls");

        switch (op)
        {
        case 0:
            printf("Saindo\n");
            break;
        case 1:
            printf("Empilhando:\n");

            int vlr;
            printf("digite um valor a ser empilhado: \n");
            scanf("%d", &vlr);
            empilhar(p1, vlr);

            break;
        case 2:
            printf("Desempilhando:\n");

            // cod

            break;
        case 3:
            printf("Mostrando:\n");

            // cod

            break;

        default:
            printf("Opção inválida\nTente novamente\n");
            break;
        }

    } while (op != 0);
}