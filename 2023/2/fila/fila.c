#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no
{
    int Vlr;
    struct no *prox;
} no;

typedef struct fila
{
    no *inicio;
    no *fim;
} fila;

void criar(fila *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

int verificar(fila *f)
{
    if (f->inicio == NULL)
    {
        return 1; // fila vazia
    }
    else
    {
        return 0;
    }
}

void *insere(fila *f, int vlr)
{
    no *novo = malloc(sizeof(no));
    novo->Vlr = vlr;
    novo->prox = NULL;

    if (verificar(f) == 1)
    { // inserindo 1º elemento
        f->inicio = novo;
        f->fim = novo;
    }
    else
    {
        f->fim->prox = novo;
        f->fim = novo;
    }
    novo = NULL;
    free(novo);
}

int remover(fila *f)
{
    int x;
    no *aux = malloc(sizeof(no));

    aux = f->inicio;
    f->inicio = aux->prox; // ou f->inicio = f->inicio->prox
    aux->prox = NULL;

    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }

    x = aux->Vlr;
    free(aux);
    return x;
}

void mostrar(fila *f)
{
    no *aux = malloc(sizeof(no));
    aux = f->inicio;

    while (aux != NULL)
    {
        printf("| %d", aux->Vlr);
        aux = aux->prox;
    }
}

int main()
{
    fila *f1 = malloc(sizeof(no));
    criar(f1);

    setlocale(LC_ALL, "Portuguese_Brazil");
    int ins, op;

    do
    {
        system("cls");
        mostrar(f1);
        printf("\n========= Enfileirando Valores =========\n");
        printf("\n0_ Sair");
        printf("\n1_ Empilhar");
        printf("\n2_ Desempillhar");
        printf("\n\n");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf("Saindo...");
            break;
        case 1:
            printf("Digite o valor a ser empilhado: ");
            scanf("%d", &ins);

            insere(f1, ins);

            break;
        case 2:
            if (verificar(f1) == 1)
            {
                printf("\nLista Vazia!\n");
                system("pause");
            }
            else
            {
                remover(f1);
            }
            break;
        default:
            printf("\nDigite um valor válido!\n");
            system("pause");
            break;
        }

    } while (op != 0);

    printf("\n\n");
}