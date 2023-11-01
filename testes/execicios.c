#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct no
{
    int Vlr;
    struct no *ant;
} no;

typedef struct lista
{
    no *inicio;
} lista;

void criandoLista(lista *l)
{
    l->inicio = NULL;
}

int verificaLista(lista *l)
{
    if (l->inicio == NULL)
    {
        return 0; // lista vazia
    }
    else
    {
        return 1; // lista com >1 elementos
    }
}

int adicionaLista(lista *l, int vlr)
{
    no *novo = malloc(sizeof(no));

    novo->ant = NULL;
    novo->Vlr = vlr;

    if (verificaLista(l) == 1)
    {
        l->inicio = novo;
        return 0;
    }
    else
    {
        return 1;
    }
}

int removeLista(lista *l)
{
    int retorno;
    no *aux = malloc(sizeof(no));

    aux->ant = NULL;

    if (verificaLista(l) == 1)
    {
        retorno = l->inicio->Vlr;
        aux = l->inicio;
        l->inicio = l->inicio->ant;
        aux = NULL;
        free(aux);
    }
    else
    {
        printf("\nLista vazia..\n");
    }
    return retorno;
}

void mostrarLista(lista *l)
{
    if (verificaLista(l) != 1)
    {
        no *aux = malloc(sizeof(no));
        aux = l->inicio;

        printf("Lista");
        while (aux != NULL)
        {
            printf(" %d", aux->Vlr);
            aux = aux->ant;
        }
    }
    else
    {
        printf("lista vazia!");
    }
}

int main()
{
    setlocale(LC_ALL, "portugues_Brazil");
    int valor;
    int op;

    lista *l1;
    criandoLista(l1);

    do
    {
        system("cls");
        mostrarLista(l1);

        printf("\n==========MENU==========\n");
        printf("0_Sair\n");
        printf("1_Adicionar um valor\n");
        printf("2_Remover um valor\n");

        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\nQual o valor deseja adicionar?\n");
            scanf("%d", &valor);
            mostrarLista(&l1);

            break;
        case 2:
            removeLista(l1);
            break;

        default:
            break;
        }
    } while (op != 0);

    return 0;
}
